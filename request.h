#ifndef REQUEST_H
#define REQUEST_H

#include <cstdlib>
#include <string>

struct Request {

    Request(int run_time) {
        ip_in = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." +
                std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);

        ip_out = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." +
                 std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);

        process_time = rand() % run_time;
    }

    std::string ip_in;
    std::string ip_out;
    int process_time;
};

#endif
