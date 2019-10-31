#include "tcp_connection.h"
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>


tcp_connection::tcp_connection(boost::asio::io_context& io_context)
    : socket_(io_context) {
}

tcp_connection::pointer tcp_connection::create(boost::asio::io_context& io_context) {
    return pointer(new tcp_connection(io_context));
}

tcp::socket& tcp_connection::socket() {
    return socket_;
}

void tcp_connection::start() {
    start_read();
}

void tcp_connection::start_read() {
    boost::array<char, 1000> array{};
    boost::asio::async_read(socket_, boost::asio::buffer(array),
                            boost::bind(&tcp_connection::handle_read, shared_from_this(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
    std::cout << "Got message" << std::endl;
}

void tcp_connection::write(std::string message) {
    boost::asio::async_write(socket_, boost::asio::buffer(message),
                             boost::bind(&tcp_connection::handle_write, shared_from_this(),
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
}

void tcp_connection::handle_read(const boost::system::error_code& /*error*/,
                                 size_t /*bytes_transferred*/) {
    start_read();
}

// Called after finished writing
void tcp_connection::handle_write(const boost::system::error_code& /*error*/,
                  size_t /*bytes_transferred*/) {
    std::cout << "Finished writing " << std::endl;
}

