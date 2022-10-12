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

    LoadBalancer* load_balancer = new LoadBalancer(); // create loadbalancer

    requests_to_generate = num_servers * 2;

    // generate random requests and add them to loadbalancer request queue
    for (int i = 0; i < requests_to_generate; i++) {
        Request* generated_request = new Request();
        load_balancer->pushNewRequest(*generated_request);
    }

    std::vector<WebServer> webservers(num_servers, NULL); // create vector that will hold webservers
    for (int i = 0; i < num_servers; i++) {
        char server_name = char(A_ASCII_VALUE + i);
        WebServer* webserver = new WebServer(server_name);
        webservers.at(i) = *webserver;
    }

    return 0;
}
