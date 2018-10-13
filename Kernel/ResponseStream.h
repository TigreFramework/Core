//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_RESPONSESTREAM_H
#define TIGREFRAMEWORK_RESPONSESTREAM_H

#include <string>
#include <TigreFramework/Core/Kernel/Application/Configurable.h>

class ResponseStream : public Configurable {

    public:
        virtual void write(std::string text) = 0;

};

#endif //TIGREFRAMEWORK_RESPONSESTREAM_H
