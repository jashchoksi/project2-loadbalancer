#include "loadbalancer.h"
#include "webserver.h"

#include <iostream>
#include <time.h>

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
        Request* generated_request = new Request();
        load_balancer->pushNewRequest(*generated_request);
    }

    return 0;
}
