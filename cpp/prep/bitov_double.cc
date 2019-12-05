#include "bitov_double.hh"

double bitov_double::calcBill(){
    
    return ((usedPowerDay*(rateDay + delivery_price + distribution_price)) + (usedPowerNight*(rateNight + delivery_price + distribution_price)));
}

bitov_double :: bitov_double(double usedPowerDay, double rateDay, double usedPowerNight, double rateNight, double delivery_price, double distribution_price){
    this->usedPowerDay = usedPowerDay;
    this->rateDay = rateDay;
    this->usedPowerNight = usedPowerNight;
    this->rateNight = rateNight;
    this->delivery_price = delivery_price;
    this->distribution_price = distribution_price;
}