//
// Created by pedrosoares on 4/29/18.
//

#ifndef TIGREFRAMEWORK_ROUTER_H
#define TIGREFRAMEWORK_ROUTER_H

#include <TigreFramework/Core/Kernel/Application/Configurable.h>
#include "Request.h"
#include "Response.h"

class Router : public Configurable {

    public:
        virtual void boot() = 0;
        virtual Response handle(Request *request) = 0;

};

#endif //TIGREFRAMEWORK_ROUTER_H
