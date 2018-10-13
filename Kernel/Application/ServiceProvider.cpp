//
// Created by pedrosoares on 4/28/18.
//

#include "ServiceProvider.h"

std::vector<ServiceProvider*> ServiceProvider::providers;

void ServiceProvider::registerProvider(ServiceProvider *provider) {
    ServiceProvider::providers.push_back(provider);
}

void ServiceProvider::bootAll() {
    for(auto provider : ServiceProvider::providers){
        provider->boot();
    }
    for(auto provider : ServiceProvider::providers){
        provider->Register();
    }
}

void ServiceProvider::dump() {
    for(auto provider : ServiceProvider::providers){
        delete (provider);
    }
    ServiceProvider::providers.clear();
}