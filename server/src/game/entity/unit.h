#ifndef SERVER_UNIT_H
#define SERVER_UNIT_H

#include "../map/tile.h"
#include <memory>
#include "../game.h"

class unit {
public:
    unit::unit(std::shared_ptr<game> game, tile_position position);
    void move_to(tile_position dest);

private:
    tile_position position_;
    std::shared_ptr<game> game_;
};


#endif //SERVER_UNIT_H
