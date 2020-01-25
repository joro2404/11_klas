#ifndef ORDER_HH
#define ORDER_HH
#include "user.hh"
#include "item.hh"
#include <vector>

class Order{
    public:
        int id;
        User* user;
        std::vector <Item> ordered_items;
        std::vector <int> quantity;
        std::string status;

    
        Order(int id, User* user, std::vector <Item> ordered_items, std::vector <int> quantity, std::string status);

        void add_item(Item item);


};

#endif