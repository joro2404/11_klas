#ifndef THIRD_HH
#define THIRD_HH
#include "racer.hh"

class third: public Racer{
    public:

    third(std::string name, int position, int speed);
    void move();
};

#endif