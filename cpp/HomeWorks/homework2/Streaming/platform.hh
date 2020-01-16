#ifndef PLATFORM_HH
#define PLATFORM_HH
#include <vector>
#include "media.hh"
#include "user.hh"
#include "payment.hh"
#include <string>
#include <string.h>

class platform{
    protected:
    std::vector< user > users;
    std::vector< media* > available_medias;

    public:

    platform(std::vector< user > users, std::vector< media* > available_medias);
    std::vector< user > get_all_users();
    std::vector < payment > get_payments(user user);
    void make_payment(user user, std::string date_of_payment);
    std::vector < media* > serach_by_title(std::string title, std::vector< media* > available_medias);
};

#endif