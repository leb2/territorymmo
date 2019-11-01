//
// Created by Brendan Le on 2019-10-24.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <list>

class notifier_factory;
class player_set_interface;
class tile_map;

class game {

public:
    game(std::shared_ptr<notifier_factory> factory);
    std::shared_ptr<tile_map> get_map();

private:
    std::shared_ptr<player_set_interface> players_;
    std::shared_ptr<tile_map> map_;
    std::shared_ptr<notifier_factory> notifier_factory_;
};

#endif //SERVER_GAME_H
