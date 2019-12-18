#ifndef CAR_HH
#define CAR_HH
#include "machine.hh"
#include <string>

class Car: public Machine{

    public:

        std::string type_of_fuel;

};

#endif