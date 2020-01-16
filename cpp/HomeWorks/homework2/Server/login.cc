#include "login.hh"
#include "users.hh"


response* login::handleRequest(request* req){

    for (int i = 0; i < users::names.size(); i++){
        
        if(users::names[i][0] == req->additionla_arguments[0] && users::names[i][1] == req->additionla_arguments[1]){

            response* res = new response(200, "OK");
            return res;
        }
        
    }
    
    response* res = new response(403, "Unauthorized");

    return res;
}