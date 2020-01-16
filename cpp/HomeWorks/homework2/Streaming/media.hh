#ifndef MEDIA_HH
#define MEDIA_HH
#include <string>

class media{
    public:
    
    std::string author;
    double price;
    std::string title;

    media(std::string title, std::string author, double price);
    virtual double calculate_price() = 0;
};

#endif