#include <iostream>
#include <string>

using namespace std;

int main() {

    // string firstName;
    // string lastName;

    // cout << "Enter first name: " << endl;
    // cin >> firstName;
    // cout << "enter last name: " << endl;
    // cin >> lastName;

    // cout << "Full name: " << firstName + " " + lastName << endl;
    // cout << "Size of string: " << firstName.length()  + lastName.length() << endl;

    string fullName;

    cout << "Enter full name: ";
    getline(cin, fullName);

    //fullName[10] = 'K';
    
    cout << "Full Name is " << fullName << endl;
}
