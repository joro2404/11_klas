#include "clothing.hh"
#include "tech.hh"
#include "store.hh"
#include <iostream>
using namespace std;

int main(){

    User mario(1, "Mario", "shte pisha 6 na N10 11b klas ;)");
    User georgi(2, "Georgi", "Java > C++");
    User mitko(3, "Mitko", "???");

    Supplier comet("comet");
    Supplier elimex("elimex");
    Supplier tremol("tremol"); 

    Tech fridge("fridge", 100, true, &comet, 4, "white tech", 4, 45);
    Tech tv("tv", 250.5, true, &elimex, 10, "relax & entarteiment", 10, 30);
    Tech smartphone("Iphone 11 pro", 2400, true, &tremol, 6, "gadgets", 2, 0.33);

    Clothing jacket("jacket", 73.50, true, &comet, 3, "black", "M", "leather");
    Clothing panths("panths", 30.33, true, &elimex, 5, "blue", "L", "denim");
    Clothing shirt("shirt", 55.5, true, &tremol, 8, "red & black", "S", "cotton");

    Clothing extra("extra", 15.5, true, &tremol, 8, "hello", "t", "to be added");

    vector <int> quantity;
    for (int i = 0; i < 3; i++){
        quantity.push_back(1);
    }

    vector <Item> techs;
    techs.push_back(fridge);
    techs.push_back(tv);
    techs.push_back(smartphone);
    
    vector <Item> cloths;
    cloths.push_back(jacket);
    cloths.push_back(panths);
    cloths.push_back(shirt);

    Order order1(1, &mario, techs, quantity, "New");
    Order order2(2, &georgi, cloths, quantity, "New");

    order2.add_item(&extra);
    cout << order2.quantity.size() << " ";
    for (int i = 0; i < order2.ordered_items.size(); i++){
        cout << order2.ordered_items[i].name << " ";
    }
    cout << endl;

    vector <User> users;
    users.push_back(mario);
    users.push_back(georgi);
    // users.push_back(mitko);

    vector <Item> items; 
    items.push_back(fridge);
    items.push_back(tv);
    items.push_back(smartphone);
    
    items.push_back(jacket);
    items.push_back(panths);
    items.push_back(shirt);

    vector <int> q;
    for (int i = 0; i < items.size(); i++){
        q.push_back(10);
    }

    vector <Order> orders;
    orders.push_back(order1);
    orders.push_back(order2);

    Store tues(users, items, orders);
    
    tues.add_user(mitko);
    for (int i = 0; i < tues.users.size(); i++){
        cout << tues.users[i].name << " ";
    }
    cout << endl;

    tues.add_item(extra);
    for (int i = 0; i < tues.items.size(); i++){
        cout << tues.items[i].name << " ";
    }
    cout << endl;

    //za drugite nqma vreme da pokazvam rabota ama i tva e neshto :)
    

    return 1;
}