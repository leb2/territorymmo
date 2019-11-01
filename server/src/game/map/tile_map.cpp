#include "tile_map.h"
#include "tile.h"
#include <iostream>

tile_map::tile_map() : tile_map_({}) {
}

std::string tile_map::to_string() {
    std::string result = "";
    for (auto iter = tile_map_.begin(); iter != tile_map_.end(); ++iter) {
        tile_position _tile_position = iter->first;
        std::shared_ptr<tile> _tile = iter->second;
        result += (boost::format("%1% -> %2%\n")
                % _tile_position.to_string() % _tile->to_string()).str();
    }
    return result;
}

std::shared_ptr<tile> tile_map::get_tile(tile_position position) {
    auto result = tile_map_.find(position);
    if (result == tile_map_.end()) {
        std::shared_ptr<tile> new_tile = std::make_shared<tile>(position);
        std::cout << "Inserting " << std::endl;
        tile_map_.insert({{position, new_tile}});
        return new_tile;
    }
    return result->second;
}

bool tile_map::is_adjacent(tile_position position1, tile_position position2) {
    return true;
}

