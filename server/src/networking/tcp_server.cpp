#include "tcp_server.h"

// How to copy object into shared pointer?
// Does setting shared pointer to memory address work (if the memory address is garbage collected)
tcp_server::tcp_server(boost::asio::io_context& io_context, std::shared_ptr<client_factory> client_factory)
        : io_context_(io_context),
          client_factory_(client_factory),
          acceptor_(io_context, tcp::endpoint(tcp::v4(), 1234)) {
    start_accept();
}

void tcp_server::start_accept() {
    tcp_connection::pointer new_connection = tcp_connection::create(io_context_);
    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&tcp_server::handle_accept, this, new_connection,
                                       boost::asio::placeholders::error));
}

void tcp_server::handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code& error) {
    std::cout << "\n\nGot a connection " << std::endl;
    if (!error) {
        new_connection->set_client(client_factory_->create_client(new_connection));
        new_connection->start();
    }
    start_accept();
}

