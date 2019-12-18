#ifndef ORDER_HH
#define ORDER_HH
#include "machine.hh"
#include "service.hh"
#include <string>

class Order: public Service{

    public:

        std::string name_of_order;
        float final_price;
        bool finished;
        int client_id;
        int machine_serial_number;

};

#endif