//
// Created by Brendan Le on 2019-10-24.
//

#ifndef SERVER_TILE_H
#define SERVER_TILE_H

struct tile_position {
    int x;
    int y;
};

class tile {
public:
    std::shared_ptr<unit> get_unit()
    tile_position get_position();
};


#endif //SERVER_TILE_H
