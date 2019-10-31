#ifndef SERVER_GAME_CLIENT_FACTORY_H
#define SERVER_GAME_CLIENT_FACTORY_H


#include "../networking/client_factory.h"

class game_client_factory : public client_factory {
public:
    std::shared_ptr<client> create_client(std::shared_ptr<tcp_connection> connection, std::string id) override;
};


#endif //SERVER_GAME_CLIENT_FACTORY_H
