//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_APPLICATION_H
#define TIGREFRAMEWORK_APPLICATION_H


#include <TigreFramework/Core/Kernel/Application/Configurable.h>

class Application: public Configurable {

    public:
        Application();
        Application(int argc, char* argv[], char** envp);
        ~Application();

        int run();

        int getArgc();
        char** getArgv();
        char** getEnvp();

    private:
        int argc;
        char** argv;
        char** envp;

};


#endif //TIGREFRAMEWORK_APPLICATION_H
