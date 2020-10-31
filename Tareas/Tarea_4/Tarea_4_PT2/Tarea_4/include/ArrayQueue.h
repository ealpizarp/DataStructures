#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include<stdexcept>
#include"Queue.h"

using std::runtime_error;

template<typename T>

class ArrayQueue: public Queue<T>
{
private:
    int front;
    int rear;
    int size;
    int max;
    T* elements;

public:
    ArrayQueue(int maxSize = DEFAULT_MAX_SIZE){
    max=maxSize;
    elements = new T[maxSize];
    rear = 0;
    front = 0;
    size = 0;
    }
    ~ArrayQueue(){
    delete[]  elements;
    }

    void enqueue(T element){
    if(size == max) throw runtime_error("Queque is full");
    elements[rear] = element;
    rear = (rear + 1)   % max;
    size++;
    }

    void enqueueFront(T element){
    if(size == max) throw runtime_error("Queue is full");
    front = (front + max - 1) % max;
    elements[front] = element;
    size++;
    }

    T dequeue(){
    if (size == 0) throw runtime_error("Queue is empty");
    front = (front+1)  % max;
    size--;
    return elements[(front + max-1) % max];
    }

    T dequeueRear(){
    if (size == 0) throw runtime_error("Queue is empty");
    rear = (rear + max -1) % max;
    size--;
    return elements[(rear) % max];
    }

    T frontValue(){
        if (size == 0) throw runtime_error("Queue is empty");
        return elements[front];
    }

    T rearValue(){
        if(size==0) throw runtime_error("Queue is empty");
        return elements[rear];
    }

    void clear(){
    size=front=rear=0;
    delete[] elements;
    elements = new T[max];
    }

    void print(){
    int temp = front;
    for(int i = 0; i < size; i++){
    std::cout<<elements[temp % max]<<" ";
    temp++;
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

#endif // ARRAYQUEUE_H
