//
// Created by Brendan Le on 2019-10-25.
//

#include "player_set.h"
#include "../player/player.h"

std::shared_ptr<player> player_set::get_player_by_id(std::string player_id) {
    return std::make_shared<player>(player_id);
}
