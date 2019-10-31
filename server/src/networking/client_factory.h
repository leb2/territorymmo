//
// Created by Brendan Le on 2019-10-30.
//

#ifndef SERVER_CLIENT_FACTORY_H
#define SERVER_CLIENT_FACTORY_H


#include "client.h"

class client_factory {
    virtual std::shared_ptr<client> create_client(std::shared_ptr<tcp_connection> connection, std::string id) = 0;
};


#endif //SERVER_CLIENT_FACTORY_H
