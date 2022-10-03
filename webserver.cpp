#include "webserver.h"

WebServer::WebServer(char server_name) {
    this->server_name = server_name;
    this->request_process_start_time = 0;
}

char WebServer::getServerName() { return this->server_name; }

bool WebServer::isRequestProcessed(int current_time) { return (current_time >= (request_process_start_time + request.process_time)); }

void WebServer::processRequest(Request request, int current_time) {
    this->request = request;
    this->request_process_start_time = current_time;
}
