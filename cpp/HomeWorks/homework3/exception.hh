#ifndef EXCEPTION_HH
#define EXCEPTION_HH
#include <string>


class Exception{

    std::string message;

    public:

        Exception(std::string message);
        std::string what();
};

#endif