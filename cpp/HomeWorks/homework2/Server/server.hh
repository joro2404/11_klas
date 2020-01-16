#ifndef SERVER_HH
#define SERVER_HH
#include <vector>
#include <string>
#include "object.hh"

class server {
    public:

    std::vector< std::string > routes;
    std::vector< object* > objects;
    
    server(std::vector< std::string > routes, std::vector< object* > objects);
    response* routeRequest(request* req);

};

#endif