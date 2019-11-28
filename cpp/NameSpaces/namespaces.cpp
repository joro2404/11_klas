#include <iostream>
using namespace std;

namespace firstSpace{

    void say_hello(){

        cout << "Hello from frist namespace" << std::endl;
    }

    namespace innerSpace {
        void say_hello(){

            cout << "Hello from inner namespace" << std::endl;
        }
    }
};

namespace secondSpace {

    void say_hello() {

        cout << "Hello from second namespace" << std::endl;
    }
};

using namespace firstSpace::innerSpace;

int main() {

    say_hello();
    secondSpace::say_hello();

}