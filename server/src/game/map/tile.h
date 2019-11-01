#ifndef SERVER_TILE_H
#define SERVER_TILE_H

#include "tile_map.h"
class unit;

class tile {
public:
    tile(tile_position position);
    std::shared_ptr<unit> get_unit();
    tile_position get_position();

    void remove_unit();
    void set_unit(std::shared_ptr<unit> unit);
    bool is_obstructed();
    std::string to_string();

private:
    tile_position position_;
    std::shared_ptr<unit> unit_;
};


#endif //SERVER_TILE_H
