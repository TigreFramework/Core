//
// Created by pedrosoares on 6/7/18.
//

#include "ParameterNotFound.h"

ParameterNotFound::ParameterNotFound() : Exception() {

}

ParameterNotFound::ParameterNotFound(std::string what) : Exception(std::move(what)) {

}