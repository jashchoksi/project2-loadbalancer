#include "loadbalancer.h"

LoadBalancer::LoadBalancer(): time(0) {}

int LoadBalancer::getTime() { return this->time; }

bool LoadBalancer::isQueueEmpty() { return this->requestqueue.empty(); }

void LoadBalancer::incrementTime() { this->time += 1; }

Request LoadBalancer::popNextRequest() {
    Request next_request = this->requestqueue.front();
    this->requestqueue.pop();

    return next_request;
}

void LoadBalancer::pushNewRequest(Request request) { this->requestqueue.push(request); }
