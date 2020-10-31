#ifndef MINHEAP_H
#define MINHEAP_H
#define DEFAULT_MAX_SIZE 1024

#include<stdexcept>

using std::runtime_error;

template<typename T>
class MinHeap {
private:
    T* elements;
    int max;
    int size;

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i){
        return 2 * i + 2;
    }

    int parent(int i){
        if(i == 0){
            return -1;
        }
        return (i - 1) / 2;
    }

    void siftUp(int i){
        while(i > 0 && elements[i] < elements[parent(i)]){
            swap(i, parent(i));
            i = parent(i);
        }
    }

    void swap(int pos1, int pos2){
        T temp = elements[pos1];
        elements[pos1] = elements[pos2];
        elements[pos2] = temp;
    }

    void siftDown(int i) {
        while (!isLeaf(i) && elements[i] > elements[greaterChild(i)]){
            int gChild = greaterChild(i);
            swap(i, gChild);
            i = gChild;
        }
    }

    bool isLeaf(int i) {
        return leftChild(i) >= size;
    }

    int greaterChild(int i) {
        if (rightChild(i) >= size || elements[leftChild(i)] < elements[rightChild(i)]){
            return leftChild(i);
        }
        return rightChild(i);
    }

public:
    MinHeap(int max = DEFAULT_MAX_SIZE) {
        elements = new T[max];
        this->max=max;
        size = 0;
    }

    ~MinHeap(){
        delete[] elements;
    }

    void insert(T element){
        if (size == max){
            throw runtime_error("Heap is full");
        }
        elements[size] = element;
        siftUp(size);
        size++;
    }

    T removeFirst(){
        if (size ==0){
            throw runtime_error("Heap is empty");
        }
        return remove(0);
    }


    T remove(int pos){
        if(pos < 0 || pos >= size){
            throw runtime_error("Index out of range");
        }

        T result = elements[pos];
        swap(pos, size-1);
        size--;
        if (size > 0){
            siftDown(pos);
        }
        return result;
    }

    T first(){
        if(size == 0){
            throw runtime_error("Heap is empty");
        }
        return elements[0];
    }

    int getSize(){
        return size;
    }

};

#endif // MINHEAP_H
