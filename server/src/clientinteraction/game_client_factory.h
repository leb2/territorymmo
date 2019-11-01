#ifndef SERVER_GAME_CLIENT_FACTORY_H
#define SERVER_GAME_CLIENT_FACTORY_H


#include "../networking/client_factory.h"
class game;

class game_client_factory : public client_factory {
public:
    explicit game_client_factory(std::shared_ptr<game> game);
    std::shared_ptr<client> create_client(std::shared_ptr<tcp_connection> connection) override;

private:
    std::shared_ptr<game> game_;
};

#endif //SERVER_GAME_CLIENT_FACTORY_H
