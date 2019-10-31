#include "game_client_factory.h"
#include "game_client.h"

std::shared_ptr<client> game_client_factory::create_client(std::shared_ptr<tcp_connection> connection) {
    return std::make_shared<game_client>(connection);
}
