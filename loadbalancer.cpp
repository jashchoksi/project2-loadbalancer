#include "loadbalancer.h"

LoadBalancer::LoadBalancer(): time(0) {}

int LoadBalancer::getTime() { return this->time; }

void LoadBalancer::pushNewRequest(Request request) { this->requestqueue.push(request); }

Request LoadBalancer::popNextRequest() {
    Request next_request = this->requestqueue.front();
    this->requestqueue.pop();

    return next_request;
}

bool LoadBalancer::isQueueEmpty() { return this->requestqueue.empty(); }
