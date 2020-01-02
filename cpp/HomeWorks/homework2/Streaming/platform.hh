#ifndef PLATFORM_HH
#define PLATFORM_HH
#include <vector>
#include "media.hh"
#include "user.hh"

class platform{
    protected:
    std::vector< user > users;
    std::vector< media > available_medias;

};

#endif