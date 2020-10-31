/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File AVLTREE.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David Gonzales Agüero
*
*   Fecha de ultima modificación: 02/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion de la estructura de datos AVLTree
*   o Arbol AVL balanceado vista en clase.

********************************************************************************
*/

#ifndef AVLTREE_H
#define AVLTREE_H
#include"List.h"
#include"DLinkedList.h"
#include"BSTNode.h"
#include<stdexcept>

using std::runtime_error;
template<typename T>
class AVLTree {
private:

    BSTNode<T> *root;

    BSTNode<T>* insertAux(BSTNode<T>* pRoot, T element) {
        if (pRoot == nullptr) {
            return new BSTNode<T> (element);
        }
        if (element == pRoot->getElement()) {
            throw runtime_error("Duplicated elements not allowed.");
        }
        if (element < pRoot->getElement()) {
            pRoot->setLeft(insertAux(pRoot->getLeft(), element));
            pRoot = rebalanceLeft(pRoot);
        }
        else {
            pRoot->setRight(insertAux(pRoot->getRight(), element));
            pRoot = rebalanceRight(pRoot);
        }
        return pRoot;
    }

    BSTNode<T>* rebalanceLeft(BSTNode<T> *pRoot) {
        int leftHeight = height(pRoot->getLeft());
        int rightHeight = height(pRoot->getRight());

        if (leftHeight - rightHeight > 1) {
            int leftLeftHeight = height(pRoot->getLeft()->getLeft());
            int leftRightHeight = height(pRoot->getLeft()->getRight());

            if (leftLeftHeight >= leftRightHeight) {
                return rotateRight(pRoot);
            }
            else {
                pRoot->setLeft(rotateLeft(pRoot->getLeft()));
                return rotateRight(pRoot);
            }
        }
        return pRoot;
    }

    BSTNode<T>* rebalanceRight(BSTNode<T> *pRoot) {
        int rightHeight = height(pRoot->getRight());
        int leftHeight = height(pRoot->getLeft());

        if (rightHeight - leftHeight > 1) {
            int rightRightHeight = height(pRoot->getRight()->getRight());
            int rightLeftHeight = height(pRoot->getRight()->getLeft());

            if (rightRightHeight >= rightLeftHeight) {
                return rotateLeft(pRoot);
            }
            else {
                pRoot->setRight(rotateRight(pRoot->getRight()));
                return rotateLeft(pRoot);
            }
        }
        return pRoot;
    }

    int height (BSTNode<T>* pRoot) {
        if (pRoot ==  nullptr) {
            return 0;
        }
        if (pRoot->isLeaf()) {
            return 1;
        }
        int leftHeight = height(pRoot->getLeft());
        int rightHeight = height(pRoot->getRight());

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }


    BSTNode<T>* rotateRight(BSTNode<T>* pRoot) {
        if (pRoot == nullptr) {
            throw runtime_error("Can't rotate right on null.");
        }
        if (pRoot->getLeft() ==  nullptr) {
            throw runtime_error("Can't rotate right with null left child.");
        }
        BSTNode<T> *newRoot = pRoot->getLeft();
        pRoot->setLeft(newRoot->getRight());
        newRoot->setRight(pRoot);
        return newRoot;
    }

    BSTNode<T>* rotateLeft(BSTNode<T>* pRoot) {
        if (pRoot == nullptr) {
            throw runtime_error("Can't rotate left on null.");
        }
        if (pRoot->getRight() ==  nullptr) {
            throw runtime_error("Can't rotate left with null right child.");
        }
        BSTNode<T> *newRoot = pRoot->getRight();
        pRoot->setRight(newRoot->getLeft());
        newRoot->setLeft(pRoot);
        return newRoot;
    }

    T findAux(BSTNode<T>* pRoot, T element) {
        if (pRoot == nullptr) {
            throw runtime_error("Element not found");
        }
        if (element == pRoot->getElement()) {
            return pRoot->getElement();
        }
        if (element < pRoot->getElement()) {
            return findAux(pRoot->getLeft(), element);
        }
        else{
            return findAux(pRoot->getRight(), element);
        }
    }

    BSTNode<T>* removeAux(BSTNode<T> *pRoot, T element) {
        if (pRoot == nullptr) {
            throw runtime_error("Element not found");
        }
        if (element < pRoot->getElement()) {
            pRoot->setLeft(removeAux(pRoot->getLeft(), element));
            return rebalanceRight(pRoot);
        }
        if (element > pRoot->getElement()) {
            pRoot->setRight(removeAux(pRoot->getRight(), element));
            return rebalanceLeft(pRoot);
        }
        else {
            if (pRoot->isLeaf()) {
                delete pRoot;
                return nullptr;
            }

            if (pRoot->childrenCount() == 1) {
                BSTNode<T> *temp = pRoot->getUniqueChild();
                delete pRoot;
                return temp;
            }

            else {
                BSTNode<T> *succesor = getSuccesor(pRoot);
                swap(pRoot, succesor);
                pRoot->setRight(removeAux(pRoot->getRight(), element));
                return pRoot;
            }
        }
    }

    void swap (BSTNode<T> *node1, BSTNode<T> *node2) {
        T temp = node1->getElement();
        node1->setElement(node2->getElement());
        node2->setElement(temp);
    }

    BSTNode<T> *getSuccesor(BSTNode<T> *pRoot) {
        return getSuccesorAux(pRoot->getRight());
    }

    BSTNode<T>* getSuccesorAux(BSTNode<T> *pRoot) {
        if (pRoot == nullptr) {
            return nullptr;
        }
        if (pRoot->getLeft() == nullptr) {
            return pRoot;
        }
        else {
            return getSuccesorAux(pRoot->getLeft());
        }
    }

    bool containAux(BSTNode<T> *pRoot, T element) {
        if (pRoot == nullptr) {
            return false;
        }
        if (element == pRoot->getElement()) {
            return true;
        }
        if (element < pRoot->getElement()) {
            return containAux(pRoot->getLeft(), element);
        }
        else {
            return containAux(pRoot->getRight(), element);
        }

    }

    void clearAux(BSTNode<T>* pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        clearAux(pRoot->getLeft());
        clearAux(pRoot->getRight());
        delete pRoot;
    }

    void getElementsAux(BSTNode<T> *pRoot, List<T> *elements) {
        if (pRoot == nullptr) {
            return;
        }
        getElementsAux(pRoot->getLeft(), elements);
        elements->append(pRoot->getElement());
        getElementsAux(pRoot->getRight(), elements);
    }

    int getSizeAux(BSTNode<T> *pRoot) {
        if (pRoot == nullptr) {
            return 0;
        }
        return 1 + getSizeAux(pRoot->getLeft()) + getSizeAux(pRoot->getRight());
    }

    void printAux(BSTNode<T>* pRoot, int depth) {
        if (pRoot == nullptr) {
            return;
        }
        for (int i = 0; i < depth; i++) {
            std::cout << "  ";
        }
        std::cout << "+-" << pRoot->getElement() << std::endl;
        printAux(pRoot->getLeft(), depth + 1);
        printAux(pRoot->getRight(), depth + 1);
    }


public:

    AVLTree() {
        root = nullptr;
    }

    ~AVLTree() {
        clear();
    }

    void insert(T element) {
        root = insertAux(root, element);
    }

    T find(T element) {
        return findAux(root, element);
    }

    T remove(T element) {
        T result = find(element);
        root = removeAux(root, element);
        return result;
    }

        bool contains(T element) {
        return containAux(root, element);
    }

    void clear() {
        clearAux(root);
        root = nullptr;
    }

    //El codigo que llama a getElements debe hacer el delete de esto

    List<T> *getElements() {
        List<T> *elements = new DLinkedList<T>();
        getElementsAux(root, elements);
        return elements;
    }

    int getSize() {
        return getSizeAux(root);
    }

     void print() {
        printAux(root, 0);
    }

};

#endif // AVLTREE_H
