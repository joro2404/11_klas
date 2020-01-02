#ifndef RACE_HH
#define RACE_HH
#include <vector>
#include "racer.hh"

class Race{

    protected:

    
    int lenght;
    int number_of_racers;
    std::vector< std::vector < Racer* > > race;
    public:

    Race(int lenght, int number_of_racers);

    void init_race(int lenght, int number_of_racers);

};
#endif