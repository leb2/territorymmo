#ifndef SERVER_TILE_MAP_H
#define SERVER_TILE_MAP_H

#include <map>
#include "tile_map_interface.h"
#include "tile_data.h"

class tile_map : public tile_map_interface {

public:
    tile_map();
    std::shared_ptr<tile> get_tile(tile_position) override;
    bool is_adjacent(tile_position position1, tile_position position2) override;

private:
    std::map<tile_position, std::shared_ptr<tile>> tile_map_;
};


#endif //SERVER_TILE_MAP_H
