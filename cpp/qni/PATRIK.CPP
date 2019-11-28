#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string s;

class myException:exception{

    string message;

    public:

        myException(string message){
            this->message = message;
        }

        string what(){
            return message;
        }

};

class Cpp{

    int number_of_people;
    string urok;
    vector<string> uroci;

    public :

        void print(){
            cout << number_of_people << endl;
        }

        Cpp(int number_of_people, string urok, vector<string> uroci){
            this->number_of_people = number_of_people;
            this->urok = urok;/* code */
            this->uroci = uroci;

        }

        void bal(){

            for (int i = 0; i < uroci.size(); i++){
                if(urok == uroci[i]) throw myException("tova veche sme go vzimali! \n");
            }
            
        }

        string toString(){

            ostringstream out;

            for (int i = 0; i < uroci.size(); i++){
                
                out << uroci[i] << " (baluk)\n";
            }

            //out >> s;
            
            return out.str();
            
            
        }
    
};

int main() {

    vector<string> uroci;
    uroci.push_back("constanti1");
    uroci.push_back("constanti2");
    uroci.push_back("constanti3");
    uroci.push_back("constanti4");
    uroci.push_back("constanti5");

    Cpp c(5, "constanti", uroci);
    try{
        c.bal();
    }catch(myException ex){
        cout << ex.what() << endl;
    }

    cout << c.toString() << endl;
    //c.number_of_people = 10;
}