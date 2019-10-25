//
// Created by Brendan Le on 2019-10-23.
//

#ifndef SERVER_TCP_CONNECTION_H
#define SERVER_TCP_CONNECTION_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection> {
public:
    typedef boost::shared_ptr<tcp_connection> pointer;
    static pointer create(boost::asio::io_context& io_context);
    tcp::socket& socket();
    void start();

private:
    void handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/);
    tcp_connection(boost::asio::io_context& io_context);
    tcp::socket socket_;
    std::string message_;
};


#endif //SERVER_TCP_CONNECTION_H
