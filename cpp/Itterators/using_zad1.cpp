#include <iostream>
#include <queue>
#include <string>
#include "zad1.cpp"

using namespace std;
using namespace brackets;

int main() {

    Brackets Brackets;

    int checker = Brackets.countBrackets();

    cout << "The string is balanced: " << checker << endl;
}

