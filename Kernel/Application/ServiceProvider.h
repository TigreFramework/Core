//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_SERVICEPROVIDER_H
#define TIGREFRAMEWORK_SERVICEPROVIDER_H

#include <string>
#include <map>
#include <vector>

class ServiceProvider {

    public:
        virtual void boot() = 0;
        virtual void Register(){ };

        static void registerProvider(ServiceProvider* provider);
        static void bootAll();

        static void dump();

    private:
        static std::vector<ServiceProvider*> providers;

};


#endif //TIGREFRAMEWORK_SERVICEPROVIDER_H
