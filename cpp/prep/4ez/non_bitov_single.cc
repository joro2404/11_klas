#include "non_bitov_single.hh"

double non_bitov_single :: calcBill(){

    return usedPower * (rate + distribution_price + delivery_price + high_voltage);
}

non_bitov_single :: non_bitov_single(double usedPower, double rate, double delivery_price, double distribution_price, double high_voltage){
    this-> usedPower = usedPower;
    this->rate = rate;
    this->delivery_price = delivery_price;
    this -> distribution_price = distribution_price;
    this->high_voltage = high_voltage;

}
