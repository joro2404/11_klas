#include "bitov_single.hh"

double bitov_single::calcBill(){
    
    return usedPower * (rate + distribution_price + delivery_price);
}


bitov_single :: bitov_single(double usedPower, double rate, double delivery_price, double distribution_price){

    this->usedPower = usedPower;
    this->rate = rate;
    this->delivery_price = delivery_price;
    this->distribution_price = distribution_price;
}