#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include<stdexcept>
#include"Queue.h"
#include"Node.h"

using std::runtime_error;

template<typename T>

class LinkedQueue: public Queue<T>
{
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    LinkedQueue(){
        front = rear = new Node<T>();
        size = 0;
    }
    ~LinkedQueue(){
    clear();
    delete front;
    }
    void enqueue(T element){
    rear->next = new Node<T>(element);
    rear = rear->next;
    size++;
    }

    void enqueueFront(T element){
    front->next = new Node<T>(element, front->next);
    if(size == 0){
        rear = front->next;
    }
    size++;

    }

    T dequeue(){
    if(size == 0){
        throw runtime_error("Queue is empty");
    }
    Node<T>* temp = front->next;
    T result= temp->element;
    front->next = front->next->next;
    delete temp;
    size--;
    if(front->next == nullptr){
        rear = front;
    }
    return result;
    }

    T dequeueRear(){
    if(size == 0) throw runtime_error("Queue is empty");
    Node<T>* temp = front;
    T res = rear->element;
    if(size == 1){
        delete temp;
        rear = front;
        front->next = nullptr;
        size--;
        return res;
    }
    while(temp->next != rear){
        temp = temp->next;
    }
    rear = temp;
    delete temp->next;
    temp->next = nullptr;
    size--;
    return res;
    }

    T frontValue(){
    if(size == 0)
        throw runtime_error("Queue is empty");
    return front->next->element;
    }

    void clear(){
    Node<T>* temp = front->next;
    while(temp != nullptr){
        front->next = front->next->next;
        delete temp;
        temp = front->next;
    }
    rear = front;
    size = 0;
    }

    T rearValue(){
    return rear->element;
    }

    void print(){
    Node<T>* temp = front->next;
    while(temp != nullptr){
        std::cout<<temp->element<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
    }

    bool isEmpty(){
    return size == 0;
    }

    int getSize(){
    return size;
    }



};

#endif // LINKEDQUEUE_H
