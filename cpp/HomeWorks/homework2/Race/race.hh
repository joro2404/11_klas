#ifndef RACE_HH
#define RACE_HH
#include <vector>
#include "racer.hh"

class Race{

    public:

    int lenght;
    int number_of_racers;
    std::vector< std::vector < Racer* > > race;
    

    Race(int lenght, int number_of_racers, std::vector < Racer* > racers, std::vector< std::vector < Racer* > > race);


};

#endif