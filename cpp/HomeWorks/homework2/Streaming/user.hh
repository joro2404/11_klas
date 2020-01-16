#ifndef USER_HH
#define USER_HH
#include <string>
#include "media.hh"
#include "payment.hh"

class user{
    public:

    std::string name;
    std::string email;
    std::vector< media* > history_medias;
    std::vector < payment > payments;


    user(std::string name, std::string email, std::vector< media* > history_medias, std::vector < payment > payments);

};

#endif