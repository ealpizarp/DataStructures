/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File TRIENODE.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David González Agüero
*
*   Fecha de ultima modificación: 03/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion deL nodo TrieNode con varias
*   modificaciones y funciones adicionales para el funcionamiento de
*   el programa neuratext.

********************************************************************************
*/

#ifndef TRIENODE_H
#define TRIENODE_H
#include "AVLTreeDictionary.h"

class TrieNode{
private:
    bool isFinal;
    int prefixCount;
    int frequency; //numero de apariciones de la palabra
    AVLTreeDictionary<char, TrieNode*> children;
    DLinkedList<int> lines;//lista de lineas donde la palabra aparece

public:
    TrieNode() : children() {
        isFinal = false;
        prefixCount = 0;
        frequency = 0;
    }

    ~TrieNode() {}

    bool getIsFinal() {
        return isFinal;
    }

    void setIsFinal(bool isFinal) {
        this->isFinal = isFinal;
    }

    int getPrefixCount() {
        return prefixCount;
    }

    void setPrefixCount(int prefixCount) {
        this->prefixCount = prefixCount;
    }

    int getFrequency() {
        return frequency;
    }

    void setFrequency(int frequency) {
        this->frequency = frequency;
    }

    void increaseCount() {
        prefixCount++;
    }

    void decreaseCount() {
        prefixCount--;
    }

    void increaseFrecuency() {
        frequency++;
    }

    bool contains(char c) {
        return children.contains(c);
    }

    void add(char c, TrieNode* newNode) {
        children.insert(c, newNode);
    }

    void addLine(int line) {
        lines.append(line);
    }

    void remove (char c) {
        children.remove(c);
    }

    TrieNode* getChild(char c) {
        return children.getValue(c);
    }

    List<char>* getChildren() {
        return children.getKeys();
    }

    List<TrieNode*>* getChildrenPointers() {
        return children.getValues();
    }

    List<int>* getLines() {
        return &lines;
    }

};

#endif // TRIENODE_H
