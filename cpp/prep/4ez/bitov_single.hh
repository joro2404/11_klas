#ifndef BITOV_SINGLE_HH
#define BITOV_SINGLE_HH
#include "bitov.hh"

class bitov_single: public bitov{
    public:
        double usedPower;
        double rate;

        bitov_single(double usedPower, double rate, double delivery_price, double distribution_price);
        double calcBill();
};

#endif