#include "loadbalancer.h"

LoadBalancer::LoadBalancer() { this->time = 0; }

int LoadBalancer::getQueueSize() { return this->requestqueue.size(); }

int LoadBalancer::getTime() { return this->time; }

bool LoadBalancer::isQueueEmpty() { return this->requestqueue.empty(); }

void LoadBalancer::incrementTime() { this->time++; }

Request* LoadBalancer::popNextRequest() {
    if (this->isQueueEmpty()) {
        return nullptr;
    }

    Request* next_request = this->requestqueue.front();
    this->requestqueue.pop();

    return next_request;
}

void LoadBalancer::pushNewRequest(Request* request) { this->requestqueue.push(request); }
