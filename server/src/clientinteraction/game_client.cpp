#include "game_client.h"
#include <iostream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

game_client::game_client(std::shared_ptr<tcp_connection> connection)
    : connection_(connection) {
    std::cout << "New client created" << std::endl;
}

void game_client::handle_request(std::string message) {
    std::cout << "message is " << message << std::endl;
    try {
        json result = json::parse(message);
        json commands = result["commands"];
        for (int i = 0; i < commands.size(); i++) {
            std::cout << result["commands"][i] << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Could not parse json." << std::endl;
    }
}

