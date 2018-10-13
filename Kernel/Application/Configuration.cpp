//
// Created by pedrosoares on 4/28/18.
//

#include <algorithm>
#include "Configuration.h"

std::map<std::string, Configurable*> Configuration::instances;
std::map<std::string, std::function<Configurable*()>> Configuration::instantiables;
std::vector<Configurable*> Configuration::instantiables_auto_dump;

Configurable* Configuration::get(const std::string &name) {
    if(Configuration::instances.find(name) != Configuration::instances.end()){
        return Configuration::instances[name];
    } else if(Configuration::instantiables.find(name) != Configuration::instantiables.end()){
        auto pointer = Configuration::instantiables[name]();
        /**
         * Validates if is nescessary dump on end o execution and add to the list if its not was included before
         */
        if(
            pointer->autoDump &&
            std::find(
                Configuration::instantiables_auto_dump.begin(),
                Configuration::instantiables_auto_dump.end(),
                pointer
            ) != Configuration::instantiables_auto_dump.end()
        ){
            Configuration::instantiables_auto_dump.push_back(pointer);
        }
        return pointer;
    }
    return nullptr;
}

void Configuration::set(std::string name, Configurable *instance) {
    Configuration::instances[name] = instance;
}

void Configuration::set(std::string name, std::function<Configurable *()> instantiable) {
    Configuration::instantiables[name] = std::move(instantiable);
}

void Configuration::dump() {
    for (const auto& kv : Configuration::instances) {
        if(kv.first != "Exception.Handler" && kv.second->autoDump) {
            delete kv.second;
        }
    }
    for(const auto& kv : Configuration::instantiables_auto_dump){
        delete kv;
    }

    Configuration::instances.clear();
    Configuration::instantiables_auto_dump.clear();
}