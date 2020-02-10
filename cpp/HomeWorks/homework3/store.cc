#include "store.hh"

Store::Store(std::vector <User> users, std::vector <Item> items, std::vector <Order> orders){
    this->users = users;
    this->items = items;
    this->orders = orders;
}

void Store::add_user(User const& user){
    for (int i = 0; i < this->users.size(); i++){
        if(this->users[i].id == user.id)throw Exception ("User already exists!");
    }
    
    this->users.push_back(user);
}

void Store::add_item(Item const& item){
    this->items.push_back(item);
}

void Store::create_order(Order const& Order){
    
    
    for (int i = 0; i < this->orders.size(); i++){
        if(this->orders[i].id == Order.id)throw Exception("Order already exists!");
    }

    int check = 0;
    for (int i = 0; i < this->users.size(); i++){
        if(this->users[i].id == Order.user->id)check++;
    }
    if(check == 0)throw Exception("Order with none existing user!");
    
    

    for (int i = 0; i < Order.ordered_items.size(); i++){
        for (int j = 0; j < this->items.size(); j++){
            if(Order.ordered_items[i].name == this->items[j].name){
                if(this->quantity[j] < Order.quantity[i])throw Exception("Not enough of this item in the store!");
                this->quantity[j] -= Order.quantity[i];
            }
        }   
    }
    
    this->orders.push_back(Order);
}

std::pair <double, unsigned int> Store::accept_order(unsigned int order_id){

    std::pair <double, unsigned int> result;
    int index;

    int check = 0;
    for (int i = 0; i < this->orders.size(); i++){
        if(this->orders[i].id == order_id) check++;
    }
    if(check == 0)throw Exception("Order doesn't exists!");
    
    for (int i = 0; i < this->orders.size(); i++){
        if(this->orders[i].id == order_id){
            if(this->orders[i].status != "New" )throw Exception("This order is being processed!");
        }
    }
    

    for (int i = 0; i < this->orders.size(); i++){
        if(this->orders[i].id == order_id){
            this->orders[i].status = "Accepted from store";
            index = i;
        }
    }

    result.second = this->orders[index].ordered_items[0].delivery_time;
    for (int i = 0; i < this->orders[index].ordered_items.size(); i++){
        result.first += this->orders[index].ordered_items[i].price;
        if(this->orders[index].ordered_items[i].delivery_time > result.second)result.second = this->orders[index].ordered_items[i].delivery_time;
    }
    
    return result;
}size_t

void Store::send_order(unsigned int order_id){

    int check = 0;
    for (int i = 0; i < this->orders.size(); i++){
        if(this->orders[i].id == order_id) check++;
    }
    if(check == 0)throw Exception("Order doesn't exists!");

    for (int i = 0; i < this->orders.size(); i++){
        if(this->orders[i].id == order_id){
            if(this->orders[i].status != "New" )throw Exception("This order is being processed!");
        }
    }

    for (int i = 0; i < this->orders.size(); i++){
        if(orders[i].id == order_id){
            orders[i].status = "Sended";
        }
    }
    
}


std::vector <Order const*> Store::get_orders_by_user(unsigned int user_id) const{

    std::vector <Order const*> result;

    int check = 0;
    for (int i = 0; i < this->users.size(); i++){
        if(this->users[i].id == user_id)check++;
    }
    if(check == 0)throw Exception("User doest exists!");

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