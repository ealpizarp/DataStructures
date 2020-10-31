#ifndef NODE_H
#define NODE_H
#include <cstdlib>

template <typename E>
class Node {
public:
    E element;
    Node<E>* next;

    Node(E element, Node<E>* next = NULL) {
        this->element = element;
        this->next = next;
    }
    Node(Node<E>* next = NULL) {
        this->next = next;
    }
    ~Node() {}
};

#endif // NODE_H
