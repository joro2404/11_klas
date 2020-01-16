#ifndef HOME_HH
#define HOME_HH
#include <string>
#include <vector>
#include "object.hh"

class home: public object {
    public:

    response* handleRequest(request* req);
};

#endif