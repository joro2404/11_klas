#ifndef AUTO_SERVICE_HH
#define AUTO_SERVICE_HH
#include "machine.hh"
#include "part.hh"
#include "client.hh"
#include "service.hh"
#include "order.hh"

#include <vector>
#include <string>

class AutoService{

    public:

        std::vector<Client> clients;
        std::vector<Part> parts;
        std::vector<Service> services;
        std::vector<Machine> machines;
        std::vector<Order> orders;
        bool onCar;
        bool onBike;
        int capacity;

        int add_order(std::vector<Order> orders, const Order& order);
        std::vector<Order> get_all_for_client(std::vector<Order> orders, const Client& client);
        std::vector<Order> get_all_for_machine(std::vector<Order> orders, const Machine& machine);
        void get_infor_for_order(const Order& order);
        std::vector<Order> get_active_orders(std::vector<Order> orders);
};

#endif