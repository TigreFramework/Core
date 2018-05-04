//
// Created by pedrosoares on 4/29/18.
//

#include "Exception.h"

Exception::Exception() : message("") {}

Exception::Exception(std::string what) : message(what) {}

std::string Exception::what() {
    return this->message;
}