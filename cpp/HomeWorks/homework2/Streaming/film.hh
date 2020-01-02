#ifndef FILM_HH
#define FILM_HH
#include "media.hh"

class film: public media{
    protected:

    int minutes;

    public:

    film(std::string title, std::string author, double price, int minutes);
    double calculate_price();
};

#endif