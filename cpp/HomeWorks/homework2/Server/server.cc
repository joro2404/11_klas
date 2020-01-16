#include "server.hh"

server::server(std::vector< std::string > routes, std::vector< object* > objects){
    this->routes = routes;
    this->objects = objects;
}

response* server::routeRequest(request* req){


    for (int i = 0; i < routes.size(); i++){
        if(routes[i] == req->route){
            return objects[i]->handleRequest(req);
        }
    }
    
    response* res = new response(404, "Route Not Found!");
    return res;
}