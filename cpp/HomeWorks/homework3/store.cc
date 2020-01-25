#include "store.hh"

Store::Store(std::vector <User> users, std::vector <Item> items, std::vector <Order> orders){
    this->users = users;
    this->items = items;
    this->orders = orders;
}

void Store::add_user(User const& user){
    this->users.push_back(user);
}

void Store::add_item(Item const& item){
    this->items.push_back(item);
}

void Store::create_order(Order const& Order){
    for (int i = 0; i < Order.ordered_items.size(); i++){
        for (int j = 0; j < this->items.size(); j++){
            if(Order.ordered_items[i].name == this->items[j].name){
                this->quantity[j] -= Order.quantity[i];
            }
        }   
    }
    
    this->orders.push_back(Order);
}

void Store::send_order(unsigned int order_id){
    for (int i = 0; i < this->orders.size(); i++){
        if(orders[i].id == order_id){
            orders[i].status = "Sended";
        }
    }
    
}


std::vector <Order const*> Store::get_orders_by_user(unsigned int user_id) const{

    std::vector <Order const*> result;

    for (int i = 0; i < this->orders.size(); i++){
        if(this->orders[i].user->id == user_id){
            result.push_back(&this->orders[i]);
        }
    }

    return result;
}

std::vector <Item const*> Store::get_items_by_supplier(Supplier const& supplier) const{

    std::vector <Item const*> result;

    for (int i = 0; i < this->orders.size(); i++){
        if(this->items[i].supplier->name == supplier.name){
            result.push_back(&this->items[i]);
        }
    }

    return result;
    
}