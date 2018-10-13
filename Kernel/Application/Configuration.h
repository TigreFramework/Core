//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_SINGLETON_H
#define TIGREFRAMEWORK_SINGLETON_H

#include <string>
#include <functional>
#include <map>
#include <vector>
#include "Configurable.h"

class Configuration {

    public:
        static Configurable* get(const std::string &name);

        template <class T>
        static T Get(const std::string &name){
            return dynamic_cast<T>(Configuration::get(name));
        }

        static void set(std::string name, Configurable* instance);
        static void set(std::string name, std::function<Configurable*()> instantiable);
        static void dump();

    private:
        static std::vector<Configurable*> instantiables_auto_dump;
        static std::map<std::string, Configurable*> instances;
        static std::map<std::string, std::function<Configurable*()>> instantiables;

};


#endif //TIGREFRAMEWORK_SINGLETON_H
