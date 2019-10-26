#include "tile_map.h"

tile_map::tile_map() : tile_map_({}) {
}

std::shared_ptr<tile> tile_map::get_tile(tile_position position) {
    auto result = tile_map_.find(position);
    if (result == tile_map_.end()) {
        std::shared_ptr<tile> new_tile = std::make_shared<tile>();
        tile_map_.insert({{position, new_tile}});
        return new_tile;
    }
    return result->second;
}

bool tile_map::is_adjacent(tile_position position1, tile_position position2) {
    return true;
}

