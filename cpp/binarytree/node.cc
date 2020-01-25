#include "node.hh"


template <class T>
Node<T>::Node(T value, Node* parent){
    this->value = value;
    this->left = NULL;
    this->right = NULL;
    this->parent = parent;
}

template <class T>
Node<T>::~Node(){
    if(this->parent.get_value > this->value){
        this-parent.set_right(NULL);
    }
    else{
        this->parent.set_left(NULL);
    }
}

template <class T>
Node<T>* Node<T>::get_left(){
    return this->left;
}

template <class T>
Node<T>* Node<T>::get_right(){
    return this->right;
}

template <class T>
T Node<T>::get_value(){
    return this->value;
}

template <class T>
Node<T>* Node<T>::get_parent(){
    return this->parent;
}

template <class T>
void Node<T>::set_left(Node* left){
    this->left = left;
}

template <class T>
void Node<T>::set_right(Node* right){
    this->right = right;
}

template <class T>
void Node<T>::set_value(T value){
    this->value = value;
}

template <class T>
void Node<T>::set_parent(Node* parent){
    this->value = value;
}