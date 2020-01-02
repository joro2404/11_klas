#include "game.hh"

double game::calculate_price(){

    return (double)hours*price;
}

game::game(std::string title, std::string author, double price, int hours): media(title, author, price){
    this->hours = hours;
}