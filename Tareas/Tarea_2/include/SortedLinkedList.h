#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "LinkedList.h"
template<typename T>
class SortedLinkedList : public LinkedList<T>
{
    public:
        SortedLinkedList():LinkedList<T>() {}

        void insert(T element){
        SortedLinkedList<T>::goToStart();

        while(!LinkedList<T>::atEnd() && element >= LinkedList<T>::getElement()){
            LinkedList<T>::next();
            }

        LinkedList<T>::insert(element);
        }

        void append(T element){
        insert(element);
        }
};

#endif // SORTEDLINKEDLIST_H
