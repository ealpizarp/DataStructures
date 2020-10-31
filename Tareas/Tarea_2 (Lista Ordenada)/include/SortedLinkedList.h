#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "LinkedList.h"
template<typename T>
class SortedLinkedList : public LinkedList<T>
{
    public:
        SortedLinkedList(): LinkedList<T>() {
        }
        void insert(T element){
        L.goToStart();

        while(!L.atEnd() && element >= L.getElement()){
            L.next();
            }

        L.insert(element);
        }

        void append(T element){
        insert(element);
        }

        T remove(){
        return L.remove();
        }

        void clear(){
        L.clear();
        }

        void goToEnd(){
        L.goToEnd();
        }

        void goToStart(){
        L.goToStart();
        }

        void goToPos(int pos){
        L.goToPos(pos);
        }

        void next(){
        L.next();
        }

        void previous(){
        L.previous();
        }

        bool atEnd(){
        return L.atEnd();
        }

        bool atStart(){
        return L.atStart();
        }

        int getPos(){
            return L.getPos();
        }

        int getSize(){
            return L.getSize();
        }

        void print(){
        L.print();
        }

    private:
        LinkedList<T> L;
};

#endif // SORTEDLINKEDLIST_H
