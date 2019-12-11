#include "core.hh"
#include <iostream>
using namespace std;

core core::operator<<(core plane_1){
    cout << plane_1.size << endl;
    cout << plane_1.number_of_flight << endl;
    cout << plane_1.model << endl;
    cout << plane_1.speed << endl;
    cout << plane_1.fuel << endl;
    cout << plane_1.fuel_per_km << endl;
    cout << plane_1.X << endl;
}
        