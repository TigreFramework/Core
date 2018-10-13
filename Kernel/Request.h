//
// Created by pedrosoares on 4/28/18.
//

#ifndef TIGREFRAMEWORK_REQUEST_H
#define TIGREFRAMEWORK_REQUEST_H

#include <string>
#include <map>
#include <nlohmann/json/single_include/nlohmann/json.hpp>
#include "Client.h"

class Request {


    public:
        explicit Request(std::map<std::string, std::string> header);
        std::string getUri();
        std::string getMethod();
        std::map<std::string, std::string> getHeaders();
        std::string getHeader(std::string name);

        std::string get(std::string name, std::string default_value);
        std::string get(std::string name);
        bool has(std::string name);
        nlohmann::json all();

        static std::string urlDecode(std::string url);

    private:
        std::string method;
        std::string uri;
        std::map<std::string, std::string> header;
        std::vector<std::map<std::string, std::string>> post_form_data;
        nlohmann::json post_json;


};


#endif //TIGREFRAMEWORK_REQUEST_H
