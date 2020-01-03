#ifndef SECOND_HH
#define SECOND_HH
#include <vector>
#include "racer.hh"

class second: public Racer{
    public:

    second(std::string name, int position, int speed);
    void move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions);
};

#endif