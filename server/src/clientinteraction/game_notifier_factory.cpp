#include "game_notifier_factory.h"

std::shared_ptr<notifier> game_notifier_factory::create() {
    return std::shared_ptr<notifier>();
}

game_notifier_factory::game_notifier_factory() {
}
