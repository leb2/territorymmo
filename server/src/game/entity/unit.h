#ifndef SERVER_UNIT_H
#define SERVER_UNIT_H

#include <memory>
#include "entity.h"
#include "../map/tile_data.h"

class game;

class unit : public std::enable_shared_from_this<unit>, public entity {
public:
    unit(std::shared_ptr<game> game);
    void move_to(tile_position dest);
    std::string to_string();

private:
    tile_position position_;
    std::shared_ptr<game> game_;
    bool on_map_;
};


#endif //SERVER_UNIT_H
