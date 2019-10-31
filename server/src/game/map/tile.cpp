#include <utility>
#include <memory>
#include "tile.h"
#include "../entity/unit.h"

std::shared_ptr<unit> tile::get_unit() {
    return unit_;
}

tile_position tile::get_position() {
    return position_;
}

bool tile::is_obstructed() {
    return false;
}

void tile::remove_unit() {
    unit_ = nullptr;
}

void tile::set_unit(std::shared_ptr<unit> unit) {
    unit_ = std::move(unit);
}

