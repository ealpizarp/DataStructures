/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File AVLTREEDICTIONARY.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David Gonzales Agüero
*
*   Fecha de ultima modificación: 02/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion de la estructura de datos AVLTree
*   Dictionary o Diccionario con arbol AVL balanceado.

********************************************************************************
*/

#ifndef AVLTREEDICTIONARY_H
#define AVLTREEDICTIONARY_H

#include "Dictionary.h"
#include "AVLTree.h"
#include "KVPair.h"



#include<stdexcept>

using std::runtime_error;

template <typename K, typename V>

class AVLTreeDictionary : public Dictionary<K,V>
{
private:
    AVLTree<KVPair<K, V> > pairs;

public:
    AVLTreeDictionary() : pairs(){}

    ~AVLTreeDictionary() {}
    void insert(K key, V value) {                       //La exepcion para que no acepte valores repetidos esta en el BSTree
        KVPair<K, V> p(key, value);
        pairs.insert(p);

    }

    V remove(K key) {
        KVPair<K, V> p(key);
        p = pairs.remove(p);
        return p.getValue();
    }

    V getValue(K key) {
        KVPair<K, V> p(key);
        p = pairs.find(p);
        return p.getValue();
    }

    void setValue(K key, V value) {
        KVPair<K, V> p(key, value);
        pairs.remove(p);
        pairs.insert(p);
    }

    void clear() {
        pairs.clear();
    }

    bool contains(K key) {
        KVPair<K, V> p(key);
        return pairs.contains(p);
    }

    List<K>* getKeys() {
        List<K> *keys = new DLinkedList<K>();
        List<KVPair<K, V> > *pairList = pairs.getElements();
        for (pairList->goToStart(); !pairList->atEnd(); pairList->next()) {
            KVPair<K, V> p = pairList->getElement();
            keys->append(p.getKey());
        }
        delete pairList;
        return keys;
    }

    List<V>* getValues() {
        List<V> *values = new DLinkedList<V>();
        List<KVPair<K, V> > *pairList = pairs.getElements();
        for (pairList->goToStart(); !pairList->atEnd(); pairList->next()) {
            KVPair<K, V> p = pairList->getElement();
            values->append(p.getValue());
        }
        delete pairList;
        return values;
    }

    int getSize() {
        return pairs.getSize();
    }



};

#endif // AVLTREEDICTIONARY_H
