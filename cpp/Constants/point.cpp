#include <iostream>
using namespace std;

class Point {
    public:
    
        class Line{
            int length;
            public:

                Line (int length){
                    this->length = length;
                }

                int get_length(){
                    return length;
                }
        };
    
    private :
        double x;
        double y;
        const char name = 'A';

    public:

        Point(double x, double y, const char name) : name(name){
            this->x = x;
            this->y = y;
        }

        double get_x() const{
            return x;
        }

        void set_x(double x){
            this->x = x;
        }

        double get_y();

        void set_y(double y);

        void print(){
            cout << name << "-> X: " << x << ", Y: " << y << endl;
        }
};

double Point::get_y(){
    return y;
}


void Point::set_y(double y){
    this->y = y;
}

void change(Point a, Point& b){
    a.set_x(8);
    b.set_x(9);
}

int main(){

    Point a = Point(2, 3, 'A');
    a.print();

    Point b = Point(3, 4, 'B');
    // cout << b.get_x() << endl;
    b.print();

    change(a ,b);
    //a.set_x(8);
    a.print();
    b.print();
}