#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    string data = "ke 3.1415 2ke";

    istringstream in(data);

    double pi;
    in.ignore(2);
    in >> pi;

    if(in.good()){

        cout << "Everything is OK " << endl;
        cout << "pi: " << pi << endl;
    }else {
        cout << "Something went wrong" << endl;
    }

    int number;
    in >> number;

    if(in.good()){

        cout << "Everything is OK" << endl;
        cout << "number: " << number << endl;
    } else {

        cout << "Something went wrong" << endl;
    }
}