#include <iostream>
#include "LoadBalancer.h"

int main() {
    int serverCount = 10;
    int time = 10000;
    int initialRequests = serverCount * 100;

    LoadBalancer loadbalancer(serverCount, time);
    loadbalancer.addRandomRequest(initialRequests);
    loadbalancer.process();
    loadbalancer.printLog();
    cout << "Completed\n";
    return 0;
}