#ifndef TIGREFRAMEWORK_RESPONSE_H
#define TIGREFRAMEWORK_RESPONSE_H

#include <string>
#include <nlohmann/json/single_include/nlohmann/json.hpp>



class Response {

    public:
        explicit Response() = default;
        Response(std::string content, int code);
        Response(nlohmann::json content, int code = 200);
        std::map<std::string, std::string> render();
        Response& operator=(const Response& rhs);

        void setHeader(std::string name, std::string value);


    private:
        int code = 200;
        std::string content;

        std::map<std::string, std::string> headers = {
                {"Content-Type", "text/html; charset=UTF-8"}
        };

        std::string codeToText();

};


#endif //TIGREFRAMEWORK_RESPONSE_H
