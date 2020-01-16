#include "request.hh"
#include "response.hh"
#include "object.hh"
#include "server.hh"
#include "home.hh"
#include "login.hh"
#include "users.hh"
#include "get_users.hh"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {

    home home;
    login login;
    get_users get_users;

    std::vector< object* > objects;
    objects.push_back(&home);
    objects.push_back(&login);
    objects.push_back(&get_users);


    std::vector< std::string > routes;
    routes.push_back("/home.html");
    routes.push_back("/api/login");
    routes.push_back("/api/get_users");

    server server(routes, objects);

    std::vector < std::string > additionla_arguments1;
    additionla_arguments1.push_back("Mario");
    additionla_arguments1.push_back("dulgo-doamshno");

    std::vector < std::string > additionla_arguments2;
    additionla_arguments2.push_back("Gosho");
    additionla_arguments2.push_back("dulgo-doamshno");

    request request1("1", "/home.html");
    request request2("2", "/api/login", additionla_arguments1);
    request request3("3", "/api/login", additionla_arguments2);
    request request4("4", "/api/get_users");
    request request5("5", "/login.html");

    response* test1 = server.routeRequest(&request1);
    response* test2 = server.routeRequest(&request2);
    response* test3 = server.routeRequest(&request3);
    response* test4 = server.routeRequest(&request4);
    response* test5 = server.routeRequest(&request5);

    cout << test1->status  << "  " << test1->text << endl;
    cout << test2->status << "  " << test2->text << endl;
    cout << test3->status << "  " << test3->text << endl;
    cout << test4->status << "  " << test4->text << endl;
    cout << test5->status << "  " << test5->text << endl;
}