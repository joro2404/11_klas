#ifndef LOGIN_HH
#define LOGIN_HH
#include <string>
#include <vector>
#include "object.hh"

class login: public object {
    public:

    response* handleRequest(request* req);
};

#endif