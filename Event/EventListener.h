//
// Created by pedrosoares on 5/22/18.
//

#ifndef TIGREFRAMEWORK_EVENTLISTENER_H
#define TIGREFRAMEWORK_EVENTLISTENER_H

#include <string>
#include <vector>
#include <map>
#include "Event.h"

#define Listeners std::map<std::string, std::vector<EventListener*>>

class EventListener {

    public:
        static void Register(std::string name, EventListener* listener);
        static void Call(std::string name, Event& listener);
        static void Dump();

        virtual void handle(Event& event) = 0;

    private:
        static Listeners listeners;

};


#endif //TIGREFRAMEWORK_EVENTLISTENER_H
