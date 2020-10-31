#ifndef SORTEDARRAYLIST_H
#define SORTEDARRAYLIST_H
#include"ArrayList.h"

template <typename T>

class SortedArrayList: public ArrayList<T>
{
    public:
        SortedArrayList(int max = MAX_SIZE): ArrayList<T>(max){}
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

        void print(){
        L.print();
        }

        int indexOf(T element){
            if(L.getSize()==0){
                throw runtime_error("List is empty");
            }
            if(!L.contains(element)){
                throw runtime_error("Element not in list");
            }
            int mid = (L.getSize()/2);
            L.goToPos(mid);
            while(L.getElement() != element){
            if(L.getElement()> element){
                L.previous();
            }
            else{
                L.next();
            }
            }
            return L.getPos();
        }

        virtual ~SortedArrayList() {}

    private:

        ArrayList<T> L;





};

#endif // SORTEDARRAYLIST_H
