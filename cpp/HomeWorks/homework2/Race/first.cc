#include "first.hh"
#include "racer.hh"

void first::move(){

    position += speed;
}

first::first(std::string name, int position, int speed): Racer(name, position, speed){}