#include <iostream>
#include <algorithm>
using namespace std;

class Rect{
    int x;
    int y;
    int w;
    int h;
    public:
        Rect(int x, int y, int w, int h){
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
        }

        Rect operator+(int num){
            Rect result = Rect(x + num, y + num, w + num, h + num);
            return result;
        }

        Rect operator+(Rect rect){
            // int width = (w - max(x, rect.x)) + rect.w;
            // int height = (h - max(y, rect.y)) + rect.h;
            int xc = min(x, rect.x);
            int yc = min(y, rect.y);
            int width = max(x + w, rect.x + rect.w) - xc;
            int height = max(y + h, rect.y + rect.h) - yc;
            Rect result(xc, yc, width, height); 
            return result;
        }

        void operator+=(int num){
            x += num;
            y += num;
            w += num;
            h += num;
        }

        void operator+=(Rect rect){
            x += min(x, rect.x);
            y += min(y, rect.y);
            w += max(x + w, rect.x + rect.w) - x;
            h += max(y + h, rect.y + rect.h) - y;
        }

        void getAll(){
            cout << x << " " <<  y << " "  << w << " " <<  h << endl;
        }


};

int main(){
    Rect rect1(0, 0, 4, 3);
    // rect1.getAll();
    // Rect rect2 = rect1 + 2;
    Rect rect2(2, 2, 5, 2);
    // rect2.getAll();
    Rect rect3 = rect1 + rect2;
    rect3.getAll();

    Rect rect4(1, 1, 4, 3);
    Rect rect5(3, 3, 6, 5);
    Rect rect6 = rect4 + rect5;
    rect6.getAll();
}