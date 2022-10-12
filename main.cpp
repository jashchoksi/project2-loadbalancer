#include "loadbalancer.h"
#include "webserver.h"

#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

const int A_ASCII_VALUE = 65;
const int PROCESS_TIME_LIMIT = 500;

Request* generateRandomRequest() {
    Request* generated_request = new Request();
    generated_request->process_time = rand() % PROCESS_TIME_LIMIT;

    return generated_request;
}

int main() {
    srand(time(0));

    std::ofstream ofs("log.txt", std::ios::out | std::ios::trunc);

    int num_servers = 0;
    int run_time = 0;
    int requests_to_generate = 0;

    std::cout << "Enter number of servers: ";
    std::cin >> num_servers;

    std::cout << "Enter time to run the load balancer: ";
    std::cin >> run_time;

    ofs << "Log of " << num_servers << " servers running for " << run_time << " clock cycles" << std::endl;

    LoadBalancer* load_balancer = new LoadBalancer();

    requests_to_generate = num_servers * 2;
    for (int i = 0; i < requests_to_generate; i++) {
        Request* generated_request = generateRandomRequest();
        load_balancer->pushNewRequest(generated_request);
    }

    ofs << "Starting queue size: " << load_balancer->getQueueSize() << std::endl << std::endl;

    std::vector<WebServer*> webservers(num_servers, nullptr);
    for (int i = 0; i < num_servers; i++) {
        char server_name = char(A_ASCII_VALUE + i);
        WebServer* webserver = new WebServer(server_name);
        webserver->processRequest(load_balancer->popNextRequest(), load_balancer->getTime());
        webservers[i] = webserver;
    }

    int min_task_time = webservers[0]->getRequest()->process_time;
    int max_task_time = webservers[0]->getRequest()->process_time;
    while (load_balancer->getTime() < run_time) {
        for (int i = 0; i < webservers.size(); i++) {
            int current_time = load_balancer->getTime();
            WebServer* webserver = webservers[i]; // can also not use for loop and just index vector using webservers[current_time % webservers.size()]

            if (webserver->getRequest() != nullptr && webserver->requestDoneProcessing(current_time)) {
                Request* processed_request = webserver->getRequest();

                if (processed_request->process_time < min_task_time) {
                    min_task_time = processed_request->process_time;
                } else if (processed_request->process_time > max_task_time) {
                    max_task_time = processed_request->process_time;
                }

                ofs << webserver->getServerName() << " finished processing request from " + processed_request->ip_in + " to " +
                    processed_request->ip_out + " at time " << current_time << std::endl;

                std::cout << webserver->getServerName() << " finished processing request from " + processed_request->ip_in + " to " +
                            processed_request->ip_out + " at time " << current_time << std::endl;

                webserver->processRequest(load_balancer->popNextRequest(), current_time);
            } else if (webserver->getRequest() == nullptr) {
                webserver->processRequest(load_balancer->popNextRequest(), current_time);
            }

            if (rand() % 15 == 0) {
                load_balancer->pushNewRequest(generateRandomRequest());
            }

            load_balancer->incrementTime();
        }
    }

    ofs << std::endl << "Ending queue size: " << load_balancer->getQueueSize() << std::endl;
    ofs << "Range of task times: [" << min_task_time << ", " << max_task_time << "]" << std::endl;

    return 0;
}
