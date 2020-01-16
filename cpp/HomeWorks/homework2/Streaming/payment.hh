#ifndef PAYMENT_HH
#define PAYMENT_HH
#include <string>
#include <vector>
#include "media.hh"

class payment{
    public:

    std::string date;
    std::vector< media* > used_medias;
    bool status;

    payment(std::string date, std::vector< media* > used_medias, bool status);
    double calculate_combined();

};

#endif