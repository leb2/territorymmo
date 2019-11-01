#ifndef SERVER_GAME_NOTIFIER_H
#define SERVER_GAME_NOTIFIER_H

#include "../game/notifier/notifier.h"

class game_notifier : public notifier {
public:
    void add_notified_region(tile_position) override;
    void add_notified_player(std::shared_ptr<player> player) override;
    void add_notified_entity(std::shared_ptr<entity> entity) override;
    void clear_notified_units() override;
    void clear_notified_players() override;
    void clear_notified_regions() override;

    void set_default_int(std::string key, int value) override;
    void set_default_float(std::string key, float value) override;
    void set_default_string(std::string key, std::string value) override;

    void set_int(std::string key, int value) override;
    void set_float(std::string key, int value) override;
    void set_string(std::string key, int value) override;
    void notify() override;
};


#endif //SERVER_GAME_NOTIFIER_H
