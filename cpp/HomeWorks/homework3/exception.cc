#include "exception.hh"

Exception::Exception(std::string message){
    this->message = message;
}

std::string Exception::what(){
    return message;
}