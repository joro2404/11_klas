#include "get_users.hh"
#include "users.hh"

response* get_users::handleRequest(request* req){
    std::string result;
    result.append("[");

    for (int i = 0; i < users::names.size(); i++){
        result.append(users::names[i][0]);
        if(i != users::names.size()-1)result.append(", ");
    }
    result.append("]");
    

    response* res = new response(200, result);
    return res;
}