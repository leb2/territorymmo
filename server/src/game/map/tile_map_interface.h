#ifndef SERVER_TILE_MAP_INTERFACE_H
#define SERVER_TILE_MAP_INTERFACE_H


#include <memory>
#include <unordered_map>
#include "tile.h"

class tile_map_interface {

public:
    virtual std::shared_ptr<tile> get_tile(tile_position) = 0;
    virtual bool is_adjacent(tile_position position1, tile_position position2) = 0;

private:
    std::unordered_map<tile_position, std::shared_ptr<tile>> tile_map_;
};

#endif //SERVER_TILE_MAP_INTERFACE_H
