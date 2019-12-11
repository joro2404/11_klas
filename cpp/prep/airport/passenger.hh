#ifndef PASSENGER_HH
#define PASSENGER_HH
#include "core.hh"

class passenger: public core {
    public:
        int passengers;
        int seats;
        int exits;
};

#endif