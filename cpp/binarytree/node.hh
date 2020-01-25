#ifndef NODE_HH
#define NODE_HH

template <class T>
class Node {

    protected:
        Node*left;
        Node* right;
        T value;
        Node* parent;

    public:

        Node(T value, Node* parent);
        ~Node();

        Node* get_left();
        Node* get_right();
        T get_value();
        Node* get_parent();

        void set_left(Node* left);
        void set_right(Node* right);
        void set_value(T value);
        void set_parent(Node* parent);
        

};

#endif