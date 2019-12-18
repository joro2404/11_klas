#include "auto_service.hh"
#include "machine.hh"
#include "part.hh"
#include "client.hh"
#include "service.hh"
#include "order.hh"
#include "exception.hh"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int AutoService::add_order(std::vector<Order> orders, const Order& order){

    vector<Order> help = get_active_orders(orders);
    if(order.forCar != onCar)throw OneExcepton("the orders is for cars, but the service doesnt work on cars!\n");
    if(order.forBike != onBike)throw OneExcepton("the order is on bike, but the services doesnt work on bikes");

    if(capacity < help.size()){
        orders.push_back(order);
        return 1;
    }

    throw OneExcepton("there is no speace in the auto_service");
    return 0;
}


vector<Order> AutoService::get_all_for_client(std::vector<Order> orders, const Client& client){

    vector<Order> help;
    for (int i = 0; i < orders.size(); i++){
        if(orders[i].client_id == client.id){
            help.push_back(orders[i]);
        }
    }

    return help;
    
}
vector<Order> AutoService::get_all_for_machine(std::vector<Order> orders, const Machine& machine){

    vector<Order> help;

    for (int i = 0; i < orders.size(); i++){
        if(orders[i].machine_serial_number == machine.serial_number){
            help.push_back(orders[i]);
        }
    }

    return help;
    
}


void AutoService::get_infor_for_order(const Order& order){

    cout << order.name_of_order << endl;
    cout << order.final_price << endl;
    cout << order.forCar << endl;
    cout << order.finished << endl;
    cout << order.client_id << endl;
    cout << order.machine_serial_number << endl;

    for (int i = 0; i < order.parts_neeeded.size(); i++){
        
        cout << order.parts_neeeded[i].name << endl;
    }
    
    //moje i po krasivo da e no nqma vreme :)
}

vector<Order> AutoService::get_active_orders(std::vector<Order> orders){

    vector<Order> help;

    for (int i = 0; i < orders.size(); i++){
        if(orders[i].finished == false){
            help.push_back(orders[i]);
        }
    }

    return help;
}
