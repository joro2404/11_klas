#ifndef LOAD_HH
#define LOAD_HH
#include "core.hh"

class load: public core {
    public:
        int current_load;
        int max_load;
};

#endif