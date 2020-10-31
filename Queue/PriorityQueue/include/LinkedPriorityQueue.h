#ifndef LINKEDPRIORITYQUEUE_H
#define LINKEDPRIORITYQUEUE_H

#include"LinkedQueue.h"
#include"PriorityQueue.h"

using std::runtime_error;

template<typename T>

class LinkedPriorityQueue : public PriorityQueue<T>
{
private:
        LinkedQueue<T> *queues;
        int size;
        int priorities;
public:
    LinkedPriorityQueue(int priorities) {
        if (priorities <= 0)
            throw runtime_error("The number of priorities must be positive");
        queues = new  LinkedQueue<T>[priorities];
        size = 0;
        this->priorities = priorities;
    }
    ~LinkedPriorityQueue( ){
    delete [] queues;
    }

    void insert(T element, int priority = 0){
        if (priority < 0 || priority >= priorities){
            throw runtime_error("Invalid priority.");
        }
        queues[priority].enqueue(element);
        size++;
        }

    T min( ) {
        if (size ==0)
            throw runtime_error("Queue is empty");
        for(int i = 0; i< priorities; i++) {
            if(!queues[i].isEmpty()){
                return queues[i].frontValue();
            }
        }
        throw runtime_error("Queue not found");
    }

    T removeMin(){
    if (size ==0)
            throw runtime_error("Queue is empty");
        for(int i = 0; i< priorities; i++) {
            if(!queues[i].isEmpty()){
                size--;
                return queues[i].dequeue();
            }
        }
        throw runtime_error("Queue not found");
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

};

#endif // LINKEDPRIORITYQUEUE_H
