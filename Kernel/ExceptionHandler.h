//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_EXCEPTIONHANDLER_H
#define TIGREFRAMEWORK_EXCEPTIONHANDLER_H

#include <TigreFramework/Core/Kernel/Application/Configurable.h>
#include "Response.h"
#include "Exception.h"

class ExceptionHandler : public Configurable {

    public:
        virtual void report(Exception &exception) = 0;
        virtual Response render(Exception &exception) = 0;

};


#endif //TIGREFRAMEWORK_EXCEPTIONHANDLER_H
