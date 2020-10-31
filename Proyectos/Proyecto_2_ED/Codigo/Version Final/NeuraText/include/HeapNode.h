/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File HEAPNODE.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David González Agüero
*
*   Fecha de ultima modificación: 16/07/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion de el HeapNode el cual se utiliza para
*   la implementacion de la estructura de datos MaxHeap y MinHeap

********************************************************************************
*/

#ifndef HEAPNODE_H
#define HEAPNODE_H

template <typename Key, typename E>
class HeapNode
{
private:
    Key key;
    E element;

public:
    HeapNode() {}

    HeapNode(Key key){
        this->key=key;
    }

    HeapNode(Key key, E element){
        this->key = key;
        this->element = element;
    }

    ~HeapNode() {}

    Key getKey() {
        return key;
    }
    void setKey(Key pKey) {
        key = pKey;
    }
    E getElement() {
        return element;
    }
    void setElement(E pElement) {
        element = pElement;
    }
    void operator= (const HeapNode &other){
        key = other.key;
        element = other.element;
    }
    bool operator==(const HeapNode &other){
        return key == other.key;
    }
    bool operator!= (const HeapNode &other){
        return key != other.key;
    }
    bool operator< (const HeapNode &other){
        return key < other.key;
    }
    bool operator<= (const HeapNode &other){
        return key <= other.key;
    }
    bool operator> (const HeapNode &other){
        return key > other.key;
    }
    bool operator>= (const HeapNode &other){
        return key >= other.key;
    }
};

#endif // HEAPNODE_H
