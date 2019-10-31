#ifndef SERVER_NOTIFIER_H
#define SERVER_NOTIFIER_H

#include <string>
#include "../map/tile.h"
class player;
class entity;

class notifier {
public:
    virtual void add_notified_region(tile_position) = 0;
    virtual void add_notified_player(std::shared_ptr<player> player) = 0;
    virtual void add_notified_entity(std::shared_ptr<entity> entity) = 0;
    virtual void clear_notified_units() = 0;
    virtual void clear_notified_players() = 0;
    virtual void clear_notified_regions() = 0;

    virtual void set_default_int(std::string key, int value) = 0;
    virtual void set_default_float(std::string key, float value) = 0;
    virtual void set_default_string(std::string key, std::string value) = 0;

    virtual void set_int(std::string key, int value) = 0;
    virtual void set_float(std::string key, int value) = 0;
    virtual void set_string(std::string key, int value) = 0;
    virtual void notify() = 0;
};


#endif //SERVER_NOTIFIER_H
