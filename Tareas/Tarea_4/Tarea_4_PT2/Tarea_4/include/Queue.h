#ifndef QUEUE_H
#define QUEUE_H
#define DEFAULT_MAX_SIZE 1024

template <typename T>
class Queue {
private:
    void operator =(const Queue&) {}
    Queue(const Queue& obj) {}

public:
    Queue() {}
    virtual ~Queue() {}
    virtual void enqueue(T element) = 0;
    virtual T dequeue() = 0;
    virtual T frontValue() = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual void print() = 0;
    virtual T dequeueRear() = 0;
    virtual T rearValue() = 0;
    virtual void enqueueFront(T element) = 0;
};

#endif // QUEUE_H
