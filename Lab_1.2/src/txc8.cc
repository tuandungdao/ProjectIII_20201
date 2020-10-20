/*
 * txc8.cc
 *
 *  Created on: Oct 19, 2020
 *      Author: USER
 */

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Tic8 : public cSimpleModule
{
private:
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent;

  public:
    Tic8();
    virtual ~Tic8();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Tic8);

Tic8::Tic8()
{
    timeoutEvent = NULL;
}

Tic8::~Tic8()
{
    cancelAndDelete(timeoutEvent);
}

void Tic8::initialize()
{
    timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");

    EV << "Sending initial message\n";
    cMessage *msg = new cMessage("tictocMsg");
    send(msg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
}

void Tic8::handleMessage(cMessage *msg)
{
    if (msg==timeoutEvent)
    {
        EV << "Timeout expired, resending message and restarting timer\n";
        cMessage *newMsg = new cMessage("tictocMsg");
        send(newMsg, "out");
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
    else // message arrived
    {
        EV << "Timer cancelled.\n";
        cancelEvent(timeoutEvent);
        delete msg;

        // Ready to send another one.
        cMessage *newMsg = new cMessage("tictocMsg");
        send(newMsg, "out");
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
}

class Toc8 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg);
};


Define_Module(Toc8);

void Toc8::handleMessage(cMessage *msg)
{
    if (uniform(0,1) < 0.1)
    {
        EV << "\"Losing\" message.\n";
        bubble("message lost");
        delete msg;
    }
    else
    {
        EV << "Sending back same message as acknowledgement.\n";
        send(msg, "out");
    }
}

