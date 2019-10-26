#ifndef SERVER_TILE_H
#define SERVER_TILE_H

#include "../entity/unit.h"

struct tile_position {
    int x;
    int y;
};

class tile {
public:
    std::shared_ptr<unit> get_unit();
    tile_position get_position();

    void remove_unit();
    void set_unit(std::shared_ptr<unit> unit);
    bool is_obstructed();

private:
    tile_position position_;
    std::shared_ptr<unit> unit_;
};


#endif //SERVER_TILE_H
