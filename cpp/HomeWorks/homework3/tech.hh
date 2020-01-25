#ifndef TECH_HH
#define TECH_HH
#include "item.hh"

class Tech:public Item{

    public:

        std::string type;
        int warranty;
        int weight;

        Tech(std::string name, float price, bool in_stock, Supplier* supplier, int delivery_time, std::string type, int warranty, int weight);
};

#endif