#include<iostream>
using namespace std;

class Point {

	private :
		int x;
		int y;

	public:
	
		Point (int x, int y){
		
			this->x = x;
			this->y = y;
		}
		
		Point (int x) {
			
			this->x;
		}
	
		int getX() {

			return x;
		}
		
		
		void setX(int abc){
		
			x = abc;
		}
};

void Point::setX(int x) {

	this->x = x;
}

int main() {

	Point p = Point(9, 3);
	p.setX(9);
	POint* pointer = &p;
	cout << "Value of x: " << p.getX() << endl;
}
