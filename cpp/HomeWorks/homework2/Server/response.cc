#include "response.hh"

response::response(int status, std::string text){
    this->status = status;
    this->text = text;

}