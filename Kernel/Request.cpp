//
// Created by pedrosoares on 4/28/18.
//

#include <TigreFramework/Core/Kernel/Application/Configuration.h>
#include <TigreFramework/Core/Kernel/Application/Env.h>
#include <iostream>
#include <TigreFramework/String/String.h>
#include <zconf.h>
#include <TigreFramework/Core/Request/Exception/ParameterNotFound.h>
#include "Request.h"
#include "HttpCore.h"
#include "Exception.h"

std::string Request::urlDecode(std::string url) {
    std::string ret;
    char ch;
    int i, ii;
    for (i=0; i<url.length(); i++) {
        if (int(url[i])==37) {
            sscanf(url.substr(i+1,2).c_str(), "%x", &ii);
            ch=static_cast<char>(ii);
            ret+=ch;
            i=i+2;
        } else {
            ret+=url[i];
        }
    }
    return (ret);
}

Request::Request(std::map<std::string, std::string> header) : header(std::move(header)) {
    auto env = Configuration::Get<Env *>("env");
    auto core = Configuration::Get<HttpCore *>("Http.Core");

    //Initialize the Variable Method
    this->method = env->get( "REQUEST_METHOD", "GET" );

    //Initialize the Variable Method
    this->uri = env->get( "REQUEST_URI", "/" );

    {
        std::string post_tmp = core->getPostData();
        if(!post_tmp.empty()) {
            try {
                nlohmann::json json = nlohmann::json::parse(post_tmp);
                if (json.is_string()) {
                    // Separa as informações
                    std::vector<Tigre::String> array;
                    {
                        Tigre::String helper = post_tmp;
                        array = helper.explode("&");
                    }

                    for (int i = 0; i < array.size(); i++) {
                        //separar KEY do VALOR do POST
                        std::vector<Tigre::String> value;
                        {
                            Tigre::String helper = array[i];
                            value = helper.explode("=");
                        }

                        // Cria um Mapa de Vetor para armazenar temporariamente os valores
                        std::map<std::string, std::string> postTmp;

                        //verifica se o POST não está com o campo vazio
                        if (value.size() == 2) {
                            // Criar o KEY do vetor e seu VALOR para adicionar a variavel POST
                            postTmp[value[0].getValue()] = Request::urlDecode(value[1].getValue());
                        } else if (value.size() == 1) {
                            // Adiciona vazio para campo vazio.
                            postTmp[value[0].getValue()] = "";
                        } else {
                            // continua pois deu merda
                            continue;
                        }

                        // Adiciona o valor ao POST
                        this->post_form_data.push_back(postTmp);
                    }
                } else {
                    this->post_json = std::move(json);
                }
            } catch (...) {

            }
        }
    }
}

std::string Request::getUri() {
    return this->uri;
}

std::string Request::getMethod() {
    return this->method;
}

std::map<std::string, std::string> Request::getHeaders() {
    return this->header;
}

std::string Request::getHeader(std::string name) {
    return this->header[name];
}

std::string Request::get(std::string name, std::string default_value) {
    if(this->has(name)){
        return this->get(name);
    }
    return default_value;
}

std::string Request::get(std::string name) {
    if(!this->post_form_data.empty()){
        for( auto & data : this->post_form_data ){
            if(data.find(name) != data.end() && !data[name].empty()){
                return data[name];
            }
        }
    }
    if(!this->post_json[name].is_null()){
        auto value = this->post_json[name];
        if(value.is_number()){
            return std::to_string(value.get<double>());
        }else if( value.is_boolean() ){
            return std::to_string(value.get<bool>());
        }else if(!value.is_string()){
            return value.dump();
        }
        std::string string = value.get<std::string>();
        if(!string.empty()){
            return string;
        }
    }
    throw ParameterNotFound("Parameter ("+name+") Not Found!");
}

bool Request::has(std::string name) {
    /*if(get.size() > 0){
        for(int i = 0; i < get.size(); i++ ){
            if(get[i][name] != ""){
                return true;
            }
        }
    }*/
    if(!this->post_form_data.empty()){
        for( auto & data : this->post_form_data ){
            if(data.find(name) != data.end() && !data[name].empty()){
                return true;
            }
        }
    }
    return !this->post_json[name].is_null() && !this->post_json[name].empty();
}

nlohmann::json Request::all() {
    if(this->post_form_data.empty()){
        return this->post_json;
    }
    return this->post_form_data;
}
