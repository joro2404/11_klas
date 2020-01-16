#include "media.hh"
#include "user.hh"
#include "payment.hh"

payment::payment(std::string date, std::vector< media* > used_medias, bool status){
    this->date = date;
    this->used_medias = used_medias;
    this->status = status;
}

double payment::calculate_combined(){
    double result = 0;
    for (int i = 0; i < used_medias.size(); i++){
        result += used_medias[i]->calculate_price();
    }

    return result;
}