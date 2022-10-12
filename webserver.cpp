#include "webserver.h"

WebServer::WebServer(char server_name) {
    this->server_name = server_name;
    this->request_process_start_time = 0;
    this->request = nullptr;
}

char WebServer::getServerName() { return this->server_name; }

Request* WebServer::getRequest() { return this->request; }

bool WebServer::hasRequest() { return this->request != nullptr; }

bool WebServer::requestDoneProcessing(int current_time) { return (current_time >= (request_process_start_time + this->request->process_time));  }

void WebServer::processRequest(Request* request, int current_time) {
    this->request = request;
    this->request_process_start_time = current_time;
}
