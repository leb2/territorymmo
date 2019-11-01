#include <utility>
#include "game.h"
#include "player/player_set.h"
#include "notifier/notifier_factory.h"
#include <iostream>
#include "entity/unit.h"

game::game(std::shared_ptr<notifier_factory> factory) :
    players_(std::make_shared<player_set>()),
    map_(std::make_shared<tile_map>()),
    notifier_factory_(factory)
{
    std::cout << "Game created" << std::endl;
}

std::shared_ptr<tile_map> game::get_map() {
    return map_;
}

void game::initialize_map() {
    std::shared_ptr<tile> _tile = map_->get_tile({0, 0});
    std::shared_ptr<game> _game = shared_from_this();
    std::shared_ptr<unit> _unit = std::make_shared<unit>(_game);
    _unit->move_to({3, 3});
}
