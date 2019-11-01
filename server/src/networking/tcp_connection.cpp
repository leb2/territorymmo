#include "tcp_connection.h"
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include "client_factory.h"

tcp_connection::tcp_connection(boost::asio::io_context& io_context)
    : socket_(io_context) {
}

tcp_connection::~tcp_connection() {
    std::cout << "I am being deconstructed!" << std::endl;
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
    boost::asio::async_read_until(socket_, read_buffer_, '\r',
                            boost::bind(&tcp_connection::handle_read, std::enable_shared_from_this<tcp_connection>::shared_from_this(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
}

void tcp_connection::write(std::string message) {
    boost::asio::async_write(socket_, boost::asio::buffer(message),
                             boost::bind(&tcp_connection::handle_write, std::enable_shared_from_this<tcp_connection>::shared_from_this(),
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
}

void tcp_connection::handle_read(const boost::system::error_code& error,
                                 size_t bytes_transferred) {
    if (error.failed()) {
        std::cout << "Error was: " << error.message() << std::endl;
        return;
    }
    std::istream input(&read_buffer_);
    std::string line;
    getline(input, line, '\r'); // Consumes from the streambuf.
    client_->handle_request(line);
    start_read();
}

// Called after finished writing
void tcp_connection::handle_write(const boost::system::error_code& error,
                  size_t bytes_transferred) {
}

