#ifndef DCIRCLELIST_H
#define DCIRCLELIST_H

#include<stdexcept>
#include"DNode.h"
#include"DLinkedList.h"

using std::runtime_error;

template <typename T>

class DCircleList
{

    private:
        int size;
        DNode<T> * current;


    public:

        DCircleList() {
        current=nullptr;
        size=0;
        }

        ~DCircleList() {
        }


        void insert(T element){
        if(current==nullptr){
            current->previous=current->next=current= new DNode<T>(element);
        }
        else{
            current->next=current->next->previous=new DNode<T>(element, current->next, current);
        }
        size++;

        }

        T remove(){
            if(current==nullptr){
                throw runtime_error("List is empty, cant remove element!");
            }
            T result = current->next->element;
            current->next=current->next->next;
            delete current->next->previous;
            current->next->previous=current;
            size--;
            return result;

        }

        void clear(){
        DNode<T> * temp;
        while(size != 0){
            temp = current->next;
            current->next = current->next->next;
            temp->next->previous = current;
            delete temp;
            size--;
        }
        current=nullptr;
        }


        T getFront(){
        if(current==nullptr){
            throw runtime_error("There is no current element, Empty List");
        }
        return current->next->element;
        }

        T getBack(){
        if(current==nullptr){
            throw runtime_error("There is no current element, Empty List");
        }
        return current->element;
        }

        void next(){
        if(current != nullptr && size > 1){
            current=current->next;
        }
        }

        void previous(){
        if(current != nullptr && size >1){
            current=current->previous;
        }
        }

        int getSize(){
        return size;
        }

        DLinkedList<T> * getElements(bool reverse){

        if(current==nullptr){
            throw runtime_error("List is empty!");
        }

        DLinkedList<T> * temp = new DLinkedList<T>;
        if(reverse){

        for(int i = 0; i < size; i++){
            temp->append(getFront());
            next();
        }
        }
        else{
            for(int i = 0; i < size; i++){
            temp->append(getBack());
            next();
        }


        }

        return temp;
        }




};

#endif // DCIRCLELIST_H
