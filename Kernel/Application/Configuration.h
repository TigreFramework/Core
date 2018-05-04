//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_SINGLETON_H
#define TIGREFRAMEWORK_SINGLETON_H

#include <string>
#include <map>
#include "Configurable.h"

class Configuration {

    public:
        static Configurable* get(const std::string &name);
        static void set(std::string name, Configurable* instance);
        static void dump();

    private:
        static std::map<std::string, Configurable*> instances;

};


#endif //TIGREFRAMEWORK_SINGLETON_H
