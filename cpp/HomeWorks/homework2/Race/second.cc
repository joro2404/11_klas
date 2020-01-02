#include "second.hh"
#include "racer.hh"

void second::move(){

    position += 2 + speed;
}

second::second(std::string name, int position, int speed): Racer(name, position, speed){}