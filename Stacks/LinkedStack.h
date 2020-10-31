#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include"Node.h"

template <typename T>

class LinkedStack:  public Stack<T>
{
    private:
        Node<T> * top;
        int size;
    public:
        LinkedStack(){
        top = nullptr;
        size = 0;
        }
        ~LinkedStack(){
        clear();
        }
        void push(T element){
        top = new Node<T>(element, top);
        size++;
        }

        T pop(){
        if(size ==0){
            throw runtime_error("Stack underflow");
        }
        T result = top->element;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        size--;
        return result;
        }


        T topValue(){
        if(top == 0) throw runtime_error("Stack is empty");
        return top->element;
        }

        void clear(){
        Node<T> * temp;
        while(top != nullptr){
            temp = top;
            top = top->next;
            delete temp;
        }   }

        bool isEmpty(){
        return top==nullptr;
        }

        int getSize(){
        return size;
        }

        void print(){
        int SizeTopValue = size;
        Node<T>* temp = top;
        while(SizeTopValue > 0){
            std::cout<< top->element <<" ";
            top = top->next;
            SizeTopValue--;
        }
        std::cout<<std::endl;
        top = temp;
        }



};

#endif // LINKEDSTACK_H
