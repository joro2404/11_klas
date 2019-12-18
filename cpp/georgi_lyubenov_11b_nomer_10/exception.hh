#ifndef EXCEPTION_HH
#define EXCEPTION_HH
#include <string>

class OneExcepton{

    public:

        std::string message;

        OneExcepton(std::string);
        std::string what(std::string message);
};

#endif