#include "material.hh"


Material::Material(std::string name, int quantity){
    this->name = name;
    this->quantity = quantity;

} //if we want time we just pass Materail(TIme, 1 hour)


Material::Material(std::string name, std::string meassure, int quantity){
    this->name = name;
    this->meassure = meassure;
    this->quantity = quantity;
}