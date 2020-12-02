/*
 * txc12.cc
 *
 *  Created on: Oct 30, 2020
 *      Author: USER
 */

#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Txc12 : public cSimpleModule
{
  protected:
    virtual void forwardMessage(cMessage *msg);
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Txc12);

void Txc12::initialize()
{
    if (getIndex()==0)
    {
        char msgname[20];
        sprintf(msgname, "tic-%d", getIndex());
        cMessage *msg = new cMessage(msgname);
        scheduleAt(0.0, msg);
    }
}

void Txc12::handleMessage(cMessage *msg)
{
    if (getIndex()==3)
    {
        EV << "Message " << msg << " arrived.\n";
        delete msg;
    }
    else
    {
        forwardMessage(msg);
    }
}

void Txc12::forwardMessage(cMessage *msg)
{
    int n = gateSize("gate");
    int k = intuniform(0,n-1);

    EV << "Forwarding message " << msg << " on gate[" << k << "]\n";
    send(msg, "gate$o", k);
}
