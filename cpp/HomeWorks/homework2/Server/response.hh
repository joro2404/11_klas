#ifndef RESPONSE_HH
#define RESPONSE_HH
#include <string>
#include <vector>

class response {
    public:

    int status;
    std::string text;

    response(int status, std::string text);
};

#endif