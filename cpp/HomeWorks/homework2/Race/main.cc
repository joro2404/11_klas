#include<vector>
#include <iostream>
using namespace std;
int main(){

    vector<vector<int> > a;
    vector<int> b;
    for (int i = 0; i < 3; i++){

        if(i != 0 )a.push_back(b);
        for (int j = 0; j < 12; j++){
            a[i].push_back(0);
        }
        
    }

    for (int i = 0; i < a.size(); i++){

        for (int j = 0; j < a[i].size(); j++){
            cout << a[i][j];
        }
        cout << endl;
        
    }
}
