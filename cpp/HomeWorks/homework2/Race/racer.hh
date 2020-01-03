#ifndef RACER_HH
#define RACER_HH
#include <vector>
#include <string>

class Racer{
    public:

    std::string name;
    int position;
    int speed;

    Racer(std::string name, int position, int speed);
    virtual void move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions) = 0;

};

#endif