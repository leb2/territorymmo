#ifndef SERVER_TILE_DATA_H
#define SERVER_TILE_DATA_H

struct tile_position {
    int x, y;

    bool operator == (const tile_position &o) const {
        return x == o.x && y == o.y;
    }

    bool operator < (const tile_position& r) const {
        return (x<r.x || (x==r.x && y<r.y));
    }
};

#endif //SERVER_TILE_DATA_H
