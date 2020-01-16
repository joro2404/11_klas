#include "platform.hh"
#include "media.hh"
#include "user.hh"
#include "payment.hh"

platform::platform(std::vector< user > users, std::vector< media* > available_medias){
    this->users = users;
    this->available_medias = available_medias;
}

std::vector< user > platform::get_all_users(){
    return users;
}

std::vector <payment > platform::get_payments(user user){
    return user.payments;
}

void platform::make_payment(user user, std::string date_of_payment){
    std::vector <payment > payments = get_payments(user);

    for (int i = 0; i < payments.size(); i++){
        if(date_of_payment == payments[i].date && payments[i].status == false){
            payments[i].status = true;
        }
    }
    
}

std::vector < media* > platform::serach_by_title(std::string title, std::vector< media* > available_medias){
    std::vector < media* > result;
    
    for (int i = 0; i < available_medias.size(); i++){
        
        if(title == available_medias[i]->title){
            result.push_back(available_medias[i]);
        }
    }
    
    return result;
}