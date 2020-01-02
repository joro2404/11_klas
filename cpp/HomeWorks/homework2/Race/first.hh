#ifndef FIRST_HH
#define FIRST_HH
#include "racer.hh"

class first: public Racer{
    public:

    first(std::string name, int position, int speed);
    void move();

};

#endif