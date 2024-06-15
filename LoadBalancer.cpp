#include "LoadBalancer.h"
#include <iostream>
#include <cstdlib>

LoadBalancer::LoadBalancer(int serverCount, int remCycles) : cycles(remCycles) {
    for(int i = 0; i < serverCount; i++) {
        webservers.push_back(Server());
    }
}

void LoadBalancer::newRequest(const RequestStruct& requestStruct) {
    requestQ.push(requestStruct);
}

void LoadBalancer::process() {
    log.push_back(requestQ.size());
    for(int i = 0; i < cycles; i++) {
        for(auto& server: webservers) {
            if(!server.isOccupied() && !requestQ.empty()) {
                server.setRequestStruct(requestQ.front());
                requestQ.pop();
            }
            server.processRequest();
        }
    }
    log.push_back(requestQ.size());
}

void LoadBalancer::addRandomRequest(int requestCount) {
    for(int i = 0; i < requestCount; i++) {
       std::string ipIn = "192.168.0." + std::to_string(rand() % 255);
       std::string ipOut = "192.168.1." + std::to_string(rand() % 255);
       int timeToProcess = rand() % 100;
       newRequest(RequestStruct(ipIn, ipOut, timeToProcess));
    }
}

void LoadBalancer::printLog() {
    cout << "Queue starting size: " << log[0] << endl;
    cout << "Queue ending size: " << log[1] << endl;
}