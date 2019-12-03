#include <iostream>
#include <string>
using namespace std;

class Electronics{
    
    public:

        string type[100];
        string additional_info[256];
        Electronics(string type, string additional_info){

            type = type;
            additional_info = additional_info;
        }
          
};