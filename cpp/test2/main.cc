#include "factory.hh"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

Factory get_best_factory(vector <Factory> factories){

    int index = 0;
    for (int i = 0; i < factories.size(); i++){
        if(factories[i].get_total_quality() > factories[index].get_total_quality())index = i;
    }
    
    return factories[index];
}

int main(){

    return 1;
}