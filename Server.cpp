#include "Server.h"

Server::Server() : occupied(false), remTime(0) {
}

void Server::processRequest() {
    if(occupied) {
        remTime -= 1;
        if(remTime <= 0) {
            occupied = false;
        }
    }
}

bool Server::isOccupied() const {
    return occupied;
}

void Server::setRequestStruct(const RequestStruct& request) {
    occupied = true;
    remTime = request.processTime;
}


