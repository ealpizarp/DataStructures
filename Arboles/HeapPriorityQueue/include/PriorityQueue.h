#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue
{
private:
    void operator=(const PriorityQueue&){}
    PriorityQueue(const PriorityQueue& other);

    public:
        PriorityQueue() {}
        virtual ~PriorityQueue() {}
        virtual void insert(T element, int priority) = 0;
        virtual T min() = 0;
        virtual T removeMin() = 0;
        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;

};

#endif // PRIORITYQUEUE_H
