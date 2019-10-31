#include "tcp_connection.h"
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include "client_factory.h"


tcp_connection::tcp_connection(boost::asio::io_context& io_context)
    : socket_(io_context) {
}

tcp_connection::~tcp_connection() {
    std::cout << "I am being deconstruted!" << std::endl;
}

void tcp_connection::set_client(std::shared_ptr<client> client) {
    client_ = client;
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
    std::cout << "starting read" << std::endl;
    boost::asio::async_read(socket_, boost::asio::buffer(read_buffer_),
                            boost::bind(&tcp_connection::handle_read, std::enable_shared_from_this<tcp_connection>::shared_from_this(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
    std::cout << "end of this" << std::endl;
}

void tcp_connection::write(std::string message) {
    boost::asio::async_write(socket_, boost::asio::buffer(message),
                             boost::bind(&tcp_connection::handle_write, std::enable_shared_from_this<tcp_connection>::shared_from_this(),
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
}

void tcp_connection::handle_read(const boost::system::error_code& error,
                                 size_t bytes_transferred) {
    std::cout << "Handling read " << std::endl;
    client_->handle_request(std::string(&read_buffer_[0], bytes_transferred));
    if (error.failed()) {
        std::cout << "Error was: " << error.message() << std::endl;
        return;
    }
    std::cout << "Got message from client" << std::endl;
    start_read();
}

// Called after finished writing
void tcp_connection::handle_write(const boost::system::error_code& error,
                  size_t bytes_transferred) {
    std::cout << "Finished writing " << std::endl;
}

