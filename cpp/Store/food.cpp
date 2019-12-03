#include <iostream>
#include <string>
using namespace std;

class Food{
    
    public:

        string type[100];
        string expiration_date[100];
        string alergens[256];
        bool BDS;

        Food(string type, string expiration_date, string alergens, bool BDS){

            type = type;
            expiration_date = expiration_date;
            alergens = alergens;
            BDS = BDS;
        }
          
};