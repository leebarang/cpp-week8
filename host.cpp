#include "host.h"

// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize() {
    services_.clear();
}

// 랜덤한 링크를 하나 반환한다.
Link* Host::getRandomLink() {
    srand(unsigned(time(NULL)));
    int randomNumber = rand()%int(myLink_.size());
    return myLink_[randomNumber];
}

// 패킷을 전달 받는다.
void Host::onReceive(Packet* packet) {
    Service *service = nullptr;
    for(Service *s: services_) {
      if(s->port() == packet->destPort()) {
        service = s;
        break;
      }
    }

    if(service != nullptr) {
      service->receivePacket(packet);
    }
}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet) {
    getRandomLink()->sendPacket(this, packet);
}