//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_BASE_EXCEPTION_H
#define TIGREFRAMEWORK_BASE_EXCEPTION_H

#include <string>

class Exception {

    public:
        Exception();
        explicit Exception(std::string what);
        virtual std::string what();
        int code = 500;

    private:
        std::string message;

};

#endif //TIGREFRAMEWORK_EXCEPTION_H
