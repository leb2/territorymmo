#include <utility>
#include "game.h"
#include "player/player_set.h"
#include "notifier/notifier_factory.h"
#include <iostream>

game::game(std::shared_ptr<notifier_factory> factory) :
    players_(std::make_shared<player_set>()),
    map_(std::make_shared<tile_map>()),
    notifier_factory_(std::move(factory))
{
    std::cout << "Game created" << std::endl;
}

std::shared_ptr<tile_map_interface> game::get_map() {
    return map_;
}
