//
// Created by pedrosoares on 4/28/18.
//
#include <TigreFramework/Core/Kernel/Application/Configuration.h>
#include <TigreFramework/Core/Kernel/Router.h>
#include <TigreFramework/Core/Kernel/HttpCore.h>
#include <TigreFramework/Core/Kernel/Application/Bootstrap.h>
#include <TigreFramework/Core/Kernel/Application/ServiceProvider.h>
#include <TigreFramework/Core/Event/EventListener.h>
#include "Application.h"

Application::Application() : Configurable(false) {
    Configuration::set("app", this);
}

Application::Application(int argc, char **argv, char **envp) : Configurable(false), argc(argc), argv(argv), envp(envp) {
    Configuration::set("app", this);
}

Application::~Application() {
    Configuration::dump();
    ServiceProvider::dump();
    EventListener::Dump();
}

int Application::run() {

    Bootstrap::boot(); //Load the application configuration
    ServiceProvider::bootAll(); //Load all providers

    //Load ours routes into de memory
    Router *router = (Router *) Configuration::get("Router");
    router->boot();

    //Handle the Request made by the client thought the driver
    HttpCore *httpCore = (HttpCore *) Configuration::get("Http.Core");
    httpCore->handle();

    return 0;
}

int Application::getArgc() {
    return this->argc;
}

char** Application::getArgv() {
    return this->argv;
}

char** Application::getEnvp() {
    return this->envp;
}