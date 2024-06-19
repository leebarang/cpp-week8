#include "service_installer.h"

// 서비스를 설치하는 역할
void ServiceInstaller::install(Host *host, Service *service) {
  host->services_.push_back(service);
}

// 사용 가능한 포트를 만들어 반환
short ServiceInstaller::assignSrcPort(Host *host) {
  short srcPort = 1000;
  bool unique = false;
  while (!unique) {
    unique = true;
    for (Service* s : host->services_) {
      if (s->port_ == srcPort) {
        srcPort++;
        unique = false;
        break;
      }
    }
  }
  return unique;
}