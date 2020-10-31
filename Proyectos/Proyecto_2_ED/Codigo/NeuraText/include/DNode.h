/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File DNode.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David Gonzales Agüero
*
*   Fecha de ultima modificación: 02/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion del nodo DNode el cual es utilizado
*   para la implementacion de la estructura de datos DLinkedList.

********************************************************************************
*/

#ifndef DNODE_H
#define DNODE_H

template <typename T>

class DNode
{
    public:
        T element;
        DNode<T> *next;
        DNode<T> *previous;

        DNode(T element, DNode<T> *next = nullptr, DNode<T>* previous = nullptr) {
        this->element=element;
        this->next=next;
        this->previous=previous;
        }

        DNode(DNode<T> * next = nullptr, DNode<T> * previous = nullptr){
        this->next=next;
        this->previous=previous;

        }

};

#endif // DNODE_H
