#ifndef SERVER_UNIT_H
#define SERVER_UNIT_H

#include <memory>
#include "entity.h"
#include "../map/tile_data.h"

class game;

class unit : public entity, std::enable_shared_from_this<unit> {
public:
    unit(std::shared_ptr<game> game, tile_position position);
    void move_to(tile_position dest);

private:
    tile_position position_;
    std::shared_ptr<game> game_;
};


#endif //SERVER_UNIT_H
