#include <utility>
#include "entity.h"

std::string rand_id(const int len) {
    std::string letters  =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::string id;
    for (int i = 0; i < len; ++i) {
        id += letters[std::rand() % (letters.length() - 1)];
    }
    return id;
}

entity::entity(std::shared_ptr<game> game) :
    game_(std::move(game)), id_(rand_id(10)) {}
