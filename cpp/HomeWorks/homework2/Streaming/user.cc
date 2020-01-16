#include "user.hh"

user::user(std::string name, std::string email, std::vector< media* > history_medias, std::vector <payment > payments){
    this->name = name;
    this->email = email;
    this->history_medias = history_medias;
    this->payments = payments;
}