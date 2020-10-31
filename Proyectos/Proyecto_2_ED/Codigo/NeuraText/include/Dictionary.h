/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File BSTREE.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David Gonzales Agüero
*
*   Fecha de ultima modificación: 02/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion de la estructura de datos BSTree o
*   arbol de busqueda binaria vista en clase

********************************************************************************
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "List.h"

template <typename K, typename V>

class Dictionary
{
    public:
        Dictionary() {}
        virtual ~Dictionary() {}
        virtual void insert(K key, V value) = 0;
        virtual V remove(K key) = 0;
        virtual V getValue(K key) = 0;
        virtual void setValue(K key, V value) = 0;
        virtual void clear() = 0;
        virtual bool contains(K key) = 0;
        virtual List<K>* getKeys() = 0;
        virtual List<V>* getValues() = 0;
        virtual int getSize() = 0;
};

#endif // DICTIONARY_H
