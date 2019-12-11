#ifndef NON_BITOV_SINGLE_HH
#define NON_BITOV_SINGLE_HH
#include "non_bitov.hh"

class non_bitov_single: public non_bitov{
    public:
        double usedPower;
        double rate;

        non_bitov_single(double usedPower, double rate, double delivery_price, double distribution_price, double high_voltage);
        double calcBill();
};

#endif