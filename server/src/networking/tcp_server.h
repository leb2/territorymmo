//
// Created by Brendan Le on 2019-10-23.
//

#ifndef SERVER_TCP_SERVER_H
#define SERVER_TCP_SERVER_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "tcp_connection.h"
#include "client.h"
#include "client_factory.h"

using boost::asio::ip::tcp;

class tcp_server {
public:
    tcp_server(boost::asio::io_context& io_context, std::shared_ptr<client_factory> client_factory);

private:
    void start_accept();
    void handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code& error);
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
    std::shared_ptr<client_factory> client_factory_;
};


#endif //SERVER_TCP_SERVER_H
