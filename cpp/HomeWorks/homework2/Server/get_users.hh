#ifndef GET_USERS_HH
#define GET_USERS_HH
#include <string>
#include <vector>
#include "object.hh"

class get_users: public object {
    public:

    response* handleRequest(request* req);
};

#endif