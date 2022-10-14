#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "request.h"
#include "webserver.h"

#include <queue>

/**
 * @brief Implementation of a load balancer that will keep track of time and requests.
*/
class LoadBalancer {
    public:
        LoadBalancer();
        int getQueueSize();
        int getTime();
        bool isQueueEmpty();
        void incrementTime();
        Request* popNextRequest();
        void pushNewRequest(Request* request);
    private:
        /**
         * @brief Queue that will hold pointers to requests.
        */
        std::queue<Request*> requestqueue;
        /**
         * @brief The time/clock cycles the load balancer has been running for.
        */
        int time;
};

#endif
