#ifndef NON_BITOV_DOUBLE_HH
#define NON_BITOV_DOUBLE_HH
#include "non_bitov.hh"

class non_bitov_double: public non_bitov{
    public:
        double high_voltage;
        double usedPowerDay;
        double usedPowerNight;
        double rateDay;
        double rateNight;

        non_bitov_double(double usedPowerDay, double rateDay, double usedPowerNight, double rateNight, double delivery_price, double distribution_price, double high_voltage);
        double calcBill();
};

#endif