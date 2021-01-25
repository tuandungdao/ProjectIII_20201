/*
 * Computer.cc
 *
 *  Created on: Jan 21, 2021
 *      Author: USER
 */

#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Computer : public cSimpleModule
{
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Computer);

void Computer::initialize()
{
    if (strcmp("computer_tic", getName()) == 0)
    {
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Computer::handleMessage(cMessage *msg)
{
    send(msg, "out");
}


