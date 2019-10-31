#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H


#include <string>
#include "tcp_connection.h"

class client {
public:
    virtual void handle_request(std::string message) = 0;
};


#endif //SERVER_CLIENT_H
