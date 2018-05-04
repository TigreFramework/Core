//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_RESPONSE_H
#define TIGREFRAMEWORK_RESPONSE_H

#include <string>
#include <nlohmann/json/single_include/nlohmann/json.hpp>



class Response {

    public:
        explicit Response() = default;
        Response(std::string content, int code);
        Response(nlohmann::json content);
        //Response(const char content[]);
        std::string render();

        Response& operator=(const Response& rhs);

    private:
        int code = 200;
        std::string content_type = "Content-Type: text/html; charset=UTF-8";
        std::string content;

        std::string codeToText();

};


#endif //TIGREFRAMEWORK_RESPONSE_H
