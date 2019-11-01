#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include "networking/tcp_server.h"
#include "clientinteraction/game_notifier_factory.h"
#include "clientinteraction/game_client_factory.h"
#include "game/game.h"
#include "game/notifier/notifier_factory.h"

using boost::asio::ip::tcp;

int main() {
    try {
        std::shared_ptr<notifier_factory> _notifier_factory = std::make_shared<game_notifier_factory>();
        std::shared_ptr<game> _game = std::make_shared<game>(_notifier_factory);
        std::shared_ptr<client_factory> _factory = std::make_shared<game_client_factory>(_game);

        boost::asio::io_context io_context;
        tcp_server server(io_context, _factory);
        io_context.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}