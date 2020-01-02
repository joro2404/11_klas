#ifndef SONG_HH
#define SONG_HH
#include "media.hh"

class song: public media{
    protected:

    int count;

    public:

    song(std::string title, std::string author, double price, int count);
    double calculate_price();
};

#endif