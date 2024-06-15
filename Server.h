#ifndef SERVER_H
#define SERVER_H
#include "RequestStruct.h"

class Server {
    private:
        bool occupied;
        int remTime;
    public:
        Server();
        void processRequest();
        void setRequestStruct(const RequestStruct& request);
        bool isOccupied() const;
};

#endif