#include "book.hh"

double book::calculate_price(){

    return price;
}

book::book(std::string title, std::string author, double price): media(title, author, price){}