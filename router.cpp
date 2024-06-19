#include "router.h"

// 패킷을 받아 재전송한다.
void Router::onReceive(Packet* packet) {
    for(RoutingEntry r : routingTable_) {
      if(r.destination == packet->destAddress()) {
        std::cout << "Router # " << id() << ":" << "forwarding packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
        r.nextLink->sendPacket(this, packet);
        break;
      }
    }
}