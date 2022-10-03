#include "loadbalancer.h"
#include "webserver.h"

#include <iostream>
#include <time.h>

const int A_ASCII_VALUE = 65;

int main() {
    srand(time(0));

    int num_servers = 0;
    int run_time = 0;
    int requests_to_generate = 0;

    std::cout << "Enter number of servers: ";
    std::cin >> num_servers;

    std::cout << "Enter time to run the load balancer: ";
    std::cin >> run_time;

    std::vector<WebServer> webservers(num_servers, NULL);
    for (int i = 0; i < num_servers; i++) {
        char server_name = char(A_ASCII_VALUE + i);
        WebServer* webserver = new WebServer(server_name);
        webservers.at(i) = *webserver;
    }

    LoadBalancer* load_balancer = new LoadBalancer(webservers);

    requests_to_generate = num_servers * 2;

    for (int i = 0; i < requests_to_generate; i++) {
        Request* generated_request = new Request();
        load_balancer->pushNewRequest(*generated_request);
    }

    while (!load_balancer->isQueueEmpty()) {
        load_balancer->incrementTime();
        Request popped_request = load_balancer->popNextRequest();
    }

    return 0;
}
