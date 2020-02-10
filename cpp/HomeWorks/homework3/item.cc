#include "item.hh"

Item::Item(std::string name, double price, bool in_stock, Supplier* supplier, int delivery_time){

    this->name = name;
    this->price = price;
    this->in_stock = in_stock;
    this->supplier = supplier;
    this->delivery_time = delivery_time;
}