#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "request.h"
#include "webserver.h"

#include <queue>
#include <vector>

class LoadBalancer {
    public:
        LoadBalancer();
        int getTime();
        bool isQueueEmpty();
        void incrementTime();
        Request* popNextRequest();
        void pushNewRequest(Request* request);
    private:
        std::queue<Request*> requestqueue;
        int time;
};

#endif
