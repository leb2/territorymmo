//
// Created by Brendan Le on 2019-10-24.
//

#ifndef SERVER_ENTITY_H
#define SERVER_ENTITY_H


#include <string>

class entity {
public:
    explicit entity(std::string id);
private:
    std::string id_;
};

#endif //SERVER_UNIT_H
