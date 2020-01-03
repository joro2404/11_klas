#ifndef FIRST_HH
#define FIRST_HH
#include <vector>
#include "racer.hh"

class first: public Racer{
    public:

    first(std::string name, int position, int speed);
    void move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions);

};

#endif