#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

/**
 * @brief Implementation of a webserver that will process requests.
*/
class WebServer {
    public:
        WebServer(char server_name);
        Request* getRequest();
        char getServerName();
        void processRequest(Request* request, int current_time);
        bool requestDoneProcessing(int current_time);
    private:
        /**
         * @brief The request the webserver is processing.
        */
        Request* request;
        /**
         * @brief The time/clock cycle at which the webserver started processing the request.
        */
        int request_process_start_time;
        /**
         * @brief The character that corresponds to the name of the webserver.
        */
        char server_name;
};

#endif
