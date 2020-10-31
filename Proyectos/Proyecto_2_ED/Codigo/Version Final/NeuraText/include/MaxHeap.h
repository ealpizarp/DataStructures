/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File MAXHEAP.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David Gonzales Agüero
*
*   Fecha de ultima modificación: 29/07/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion de la estructura de datos MaxHeap
*   vista en clase.
********************************************************************************
*/
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include"HeapNode.h"
#include <stdexcept>

using namespace std;

template <typename K, typename E>
class MaxHeap {
private:
    int maxSize;
    int size;
    HeapNode<K, E>* elements;

    int leftChild(int pos) {
        return 2 * pos + 1;
    }
    int rightChild(int pos) {
        return 2 * pos + 2;
    }
    int parent(int pos) {
        if (pos == 0) {
            return -1;
        }
        return (pos - 1) / 2;
    }
    int isLeaf(int pos) {
        if ((pos >= size) || (pos < 0)) {
            throw runtime_error("Position out of range.");
        }
        return leftChild(pos) >= size;
    }
    void swap(int pos1, int pos2) {
        HeapNode<K, E> temp = elements[pos1];
        elements[pos1] = elements[pos2];
        elements[pos2] = temp;
    }
    void siftUp(int pos) {
        while(pos > 0 && elements[pos] > elements[parent(pos)]){
            swap(pos, parent(pos));
            pos = parent(pos);
        }
    }
    void siftDown(int pos) {
        while (!isLeaf(pos) && elements[pos] < elements[greaterChild(pos)]){
            int gChild = greaterChild(pos);
            swap(pos, gChild);
            pos = gChild;
        }
    }
    int greaterChild(int i) {
        if (rightChild(i) >= size || elements[leftChild(i)] > elements[rightChild(i)]){
            return leftChild(i);
        }
        return rightChild(i);
    }

public:
    MaxHeap(int maxSize = 1024) {
        this->maxSize = maxSize;
        size = 0;
        elements = new HeapNode<K, E>[maxSize];
    }
    ~MaxHeap() {
        delete [] elements;
    }
    /*
    void insert(E element) {
        if (size == maxSize){
        throw runtime_error("Heap is full");
        }
        elements[size] = element;
        siftUp(size);
        size++;
    }
    */

    void insert(K key, E element) {
        if (size == maxSize){
            throw runtime_error("Heap is full");
        }
        HeapNode<K, E> temp(key, element);
        elements[size] = temp;
        siftUp(size);
        size++;
    }
    HeapNode<K, E> removeFirst() {
        if (size ==0){
            throw runtime_error("Heap is empty");
        }
        return remove(0);

        throw runtime_error("Cant remove!");
    }
    HeapNode<K, E> remove(int pos) {
        if(pos < 0 || pos >= size){
            throw runtime_error("Index out of range");
        }

        HeapNode<K, E> result = elements[pos];
        swap(pos, size-1);
        size--;
        if (size > 0){
            siftDown(pos);
        }
        return result;
    }
    int getSize() {
        return size;
    }
};

#endif // MAXHEAP_H
