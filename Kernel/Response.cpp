//
// Created by pedrosoares on 4/28/18.
//

#include "Response.h"

Response::Response(std::string content, int code) : content(content), code(code) {

}

Response::Response(nlohmann::json content) : code(200) {
    if(content.is_string()){
        this->content = content;
    }else{
        this->content = content.dump();
    }
}

/*Response::Response(const char *content) : content(content), code(200) {

}*/

Response& Response::operator=(const Response &rhs) {
    this->content = rhs.content;
    this->code = rhs.code;
    return *this;
}

std::string Response::render() {
    std::string header = "HTTP/1.1 "+std::to_string(this->code)+" "+this->codeToText()+"\r\n"
                        +this->content_type+"\r\n"
                        +"\r\n\r\n";

    return header+this->content;
}

std::string Response::codeToText() {
    switch (this->code){
        case 100:
            return "Continue";

        case 101:
            return "Switching Protocols";

        case 200:
            return "OK";

        case 201:
            return "Created";

        case 202:
            return "Accepted";

        case 203:
            return "Non-Authoritative Information";

        case 204:
            return "No Content";

        case 205:
            return "Reset Content";

        case 206:
            return "Partial Content";

        case 300:
            return "Multiple Choices";

        case 301:
            return "Moved Permanently";

        case 302:
            return "Found";

        case 303:
            return "See Other";

        case 304:
            return "Not Modified";

        case 305:
            return "Use Proxy";

        case 307:
            return "Temporary Redirect";

        case 400:
            return "Bad Request";

        case 401:
            return "Unauthorized";

        case 402:
            return "Payment Required";

        case 403:
            return "Forbidden";

        case 404:
            return "Not Found";

        case 405:
            return "Method Not Allowed";

        case 406:
            return "Not Acceptable";

        case 407:
            return "Proxy Authentication Required";

        case 408:
            return "Request Timeout";

        case 409:
            return "Conflict";

        case 410:
            return "Gone";

        case 411:
            return "Length Required";

        case 412:
            return "Precondition Failed";

        case 413:
            return "Request Entity Too Large";

        case 414:
            return "Request-URI Too Long";

        case 415:
            return "Unsupported Media Type";

        case 416:
            return "Requested Range Not Satisfiable";

        case 417:
            return "Expectation Failed";

        case 500:
            return "Internal Server Error";

        case 501:
            return "Not Implemented";

        case 502:
            return "Bad Gateway";

        case 503:
            return "Service Unavailable";

        case 504:
            return "Gateway Timeout";

        case 505:
            return "HTTP Version Not Supported";

        default:
            return "";

    }
}