#ifndef SERVER_GAME_NOTIFIER_FACTORY_H
#define SERVER_GAME_NOTIFIER_FACTORY_H

#include "../game/notifier/notifier_factory.h"

class game_notifier_factory : public notifier_factory {
    std::shared_ptr<notifier> create() override;
};


#endif //SERVER_GAME_NOTIFIER_FACTORY_H
