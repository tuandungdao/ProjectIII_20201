/*
 * txc2.cc
 *
 *  Created on: Oct 18, 2020
 *      Author: USER
 */

#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Txc2 : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Txc2);

void Txc2::initialize()
{
    if (strcmp("tic", getName()) == 0)
    {
        EV << "Sending initial message\n";
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Txc2::handleMessage(cMessage *msg)
{
    EV << "Received message `" << msg->getName() << "', sending it out again\n";
    send(msg, "out");
}


