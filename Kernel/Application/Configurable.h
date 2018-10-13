//
// Created by pedrosoares on 4/29/18.
//

#ifndef TIGREFRAMEWORK_CONFIGURABLE_H
#define TIGREFRAMEWORK_CONFIGURABLE_H

class Configurable {

    public:
        virtual ~Configurable() = default;
        explicit Configurable(bool autoDump = true) : autoDump(autoDump) { };
        bool autoDump = true;

};

#endif //TIGREFRAMEWORK_CONFIGURABLE_H
