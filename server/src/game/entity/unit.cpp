#include <utility>
#include <utility>
#include "unit.h"
#include "../map/tile_map.h"
#include "../map/tile.h"
#include "../game.h"

unit::unit(std::shared_ptr<game> game, tile_position position) :
    entity(game), position_(position)
{

}

void unit::move_to(tile_position dest) {
    std::shared_ptr<tile_map> map = game_->get_map();
    if (map->is_adjacent(position_, dest)) {
        std::shared_ptr<tile> curr_tile = map->get_tile(position_);
        std::shared_ptr<tile> dest_tile = map->get_tile(dest);
        if (!dest_tile->is_obstructed()) {
            curr_tile->remove_unit();
            dest_tile->set_unit(shared_from_this());
        }
    }
}

std::string unit::to_string() {
    return "A unit";
}
