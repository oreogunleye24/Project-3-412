#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <queue>
#include <vector>
#include "RequestStruct.h"
#include "Server.h"


class LoadBalancer {
    private:
        vector<int> log;
        vector<Server> webservers;
        queue<RequestStruct> requestQ;
        int cycles;

    public:
       LoadBalancer(int serverCount, int cycles);
       void newRequest(const RequestStruct& requestStruct);
       void process();
       void addRandomRequest(int requestCount);
       void printLog();
};

#endif