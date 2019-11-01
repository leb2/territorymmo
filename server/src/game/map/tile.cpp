#include <utility>
#include <memory>
#include "tile.h"
#include "../entity/unit.h"
#include <boost/format.hpp>

tile::tile(tile_position position) : position_(position) {
}

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

std::string tile::to_string() {
    return (boost::format("<Tile at position %1% with unit %2%>") % position_.to_string() % unit_->to_string()).str();
}

