#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v;
    
    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    cout << "Size: " << v.size() << endl;
    v.pop_back();
    cout << "Size: " << v.size() << endl;
    
}