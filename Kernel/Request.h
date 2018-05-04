//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_REQUEST_H
#define TIGREFRAMEWORK_REQUEST_H

#include <string>
#include <map>
#include "Client.h"

class Request {


    public:
        explicit Request(std::map<std::string, std::string> header);
        std::string getUri();
        std::string getMethod();
        std::map<std::string, std::string> getHeaders();
        std::string getHeader(std::string name);

    private:
        std::string method;
        std::string uri;
        std::map<std::string, std::string> header;

};


#endif //TIGREFRAMEWORK_REQUEST_H
