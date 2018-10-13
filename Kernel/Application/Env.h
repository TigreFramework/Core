//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_ENV_H
#define TIGREFRAMEWORK_ENV_H

#include <string>
#include "Configurable.h"

class Env : public Configurable {

    public:
        virtual std::string get(std::string name, std::string default_value="") = 0;

};

#endif //TIGREFRAMEWORK_ENV_H
