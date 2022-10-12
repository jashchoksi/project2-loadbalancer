#ifndef REQUEST_H
#define REQUEST_H

#include <cstdlib>
#include <string>

struct Request {
    std::string ip_in = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." +
                        std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);

    std::string ip_out = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." +
                         std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);

    int process_time;
};

#endif
