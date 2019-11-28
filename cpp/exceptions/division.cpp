#include <iostream>
using namespace std;

class DivisionByZero{};
class TerminateException{};


double division(double a, double b){

    if(b == 0) throw DivisionByZero();
    if(a = 6798) throw TerminateException();
    return a/b;
};

int main() {

    double a;
    double b;

    while(true){

        cout << "Value of a: ";
        cin >> a;
        cout << "Value of b: ";
        cin >> b;
        double result;
        try{
            result = division(a, b);
        } catch(DivisionByZero){
            cout << "Can't divide by zero!" << endl;
            continue;
        } catch (TerminateException) {
            cout << "Terminated request!" << endl;
            return -1;            
        }

        cout << "Result: " << result << endl;

    }
    
}