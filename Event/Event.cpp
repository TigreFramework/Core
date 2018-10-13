//
// Created by pedrosoares on 5/22/18.
//

#include "Event.h"
#include "EventListener.h"

void Event::emit(std::string name, Event &event) {
    EventListener::Call(name, event);
}

void Event::emit(std::string name, Event *event) {
    if(event != nullptr){
        EventListener::Call(name, *event);
    }else{
        Event event_empty;
        EventListener::Call(name, event_empty);
    }
}
