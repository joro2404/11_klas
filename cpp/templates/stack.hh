#ifndef _STACK_H_
#define _STACK_H_

template<class T>
class stack {
    private:
        static const insigned int chunk = 2;
        int size;
        T* data;
        int top;
    public:
        stack();
        stack(const stack& other);
        ~stack();
        void push(const T& value);
        T pop();

    private:
        void resize();
};

#endif