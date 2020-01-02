#ifndef BOOK_HH
#define BOOK_HH
#include "media.hh"

class book: public media{
    public:

    book(std::string title, std::string author, double price);
    double calculate_price();
};

#endif