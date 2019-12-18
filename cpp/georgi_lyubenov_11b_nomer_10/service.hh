#ifndef SERVICE_HH
#define SERVICE_HH
#include "part.hh"
#include <string>
#include <vector>

class Service: public Part{

    public:

        std::vector<Part> parts_neeeded;

};

#endif