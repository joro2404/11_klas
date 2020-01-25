#include "clothing.hh"

Clothing::Clothing(std::string name, float price, bool in_stock, Supplier* supplier, int delivery_time, std::string color, std::string size, std::string material):Item(name, price, in_stock, supplier, delivery_time){
    this->color = color;
    this->size = size;
    this->material = material;
}