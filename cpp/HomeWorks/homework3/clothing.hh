#ifndef CLOTHING_HH
#define CLOTHING_HH
#include "item.hh"

class Clothing:Item{
    public:
        std::string color;
        std::string size;
        std::string material;

    
        Clothing(std::string name, float price, bool in_stock, Supplier* supplier, int delivery_time, std::string color, std::string size, std::string material);

};

#endif