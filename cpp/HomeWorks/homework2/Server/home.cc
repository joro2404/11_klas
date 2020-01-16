#include "home.hh"

response* home::handleRequest(request* req){

    response* res = new response(200, "<html>home</html>");

    return res;
}