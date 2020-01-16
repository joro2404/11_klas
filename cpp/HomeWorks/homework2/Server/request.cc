#include "request.hh"

request::request(std::string ip, std::string route){
    this->ip = ip;
    this->route = route;
}

request::request(std::string ip, std::string route,  std::vector < std::string > additionla_arguments){
    this->ip = ip;
    this->route = route;
    this->additionla_arguments = additionla_arguments;
}