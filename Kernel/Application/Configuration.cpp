#include "Configuration.h"

std::map<std::string, Configurable*> Configuration::instances;

Configurable* Configuration::get(const std::string &name) {
    if(Configuration::instances.find(name) == Configuration::instances.end()) {
        throw std::string("Not found Configuration \"")+name+"\"";
    }
    return Configuration::instances[name];
}

void Configuration::set(std::string name, Configurable *instance) {
    Configuration::instances[name] = instance;
}

void Configuration::dump() {
    for (const auto& kv : Configuration::instances) {
        if(kv.first != "app") {
            delete (kv.second);
        }
    }

    Configuration::instances.clear();
}