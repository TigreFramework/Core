//
// Created by pedrosoares on 5/22/18.
//

#ifndef TIGREFRAMEWORK_EVENT_H
#define TIGREFRAMEWORK_EVENT_H

#include <string>

class Event {

    public:
        static void emit(std::string name, Event& event);
        static void emit(std::string name, Event* event);

};


#endif //TIGREFRAMEWORK_EVENT_H
