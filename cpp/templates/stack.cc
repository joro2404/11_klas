#include "stack.hh"

template<class T>
stack<T>::stack() {
    size = chunk;
    top = -1;
    data = new T[size];
}

template<class T>
stack<T>::stack(const stack& other){
    size = other.size;
    top = other.top;
    data = new T[size];
}