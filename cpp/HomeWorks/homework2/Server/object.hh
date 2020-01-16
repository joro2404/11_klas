#ifndef OBJECT_HH
#define OBJECT_HH
#include <string>
#include <vector>
#include "response.hh"
#include "request.hh"

class object {
    public:

    virtual response* handleRequest(request* req) = 0;
};

#endif