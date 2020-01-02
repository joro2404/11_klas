#ifndef GAME_HH
#define GAME_HH
#include "media.hh"

class game: public media{
    protected:

    int hours;

    public:

    game(std::string title, std::string author, double price, int minutes);
    double calculate_price();
};

#endif