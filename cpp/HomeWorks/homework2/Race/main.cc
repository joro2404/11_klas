#include<vector>
#include <iostream>
#include "race.hh"
#include "racer.hh"
#include "first.hh"
#include "second.hh"
#include "third.hh"
using namespace std;

// ideqta mi e kogato dvama sustezateli se blusnat i dvamata da igarqt toest i dvamata stavat NULL

int main(){


    first racer1("Mario", 0, 3);
    first racer2("Gosho", 0, 1);
    first racer3("Mitko", 0, 2);
    first racer4("Az", 0, 5);

    std::vector < Racer* > racers;
    racers.push_back(&racer1);
    racers.push_back(&racer2);
    racers.push_back(&racer3);
    racers.push_back(&racer4);

    std::vector< std::vector < Racer* > > race;

    Race rally(10, 4, racers, race);

    std::vector <std::string> positions;

    while(positions.size() < 3){
        racer1.move(race, positions);
        racer2.move(race, positions);
        racer3.move(race, positions);
        racer4.move(race, positions);
    }

    cout << "Winner is -> " << positions[0] << endl;
    cout << "Runner up -> " << positions[1] << endl;
    cout << "3rd place -> " << positions[2] << endl;
    
}
