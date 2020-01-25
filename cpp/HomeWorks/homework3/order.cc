#include "order.hh"

Order::Order(int id, User* user, std::vector <Item> ordered_items, std::vector <int> quantity, std::string status){
    this->id = id;
    this->user = user;
    this->ordered_items = ordered_items;
    this->quantity = quantity;
    this->status = status;
}

void Order::add_item(Item item){
    int check = 0;

    for (int i = 0; i < this->ordered_items.size(); i++){
        if(ordered_items[i].name == item.name){
            this->quantity[i]++;
            check++;
        }
    }

    if(check > 0){
        this->ordered_items.push_back(item);
        this->quantity.push_back(1);
    }
    
}