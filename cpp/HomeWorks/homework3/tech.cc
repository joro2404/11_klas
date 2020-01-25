#include "tech.hh"

Tech::Tech(std::string name, float price, bool in_stock, Supplier* supplier, int delivery_time, std::string type, int warranty, int weight):Item(name, price, in_stock, supplier, delivery_time){
    this->type = type;
    this->warranty = warranty;
    this->weight = weight;
}