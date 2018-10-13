cmake_minimum_required(VERSION 3.4)
project(TigreFramework)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SYSTEM_FILES
        Kernel/Request.cpp
        Kernel/Response.cpp
        Kernel/Client.cpp
        Kernel/Application/ServiceProvider.cpp
        Kernel/Application/Configuration.cpp
        Kernel/Application.cpp
        Kernel/Exception.cpp Kernel/Exception.h
        Kernel/ExceptionHandler.h
        Kernel/PageNotFoundException.cpp

        Kernel/Router.h
        Kernel/ResponseStream.h
        Kernel/HttpCore.h
        Kernel/Application/Bootstrap.h
        Kernel/Application/Configurable.h
        Kernel/Application/Env.h

        Event/Event.cpp
        Event/EventListener.cpp

        Request/Exception/ParameterNotFound.cpp
)

set(SOURCE_FILES ${SYSTEM_FILES})

add_library(tgcore ${SYSTEM_FILES})