/*
 * txc17.cc
 *
 *  Created on: Nov 6, 2020
 *      Author: USER
 */

#include <string.h>
#include <omnetpp.h>
#include "tictoc17_m.h"

using namespace omnetpp;

class Txc17 : public cSimpleModule
{
private:
    simsignal_t arrivalSignal;

protected:
    virtual TicTocMsg17 *generateMessage();
    virtual void forwardMessage(TicTocMsg17 *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Txc17);

void Txc17::initialize()
{
    arrivalSignal = registerSignal("arrival");
    if (getIndex() == 0) {
        TicTocMsg17 *msg = generateMessage();
        scheduleAt(0.0, msg);
    }
}

void Txc17::handleMessage(cMessage *msg)
{
    TicTocMsg17 *ttmsg = check_and_cast<TicTocMsg17 *>(msg);

    if (ttmsg->getDestination() == getIndex()) {
        int hopcount = ttmsg->getHopCount();
        emit(arrivalSignal, hopcount);

        if (hasGUI()) {
            char label[50];
            sprintf(label, "last hopCount = %d", hopcount);
            cCanvas *canvas = getParentModule()->getCanvas();
            cTextFigure *textFigure = check_and_cast<cTextFigure*>(canvas->getFigure("lasthopcount"));
            textFigure->setText(label);
        }

        EV << "Message " << ttmsg << " arrived after " << hopcount << " hops.\n";
        bubble("ARRIVED, starting new one!");

        delete ttmsg;

        EV << "Generating another message: ";
        TicTocMsg17 *newmsg = generateMessage();
        EV << newmsg << endl;
        forwardMessage(newmsg);
    }
    else {
        forwardMessage(ttmsg);
    }
}

TicTocMsg17 *Txc17::generateMessage()
{
    int src = getIndex();
    int n = getVectorSize();
    int dest = intuniform(0, n-2);
    if (dest >= src)
        dest++;

    char msgname[20];
    sprintf(msgname, "tic-%d-to-%d", src, dest);

    TicTocMsg17 *msg = new TicTocMsg17(msgname);
    msg->setSource(src);
    msg->setDestination(dest);
    return msg;
}

void Txc17::forwardMessage(TicTocMsg17 *msg)
{
    msg->setHopCount(msg->getHopCount()+1);

    int n = gateSize("gate");
    int k = intuniform(0, n-1);

    EV << "Forwarding message " << msg << " on gate[" << k << "]\n";
    send(msg, "gate$o", k);
}



