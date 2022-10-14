#include "loadbalancer.h"

/**
 * @brief LoadBalancer constructor.
 *
 * Constructs a load balancer and sets time to 0.
*/
LoadBalancer::LoadBalancer() { this->time = 0; }

/**
 * @brief Gets the size of the queue that contains the requests.
 *
 * @returns The number of requests in the queue
*/
int LoadBalancer::getQueueSize() { return this->requestqueue.size(); }

/**
 * @brief Gets the current time/clock cycle.
 *
 * @return The time/clock cycles the load balancer has been running for.
*/
int LoadBalancer::getTime() { return this->time; }

/**
 * @brief Checks if the request queue is empty.
 *
 * @returns True if there are no more requests in the queue, otherwise False.
*/
bool LoadBalancer::isQueueEmpty() { return this->requestqueue.empty(); }

/**
 * @brief Increments the time/clock cycles the load balancer has been running for.
*/
void LoadBalancer::incrementTime() { this->time++; }

/**
 * @brief Pops request from the front of the queue.
 *
 * Checks if the queue is empty and if it is not, removes the request at the front of the queue and returns it.
 *
 * @returns A pointer to the request that was popped from the front of the queue. If queue is empty, returns @a nullptr.
*/
Request* LoadBalancer::popNextRequest() {
    if (this->isQueueEmpty()) {
        return nullptr;
    }

    Request* next_request = this->requestqueue.front();
    this->requestqueue.pop();

    return next_request;
}

/**
 * @brief Pushes a request to the end of the queue.
 *
 * @param request a pointer to the request that will be added to the end of the queue
*/
void LoadBalancer::pushNewRequest(Request* request) { this->requestqueue.push(request); }
