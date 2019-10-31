#include "game_client.h"
#include <iostream>

game_client::game_client(std::shared_ptr<tcp_connection> connection)
    : connection_(connection) {
    std::cout << "New client created" << std::endl;
}

void game_client::handle_request(std::string message) {
    std::cout << "message is " << message << std::endl;
}

