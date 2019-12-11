#include "non_bitov_double.hh"

double non_bitov_double :: calcBill(){

    return usedPowerNight * (rateNight + distribution_price + delivery_price + high_voltage) + usedPowerDay * (rateDay + distribution_price + delivery_price + high_voltage);
}

non_bitov_double :: non_bitov_double(double usedPowerDay, double rateDay, double usedPowerNight, double rateNight, double delivery_price, double distribution_price, double high_voltage){

    this-> usedPowerDay = usedPowerDay;
    this->rateDay = rateDay;
    this->usedPowerNight = usedPowerNight;
    this->rateNight = rateNight;
    this->delivery_price = delivery_price;
    this->distribution_price = distribution_price;
    this->high_voltage = high_voltage;
}
