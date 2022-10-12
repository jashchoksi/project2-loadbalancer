#include "webserver.h"

WebServer::WebServer(char server_name) {
    this->server_name = server_name;
    this->request_process_start_time = 0;
    this->has_request = false;
}

char WebServer::getServerName() { return this->server_name; }

bool WebServer::hasRequest() { return this->has_request; }

bool WebServer::isRequestProcessed(int current_time) {
    if (current_time >= (request_process_start_time + request.process_time)) {
        this->has_request = false;
        return true;
    } else {
        return false;
    }
}

void WebServer::processRequest(Request request, int current_time) {
    this->request = request;
    this->request_process_start_time = current_time;
    this->has_request = true;
}
