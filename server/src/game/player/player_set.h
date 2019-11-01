//
// Created by Brendan Le on 2019-10-25.
//

#ifndef SERVER_PLAYER_SET_H
#define SERVER_PLAYER_SET_H

#include <string>
#include "player_set_interface.h"

class player_set : public player_set_interface {
public:
    std::shared_ptr<player> get_player_by_id(std::string player_id) override;
};


#endif //SERVER_PLAYER_SET_H
