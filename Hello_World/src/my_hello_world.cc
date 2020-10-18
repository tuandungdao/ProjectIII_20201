#include<omnetpp.h>

using namespace omnetpp;

class My_Node: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

Define_Module(My_Node);

void My_Node::initialize() {
    if(strcmp("Computer2", getName()) ==0)
    {
        cMessage *msg = new cMessage("Hi guys!");

        send(msg, "output_gate");
    }
}

void My_Node::handleMessage(cMessage *msg)
{
    send(msg, "output_gate");
}

