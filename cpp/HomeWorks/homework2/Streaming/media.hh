#ifndef MEDIA_HH
#define MEDIA_HH
#include <string>

class media{
    protected:

    std::string title;
    std::string author;
    double price;

    public:

    media(std::string title, std::string author, double price);
    virtual double calculate_price() = 0;
};

#endif