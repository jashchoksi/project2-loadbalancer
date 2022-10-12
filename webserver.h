#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

class WebServer {
    public:
        WebServer(char server_name);
        char getServerName();
        bool hasRequest();
        bool isRequestProcessed(int current_time);
        void processRequest(Request request, int current_time);
    private:
        bool has_request;
        Request request;
        int request_process_start_time;
        char server_name;
};

#endif
