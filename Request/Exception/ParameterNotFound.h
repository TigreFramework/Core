//
// Created by pedrosoares on 6/7/18.
//

#ifndef TIGREFRAMEWORK_PARAMETERNOTFOUND_H
#define TIGREFRAMEWORK_PARAMETERNOTFOUND_H


#include <TigreFramework/Core/Kernel/Exception.h>

class ParameterNotFound : public Exception {

    public:
        ParameterNotFound();
        explicit ParameterNotFound(std::string what);

};


#endif //TIGREFRAMEWORK_PARAMETERNOTFOUND_H
