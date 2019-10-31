#ifndef SERVER_ENTITY_H
#define SERVER_ENTITY_H

#include <string>

class notifier;
class game;
class entity {
public:
    entity(std::shared_ptr<game> game);

protected:
    std::shared_ptr<notifier> notifier_;
    std::shared_ptr<game> game_;

private:
    std::string id_;
};

#endif //SERVER_UNIT_H
