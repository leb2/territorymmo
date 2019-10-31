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
#include <boost/array.hpp>

using boost::asio::ip::tcp;
class client_factory;
class client;

class tcp_connection;

class tcp_connection : public std::enable_shared_from_this<tcp_connection> {

public:
    ~tcp_connection();
    typedef std::shared_ptr<tcp_connection> pointer;
    static pointer create(boost::asio::io_context& io_context);
    void set_client(std::shared_ptr<client> client);

    tcp::socket& socket();
    void start();
    void write(std::string message);

private:
    void handle_write(const boost::system::error_code& error, size_t bytes_transferred);
    void handle_read(const boost::system::error_code& error, size_t bytes_transferred);
    void start_read();

    explicit tcp_connection(boost::asio::io_context& io_context);
    std::shared_ptr<client> client_;
    tcp::socket socket_;
    std::string message_;
    boost::array<char, 1000> read_buffer_;
};


#endif //SERVER_TCP_CONNECTION_H
