/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File BSTNODE.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David Gonzales Agüero
*
*   Fecha de ultima modificación: 02/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion del nodo BSTNode para el uso de los
*   arboles.

********************************************************************************
*/

#ifndef BSTNODE_H
#define BSTNODE_H

template<typename T>
class BSTNode {
private:
    T element;
    BSTNode<T> *left;
    BSTNode<T> *right;

public:
    BSTNode(T element, BSTNode<T> *left = nullptr, BSTNode<T> *right = nullptr) {
    this->element=element;
    this->left=left;
    this->right=right;
    }

    ~BSTNode() {}

    T getElement(){
        return element;
    }

    void setElement(T element){
        this->element = element;
    }

    BSTNode<T>* getLeft(){
        return left;
    }

    void setLeft(BSTNode<T> *left){
        this->left=left;
    }

    BSTNode<T>* getRight(){
        return right;
    }

    void setRight(BSTNode<T> *right){
        this->right=right;
    }

    bool isLeaf(){
        return left == nullptr && right == nullptr;
    }

    int childrenCount() {
        return (left == nullptr ? 0 : 1) + (right == nullptr ? 0 : 1);
    }

    BSTNode<T>* getUniqueChild() {
        return left == nullptr ? right : left;
    }

};

#endif // BSTNODE_H
