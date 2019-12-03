#include <iostream>
#include <string>
using namespace std;

class Electronics{
    
    public:

        string type[100];
        string warranty_date[100];
        string warranty_conditions[256];

        Electronics(string type, string warranty_date, string warranty_conditions){

            type = type;
            warranty_date = warranty_date;
            warranty_conditions = warranty_conditions;
        }
          
};