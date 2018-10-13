//
// Created by pedrosoares on 4/29/18.
//

#ifndef TIGREFRAMEWORK_HTTPCORE_H
#define TIGREFRAMEWORK_HTTPCORE_H

#include <TigreFramework/Core/Kernel/Application/Configurable.h>

class HttpCore : public Configurable {

    public:
        virtual void handle() = 0; //Handle the HTTP Request
        virtual void addHeader(std::string name, std::string value="") = 0;
        virtual std::string getHeaders() = 0;
        virtual std::string getPostData() = 0;

};

#endif //TIGREFRAMEWORK_HTTPCORE_H
