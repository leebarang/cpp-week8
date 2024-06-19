#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <vector>
#include <iostream>

struct RoutingEntry {
public:
  Address destination;
  Link *nextLink;
};

class Router : public Node {
protected:
  std::vector<RoutingEntry> routingTable_;

  void onReceive(Packet* packet) override {
    for(RoutingEntry r : routingTable_) {
      if(r.destination == packet->destAddress()) {
        r.nextLink->sendPacket(this, packet);
        break;
      }
    }
  }
};

#endif