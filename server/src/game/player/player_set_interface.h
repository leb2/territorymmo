#ifndef SERVER_PLAYER_SET_INTERFACE_H
#define SERVER_PLAYER_SET_INTERFACE_H


class player_set_interface {
public:
    virtual std::shared_ptr<player> get_player_by_id(std::string player_id) = 0;
};


#endif //SERVER_PLAYER_SET_INTERFACE_H
