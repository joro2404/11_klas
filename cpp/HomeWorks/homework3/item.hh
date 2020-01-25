#ifndef ITEM_HH
#define ITEM_HH
#include <string>
#include "supplier.hh"

class Item{

    public:
        std::string name;
        float price;
        bool in_stock;
        Supplier* supplier;
        int delivery_time;

    
        Item(std::string name, float price, bool in_stock, Supplier* supplier, int delivery_time);

        
};

#endif