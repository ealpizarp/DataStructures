#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Stack.h"
#include<stdexcept>

using std::runtime_error;

template <typename T>

class ArrayStack:   public Stack<T>
{
private:
    int maxSize;
    int top;
    T * elements;

public:
    ArrayStack(int maxSize = DEFAULT_MAX_SIZE)
    {
    this->maxSize = maxSize;
    this->elements = new T[maxSize];
    this->top = 0;
    }

    ~ArrayStack(){
    delete [] elements;
    }

    void push(T element){
    if(top == maxSize) {
        T* temp = new T[maxSize];
        temp = elements;
        top = 0;
        elements = new T[maxSize*2];
        for(int i =0; i < maxSize; i++){
            elements[i] = temp[i];
            top++;
        }
         maxSize = maxSize * 2;
    }
    elements[top] = element;
    top++;
    }

    T pop(){
    if(top==0){throw runtime_error("Stack underflow");}
    top--;
    return elements[top];
    }

    T topValue(){
    if (top==0) {throw runtime_error("Stack is empty");}
    return elements[top -1];
    }

    void clear(){
    top = 0;
    }

    bool isEmpty(){
    return top == 0;
    }

    int getSize(){
    return top;
    }

    void print(){
        int size = top-1;
        while(size >= 0){
            std::cout<<elements[size]<<" ";
            size--;
        }
        std::cout<<std::endl;
    }
};

#endif // ARRAYSTACK_H
