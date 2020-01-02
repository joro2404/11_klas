#ifndef SECOND_HH
#define SECOND_HH
#include "racer.hh"

class second: public Racer{
    public:

    second(std::string name, int position, int speed);
    void move();
};

#endif