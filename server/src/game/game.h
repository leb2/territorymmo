//
// Created by Brendan Le on 2019-10-24.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <list>
#include "notifier/notifier.h"
#include "player/player.h"
#include "map/tile_map.h"
#include "map/tile_map_interface.h"
#include "player/player_set_interface.h"
#include "notifier/notifier_factory.h"

class game {

public:
    game(std::shared_ptr<notifier_factory> factory);
    std::shared_ptr<tile_map_interface> get_map();

private:
    std::shared_ptr<player_set_interface> players_;
    std::shared_ptr<tile_map_interface> map_;
    std::shared_ptr<notifier_factory> notifier_factory_;
};


#endif //SERVER_GAME_H
