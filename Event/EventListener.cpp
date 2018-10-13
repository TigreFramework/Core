//
// Created by pedrosoares on 5/22/18.
//

#include "EventListener.h"

Listeners EventListener::listeners;

void EventListener::Register(std::string name, EventListener* listener) {
    EventListener::listeners[name].push_back(listener);
}

void EventListener::Call(std::string name, Event& listener) {
    for(auto eventListener : EventListener::listeners[name]){
        eventListener->handle(listener);
    }
}

void EventListener::Dump() {
    for (auto& kv : EventListener::listeners) {
        for(const auto& kk : kv.second){
            delete (kk);
        }
        kv.second.clear();
    }
    EventListener::listeners.clear();
}