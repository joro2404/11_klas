#ifndef USER_HH
#define USER_HH
#include <string>

class User{
    public:
        int id;
        std::string name;
        std::string password;

        User(int id, std::string name, std::string passowrd);

};

#endif