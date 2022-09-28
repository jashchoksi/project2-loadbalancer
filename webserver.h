#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

class WebServer {
    public:
        WebServer();
    private:
        Request request;
        int process_time;
};

#endif
