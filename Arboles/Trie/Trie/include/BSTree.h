#ifndef BSTREE_H
#define BSTREE_H

#include<stdexcept>
#include"BSTNode.h"
#include"list.h"
#include"DLinkedList.h"

using std::runtime_error;

template<typename T>

class BSTree {
private:
    BSTNode<T> *root;

    BSTNode<T>* insertAux(BSTNode<T> *pRoot, T element) {                //La p de proot significa parametro
        if (pRoot == nullptr){
            return new BSTNode<T>(element);
        }
        else if (element < pRoot->getElement()) {
            pRoot->setLeft(insertAux(pRoot->getLeft(), element));
        }
        else if (element > pRoot->getElement()) {
            pRoot->setRight(insertAux(pRoot->getRight(), element));
        }
        else {
            throw runtime_error("Duplicated Key");
        }
        return pRoot;
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
            return pRoot;
        }
        if (element > pRoot->getElement()) {
            pRoot->setRight(removeAux(pRoot->getRight(), element));
            return pRoot;
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

public:
    BSTree(){
        root = nullptr;
    }

    ~BSTree(){
        clear();
    }

    void insert(T element){
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

    /*bool contains(T element) {
        try {
            find(element);
            return true;
        }
        catch (runtime_error &e) {
            return false;
        }
    }
    */

    bool contains(T element) {
        return containAux(root, element);
    }

    void clear() {
        clearAux(root);
        root = nullptr;
    }

    List<T> *getElements() {
        List<T> *elements = new DLinkedList<T>();                  //El codigo que llama a getElements debe hacer el delete de esto
        getElementsAux(root, elements);
        return elements;
    }

    int getSize() {
        return getSizeAux(root);
    }

};

#endif // BSTREE_H
