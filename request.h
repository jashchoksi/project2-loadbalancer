#ifndef REQUEST_H
#define REQUEST_H

#include <cstdlib>
#include <string>

/**
 * @brief Provides the implementation for the requests handled by the load balancer.
 *
 * A request consists of a source IP address, a destination IP address, and the time it takes to process it.
*/
struct Request {
    /**
     * @brief The source IP address of the request.
     *
     * The octets of the IP address are intialized with random values.
    */
    std::string ip_in = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." +
                        std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);

    /**
     * @brief The destination IP address of the request.
     *
     * The octets of the IP address are intialized with random values.
    */
    std::string ip_out = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." +
                         std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);

    /**
     * @brief The time it takes to process the request.
    */
    int process_time;
};

#endif
