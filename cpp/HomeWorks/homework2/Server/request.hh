#ifndef REQUEST_HH
#define REQUEST_HH
#include <string>
#include <vector>

class request {
    public:

    std::string ip;
    std::string route;
    std::vector < std::string > additionla_arguments;

    request(std::string ip, std::string route);
    request(std::string ip, std::string route, std::vector < std::string > additionla_arguments);
};

#endif