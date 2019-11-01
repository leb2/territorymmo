//
// Created by Brendan Le on 2019-10-24.
//

#ifndef SERVER_NOTIFIER_FACTORY_H
#define SERVER_NOTIFIER_FACTORY_H

#include "notifier.h"

class notifier_factory {
public:
    virtual std::shared_ptr<notifier> create() = 0;
};


#endif //SERVER_NOTIFIER_FACTORY_H
