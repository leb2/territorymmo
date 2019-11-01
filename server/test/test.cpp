#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include "../src/networking/tcp_server.h"
#include "../src/clientinteraction/game_notifier_factory.h"
#include "../src/clientinteraction/game_client_factory.h"
#include "../src/clientinteraction/game_client.h"
#include "../src/game/game.h"
#include "../src/game/notifier/notifier_factory.h"

using boost::asio::ip::tcp;


void test_map() {
    std::shared_ptr<tile_map> _tile_map = std::make_shared<tile_map>();
    _tile_map->get_tile({0, 0});
    _tile_map->get_tile({1, 0});
    std::cout << _tile_map->to_string() << std::endl;
}

int main() {
    std::shared_ptr<notifier_factory> _notifier_factory = std::make_shared<game_notifier_factory>();
    std::shared_ptr<game> _game = std::make_shared<game>(_notifier_factory);
    std::shared_ptr<client> _client = std::make_shared<game_client>(_game);

    test_map();
    return 0;
}
