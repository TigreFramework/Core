//
// Created by pedrosoares on 4/28/18.
//

#include <TigreFramework/Core/Kernel/Application/Configuration.h>
#include <TigreFramework/Core/Kernel/Application/Env.h>
#include "Request.h"

Request::Request(std::map<std::string, std::string> header) : header(std::move(header)) {
    Env * env = (Env *) Configuration::get("env");

    //Initialize the Variable Method
    this->method = env->get( "REQUEST_METHOD", "GET" );

    //Initialize the Variable Method
    this->uri = env->get( "REQUEST_URI", "/" );
}

std::string Request::getUri() {
    return this->uri;
}

std::string Request::getMethod() {
    return this->method;
}

std::map<std::string, std::string> Request::getHeaders() {
    return this->header;
}

std::string Request::getHeader(std::string name) {
    return this->header[name];
}