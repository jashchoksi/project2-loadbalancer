#include "webserver.h"

/**
 * @brief WebServer constructor.
 *
 * Creates a WebServer object with its name as @a server_name, and an initial @a request_process_start_time value of 0.
 *
 * @param server_name character to be used as the name of the server
*/
WebServer::WebServer(char server_name) {
    this->server_name = server_name;
    this->request_process_start_time = 0;
}

/**
 * @brief Gets the request the webserver is processing.
 *
 * @returns A pointer to the request the webserver is processing
*/
Request* WebServer::getRequest() { return this->request; }

/**
 * @brief Gets the name of the webserver.
 *
 * @returns A character denoting the name of the webserver
*/
char WebServer::getServerName() { return this->server_name; }

/**
 * @brief Webserver takes in request and starts processing it.
 *
 * @param request the request to be processed by the webserver
 * @param current_time the current time/clock cycle which will serve as the starting processing time for the request
*/
void WebServer::processRequest(Request* request, int current_time) {
    this->request = request;
    this->request_process_start_time = current_time;
}

/**
 * @brief Checks if the request is done processing.
 *
 * @param current_time the current time/clock cycle which will be used to determine whether or not the webserver has finished processing
 * the request
 *
 * @returns True if request is done processing, otherwise False
*/
bool WebServer::requestDoneProcessing(int current_time) { return (current_time >= (request_process_start_time + this->request->process_time));  }
