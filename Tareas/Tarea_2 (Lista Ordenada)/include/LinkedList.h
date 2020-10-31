#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"
#include"List.h"

template <typename T>

class LinkedList: public List<T>
{
protected:
    Node<T>*head;
    Node<T>*current;
    Node<T>*tail;
    int size;

    public:
        LinkedList() {
        new Node<T>();
        current=tail=head=new Node<T>();
        size=0;
        }

        ~LinkedList(){
        clear();
        delete head;
        }

        void insert(T element){
        current->next=new Node<T>(element, current->next);
        size++;

        if(current==tail){
            tail=tail->next;
        }
        }




        void append(T element){
        tail=tail->next = new Node<T>(element);
        size++;
        }


        T remove(){
        if(size==0){
            throw runtime_error("List is empty");
        }
        if(current=tail){
            throw runtime_error("No current element");
        }

        T res=current->next->element;
        Node<T> *temp=current->next;
        current->next=temp->next;
        delete temp;

        if(current->next == nullptr){
            tail=current;
        }
        size--;
        return res;
        }

        void clear(){
        while(head->next != nullptr){
            current=head->next;
            head->next=current->next;
            delete current;
        }
        current=tail=head;
        size=0;
        }

        T getElement(){
        if(size==0){
            throw runtime_error("List is empty");
        }
        if(current==tail){

            throw runtime_error("No current element");
        }

        return current->next->element;

        }

        void goToStart(){
        current=head;
        }

        void goToEnd(){
        current=tail;
        }

        void goToPos(int pos){
        if(pos<0 || pos>size){
            throw runtime_error("Index out of range");
        }
        goToStart();
        for(int i=0; i<pos; i++){

            current=current->next;
        }
        }

        void next(){
        if(current != tail){
            current=current->next;
        }
        }

        void previous(){
        if(current != head){
            Node<T>* temp=head;
            while(temp->next != current){
                temp=temp->next;
            }
            current=temp;
        }
        }

        bool atStart(){
        return current==head;
        }

        bool atEnd(){
        return current==tail;
        }

        int getPos(){
        int pos=0;
        Node<T>*temp=head;

        while(temp!=current){
            temp-temp->next;
            pos++;
        }
        return pos;
        }


        int getSize(){
        return size;
        }

        void reverse(){
        current = head;
        Node<T>* temp = head->next;
        Node<T>* temp2 = head->next;
        tail=head->next;
        while(current != nullptr){
            temp2=current->next;
            current->next=temp;
            temp=current;
            current=temp2;
        }
        head->next=temp;
        current=head;
        tail->next=nullptr;
        }

        bool equals(List<T> *L){
        if(L->getSize() != size){
            return false;
        }
        goToStart();
        L->goToStart();
        int aux=0;
        while(current != tail){
        if(getElement() == L->getElement()){
            aux++;
        }
        current = current->next;
        L->next();
        }
        if(aux != size){
            return false;
        }
        return true;
        }

        void print(){
        goToStart();
        while(current!= tail){
            std::cout<<current->next->element<<" -> ";
            current=current->next;
        }
        std::cout<<"NULL";
        }



    protected:

    private:
};

#endif // LINKEDLIST_H
