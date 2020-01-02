#include "song.hh"

double song::calculate_price(){

    return (double)count*price;
}
song::song(std::string title, std::string author, double price, int count): media(title, author, price){
    this->count = count;
}