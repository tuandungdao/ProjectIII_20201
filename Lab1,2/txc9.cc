/*
 * txc9.cc
 *
 *  Created on: Oct 19, 2020
 *      Author: USER
 */

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Tic9 : public cSimpleModule
{
  private:
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent;  // holds pointer to the timeout self-message
    int seq;  // message sequence number
    cMessage *message;  // message that has to be re-sent on timeout

  public:
    Tic9();
    virtual ~Tic9();

  protected:
    virtual cMessage *generateNewMessage();
    virtual void sendCopyOf(cMessage *msg);
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Tic9);

Tic9::Tic9()
{
    timeoutEvent = message = NULL;
}

Tic9::~Tic9()
{
    cancelAndDelete(timeoutEvent);
    delete message;
}

void Tic9::initialize()
{
    seq = 0;
    timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");

    EV << "Sending initial message\n";
    message = generateNewMessage();
    sendCopyOf(message);
    scheduleAt(simTime()+timeout, timeoutEvent);
}

void Tic9::handleMessage(cMessage *msg)
{
    if (msg==timeoutEvent)
    {
        EV << "Timeout expired, resending message and restarting timer\n";
        sendCopyOf(message);
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
    else // message arrived
    {
        EV << "Received: " << msg->getName() << "\n";
        delete msg;

        EV << "Timer cancelled.\n";
        cancelEvent(timeoutEvent);
        delete message;

        message = generateNewMessage();
        sendCopyOf(message);
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
}

cMessage *Tic9::generateNewMessage()
{
    char msgname[20];
    sprintf(msgname, "tic-%d", ++seq);
    cMessage *msg = new cMessage(msgname);
    return msg;
}

void Tic9::sendCopyOf(cMessage *msg)
{
    cMessage *copy = (cMessage *) msg->dup();
    send(copy, "out");
}

class Toc9 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Toc9);

void Toc9::handleMessage(cMessage *msg)
{
    if (uniform(0,1) < 0.1)
    {
        EV << "\"Losing\" message " << msg << endl;
        bubble("message lost");
        delete msg;
    }
    else
    {
        EV << msg << " received, sending back an acknowledgement.\n";
        delete msg;
        send(new cMessage("ack"), "out");
    }
}

