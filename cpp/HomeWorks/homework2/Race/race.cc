#include "race.hh"
#include "racer.hh"

Race::Race(int lenght, int number_of_racers){
    this->lenght = lenght;
    this->number_of_racers = number_of_racers;
}

void Race::init_race(int lenght, int number_of_racers){
    for (int i = 0; i < number_of_racers; i++){

        for (int j = 0; i < lenght; j++){
            race[i].push_back(NULL);
        }
        
    }
}
