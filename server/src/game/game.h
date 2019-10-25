//
// Created by Brendan Le on 2019-10-24.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <list>
#include "notifier.h"
#include "player.h"
#include "tile_map.h"
#include "tile_map_interface.h"
#include "player_set_interface.h"

class game {

public:
    game();

private:
    std::shared_ptr<player_set_interface> players_;
    std::shared_ptr<tile_map_interface> map_;
};


#endif //SERVER_GAME_H
