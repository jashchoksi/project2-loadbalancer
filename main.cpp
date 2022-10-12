#include "loadbalancer.h"
#include "webserver.h"

#include <iostream>
#include <time.h>
#include <vector>

const int A_ASCII_VALUE = 65;
const int PROCESS_TIME_MODIFIER = 500;

Request* generateRandomRequest() {
    Request* generated_request = new Request();
    generated_request->process_time = rand() % PROCESS_TIME_MODIFIER;

    return generated_request;
}

int main() {
    srand(time(0));

    int num_servers = 0;
    int run_time = 0;
    int requests_to_generate = 0;

    std::cout << "Enter number of servers: ";
    std::cin >> num_servers;

    std::cout << "Enter time to run the load balancer: ";
    std::cin >> run_time;

    LoadBalancer* load_balancer = new LoadBalancer();

    requests_to_generate = num_servers * 2;
    for (int i = 0; i < requests_to_generate; i++) {
        load_balancer->pushNewRequest(generateRandomRequest());
    }

    std::vector<WebServer*> webservers(num_servers, NULL);
    for (int i = 0; i < num_servers; i++) {
        char server_name = char(A_ASCII_VALUE + i);
        WebServer* webserver = new WebServer(server_name);
        webservers[i] = webserver;
    }

    while (!load_balancer->isQueueEmpty() && load_balancer->getTime() < run_time) {
        for (int i = 0; i < webservers.size(); i++) {
            int current_time = load_balancer->getTime();
            WebServer* webserver = webservers[i];

            if (!webserver->hasRequest()) {
                webserver->processRequest(load_balancer->popNextRequest(), current_time);
            } else if (webserver->requestDoneProcessing(current_time)) {
                Request* processed_request = webserver->getRequest();
                std::cout << webserver->getServerName() << " finished processing request from " + processed_request->ip_in + " to " +
                             processed_request->ip_out + " at time " << current_time << std::endl;

                webserver->processRequest(load_balancer->popNextRequest(), current_time);
            }
            load_balancer->incrementTime();
        }

        if (rand() % 10 == 0) {
            load_balancer->pushNewRequest(generateRandomRequest());
        }

        load_balancer->incrementTime();
    }

    return 0;
}
