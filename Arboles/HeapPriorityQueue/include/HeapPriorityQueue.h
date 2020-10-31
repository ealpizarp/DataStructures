#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include"PriorityQueue.h"
#include"MinHeap.h"
#include"KVPair.h"

template<typename T>

class HeapPriorityQueue : public PriorityQueue<T> {
private:
    MinHeap<KVPair<int, T> > *elements;
    int priorities;

public:
    HeapPriorityQueue(int priorities, int max =DEFAULT_MAX_SIZE) {
        if(priorities <= 0){
            throw runtime_error("The number of priorities must be positive");
        }
        this->priorities = priorities;
        elements = new MinHeap<KVPair<int, T> >(max);
    }
    ~HeapPriorityQueue() {
        delete elements;
    }

    void insert(T element, int priority) {
        if (priority < 0 || priority >= priorities){
            throw runtime_error("Invalid priority");
        }
        KVPair<int, T> p(priority, element);
        elements->insert(p);
    }

    T min(){
        KVPair<int, T> p = elements->first();
        return p.getValue();
    }

    T removeMin(){
        KVPair<int, T> p = elements->removeFirst();
        return p.getValue();
    }

    int getSize(){
        return elements->getSize();
    }

    bool isEmpty(){
        return elements->getSize() == 0;
    }
};

#endif // HEAPPRIORITYQUEUE_H
