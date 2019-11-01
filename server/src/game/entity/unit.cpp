#include <utility>

#include <utility>
#include <utility>
#include "unit.h"
#include "../map/tile_map.h"
#include "../map/tile.h"
#include "../game.h"
#include <iostream>

unit::unit(std::shared_ptr<game> game) :
    entity(game), on_map_(false), game_(game)
{
    std::cout << "Making unit " << std::endl;
}

void unit::move_to(tile_position dest) {
    on_map_ = true;
    std::shared_ptr<tile_map> map = game_->get_map();
    if (map->is_adjacent(position_, dest)) {
        std::shared_ptr<tile> curr_tile = map->get_tile(position_);
        std::shared_ptr<tile> dest_tile = map->get_tile(dest);
        if (!dest_tile->is_obstructed()) {
            curr_tile->remove_unit();
            std::shared_ptr<unit> _unit = shared_from_this();
            dest_tile->set_unit(_unit);
        }
    } else {
        throw "cannot move unit into position " + dest.to_string();
    }
}

std::string unit::to_string() {
    return "A unit";
}
