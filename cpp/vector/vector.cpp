#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class VectorPopException : exception {};
class VectorPushException : exception {};
class ValException : exception{};

class vector{
    private:
        int *items;
        int elements;
        int value;
    public:
    vector(){
            count = 0;
            items = NULL;
            elements = 10;
            value = 100;
        }

        vector(int max_elements, int max_value){
            count = 0;
            items = NULL;
            elements = max_elements;
            value = max_value;
        }
        
        int count;
        void push(int new_item){
            if(count == elements){
                throw VectorPushException();
            }
            else if(new_item > value){
                throw ValException();
            }
            else{
                items = (int*)realloc(items, (sizeof(int)*(++count)));
                items[count-1] = new_item;
            }
            
        }

        int is_empty(){
            if(count<=0){
                return 1;
            }
            return 0;
        }

        // int pop(int *popped_item){
        //     if(is_empty()){
        //         return 0;
        //     }
        //      *popped_item = items[--count];
        //     return 1;
        // }

        int pop(){
            if(is_empty()){
                throw VectorPopException();
            }
            return items[--count];
        }

        void empty() {
            free(items);
            count = 0;
        }
};



int main(){
    int max_el = 15;
    vector v1(max_el,7);
    vector v2;


    try{
        int i;
        for (i = 0; i < max_el + 1; i++)
        {
            v1.push(i);
            cout << "Pushed: " << i << endl;
        }
    }
    catch(VectorPushException ex){
        cout << "Max exceeded: " << v1.count << endl;
    }
    catch(ValException ex){
        cout << "Value exceeded" << endl;
    }



    try{
        int popped_item;
        while(1){
            popped_item = v1.pop();
            cout << "Item poped: " << popped_item << endl;
        }
    }
    catch(VectorPopException ex){
        cout << "Pop bruh" << endl;
    }
    catch(exception ex){
        cout << "bruh" << endl;
    }
    
    return 0;
}

