#include "film.hh"

double film::calculate_price(){

    return (double)minutes*price;
}

film::film(std::string title, std::string author, double price, int minutes): media(title, author, price){
    this->minutes = minutes;
}