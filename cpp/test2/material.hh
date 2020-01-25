#ifndef MATERIAL_HH
#define MATERIAL_HH
#include <string>
#include <vector>

class Material {

    public:
        std::string name;
        std::string meassure;
        int quantity;
        

        Material(std::string name, int quantity); //if we want time we just pass Materail(TIme, 1 hour)
        Material(std::string name, std::string meassure, int quantity);
};

#endif