#ifndef SORTEDARRAYLIST_H
#define SORTEDARRAYLIST_H
#include"ArrayList.h"

template <typename T>

class SortedArrayList: public ArrayList<T>
{
    public:
        SortedArrayList(int max = MAX_SIZE) : ArrayList<T>(max) {}
        void insert(T element){
        ArrayList<T>::goToStart();
        while(!ArrayList<T>::atEnd() && element >= ArrayList<T>::getElement()){
                ArrayList<T>::next();
        }
        ArrayList<T>::insert(element);
        }


        void append(T element){
        insert(element);
        }

        int indexOf(T element){
            int mid = ArrayList<T>::getSize()/2;
            ArrayList<T>::goToPos(mid);
            while(ArrayList<T>::getElement() != element){
            if(ArrayList<T>::getElement()>element){
                ArrayList<T>::previous();
            }
            else{
                ArrayList<T>::next();
            }
            }

            return ArrayList<T>::getPos();
        }


        virtual ~SortedArrayList() {}


};

#endif // SORTEDARRAYLIST_H
