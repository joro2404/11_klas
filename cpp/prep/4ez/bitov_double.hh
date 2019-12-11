#ifndef BITOV_DOUBLE_HH
#define BITOV_DOUBLE_HH
#include "bitov.hh"

class bitov_double: public bitov{
    public:
        double usedPowerDay;
        double usedPowerNight;
        double rateDay;
        double rateNight;

        bitov_double(double usedPowerDay, double rateDay, double usedPowerNight, double rateNight, double delivery_price, double distribution_price);
        double calcBill();
};

#endif