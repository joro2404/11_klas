#ifndef THIRD_HH
#define THIRD_HH
#include <vector>
#include "racer.hh"

class third: public Racer{
    public:

    third(std::string name, int position, int speed);
    void move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions);
};

#endif