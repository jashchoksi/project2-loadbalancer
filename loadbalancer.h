#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "request.h"

#include <queue>

class LoadBalancer {
    public:
        LoadBalancer();
        int getTime();
        void pushNewRequest(Request request);
        Request popNextRequest();
        bool isQueueEmpty();
    private:
        std::queue<Request> requestqueue;
        int time;
};

#endif
