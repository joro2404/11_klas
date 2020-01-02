#ifndef PAYMENT_HH
#define PAYMENT_HH
#include <string>
#include <vector>
#include "media.hh"
;
class payment{
    protected:

    std::string date;
    std::vector< media > used_medias;
    bool status;

    public:

    payment(std::string date, std::vector< media > used_medias, bool status);
    double calculate_combined();

};

#endif