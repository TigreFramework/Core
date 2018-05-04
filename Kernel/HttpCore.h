//
// Created by pedrosoares on 4/29/18.
//

#ifndef TIGREFRAMEWORK_HTTPCORE_H
#define TIGREFRAMEWORK_HTTPCORE_H

class HttpCore {

    public:
        virtual void handle() = 0; //Handle the HTTP Request

};

#endif //TIGREFRAMEWORK_HTTPCORE_H
