/*
 * Txc.cc
 *
 *  Created on: Nov 5, 2020
 *      Author: USER
 */

#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

// Include a generated file: the header file created from tictoc13.msg.
// It contains the definition of the TictocMsg10 class, derived from
// cMessage.
#include "tictoc_m.h"


class Txc : public cSimpleModule
{
  protected:
    virtual TicTocMsg *generateMessage();
    virtual void forwardMessage(TicTocMsg *msg);
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Txc);

void Txc::initialize()
{
    // Module 0 sends the first message
    if (getIndex()==0)
    {
        // Boot the process scheduling the initial message as a self-message.
        TicTocMsg *msg = generateMessage();
        scheduleAt(0.0, msg);
    }
}

void Txc::handleMessage(cMessage *msg)
{
    TicTocMsg *ttmsg = check_and_cast<TicTocMsg *>(msg);

    if (ttmsg->getDestination()==getIndex())
    {
        // Message arrived.
        EV << "Message " << ttmsg << " arrived after " << ttmsg->getHopCount() << " hops.\n";
        bubble("ARRIVED, starting new one!");
        delete ttmsg;

        // Generate another one.
        EV << "Generating another message: ";
        TicTocMsg *newmsg = generateMessage();
        EV << newmsg << endl;
        forwardMessage(newmsg);
    }
    else
    {
        // We need to forward the message.
        forwardMessage(ttmsg);
    }
}

TicTocMsg *Txc::generateMessage()
{
    // Produce source and destination addresses.
    int src = getIndex();   // our module index
    int n = 30;      // module vector size
    int dest = intuniform(0,n-2);
    if (dest>=src) dest++;

    char msgname[20];
    sprintf(msgname, "tic-%d-to-%d", src, dest);

    // Create message object and set source and destination field.
    TicTocMsg *msg = new TicTocMsg(msgname);
    msg->setSource(src);
    msg->setDestination(dest);
    return msg;
}

void Txc::forwardMessage(TicTocMsg *msg)
{
    // Increment hop count.
    msg->setHopCount(msg->getHopCount()+1);

    // Same routing as before: random gate.
    int n = gateSize("gate");
    int k = intuniform(0,n-1);

    EV << "Forwarding message " << msg << " on gate[" << k << "]\n";
    send(msg, "gate$o", k);
}

