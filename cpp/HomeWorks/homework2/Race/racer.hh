#ifndef RACER_HH
#define RACER_HH
#include <string>

class Racer{
    protected:

    std::string name;
    int position;
    int speed;

    public:

    Racer(std::string name, int position, int speed);
    virtual void move() = 0;

};

#endif