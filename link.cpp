#include "link.h"
#include "node.h"

void Link::sendPacket(Node* sender, Packet* packet){
    Node* receiver = other(sender);
    receiver->onReceive(packet);
}