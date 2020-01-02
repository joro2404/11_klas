#include "third.hh"
#include "racer.hh"

void third::move(){

    position -= 1;
}

third::third(std::string name, int position, int speed): Racer(name, position, speed){}