#ifndef SERVER_GAME_CLIENT_H
#define SERVER_GAME_CLIENT_H


#include "../networking/client.h"
class game;

class game_client : public client {
public:
    game_client(std::shared_ptr<game> game);
    game_client(std::shared_ptr<tcp_connection> connection, std::shared_ptr<game> game);
    void handle_request(std::string message) override;

private:
    std::string id_;
    std::shared_ptr<tcp_connection> connection_;
    std::shared_ptr<game> game_;
};


#endif //SERVER_GAME_CLIENT_H
