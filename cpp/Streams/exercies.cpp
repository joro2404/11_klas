#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string xy;

class Coordinates {

    private:
        int x;
        int y;

    public:
        Coordinates(int x, int y){

            this->x = x;
            this->y = y;
        }

        string toString() {

            ostringstream points;

            points << '(' << x << ',' << ' ' << y << ')';
            string data = points.str();

            return data;
        }


};

class coordinatesCollection {

    private:
        vector<Coordinates> points;

    public:

        void readPoints(string str) {

            istringstream data(str);
            int x, y;

            while(!data.eof()){
                data.ignore();
                data >> x;
                data.ignore();
                data >> y;
                Coordinates found(x, y);
                points.push_back(found);
            }
        }

        void printCoordinates(){

            for(int i=0;i<points.size();i++){

                cout << points[i].toString() << endl;
            }
        }
};


int main() {

    string str;
    coordinatesCollection points;
    getline(cin, str);
    points.readPoints(str);
    points.printCoordinates();
}