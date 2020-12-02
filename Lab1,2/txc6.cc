/*
 * tx6.cc
 *
 *  Created on: Oct 18, 2020
 *      Author: USER
 */

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Txc6 : public cSimpleModule
{
  private:
    cMessage *event;
    cMessage *tictocMsg;

  public:
    Txc6();
    virtual ~Txc6();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Txc6);

Txc6::Txc6()
{
    event = tictocMsg = NULL;
}

Txc6::~Txc6()
{
    cancelAndDelete(event);
    delete tictocMsg;
}

void Txc6::initialize()
{
    event = new cMessage("event");

    tictocMsg = NULL;

    if (strcmp("tic", getName()) == 0)
    {
        EV << "Scheduling first send to t=5.0s\n";
        tictocMsg = new cMessage("tictocMsg");
        scheduleAt(5.0, event);
    }
}

void Txc6::handleMessage(cMessage *msg)
{
    if (msg==event)
       {
           EV << "Wait period is over, sending back message\n";
           send(tictocMsg, "out");
           tictocMsg = NULL;
       }
       else
       {
           EV << "Message arrived, starting to wait 1 sec...\n";
           tictocMsg = msg;
           scheduleAt(simTime()+1.0, event);
       }
}

