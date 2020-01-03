#include "race.hh"
#include "racer.hh"

Race::Race(int lenght, int number_of_racers, std::vector < Racer* > racers, std::vector< std::vector < Racer* > > race){
    this->lenght = lenght;
    this->number_of_racers = number_of_racers;
    
    for (int i = 0; i < number_of_racers; i++) {
        this->race.push_back(std::vector<Racer*>());
        for (int j = 0; j < lenght; j++) {
            this->race[i].push_back(NULL);
        }
        this->race[i][0] = racers[i];
    }
}
