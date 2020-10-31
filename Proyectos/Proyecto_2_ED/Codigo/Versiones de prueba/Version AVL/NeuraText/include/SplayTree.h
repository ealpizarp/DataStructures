#ifndef SPLAYTREE_H
#define SPLAYTREE_H
#include "BSTNode.h"
#include<stdexcept>
#include<cmath>
#include<iostream>


template<typename T>
class SplayTree {
private:
    BSTNode<T>* root;

    void inOrderAux(BSTNode<T>* pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        inOrderAux(pRoot->getLeft());
        std::cout<< pRoot->getElement() << " ";
        inOrderAux(pRoot->getRight());
    }

    void preOrderAux(BSTNode<T>* pRoot) {
        if (pRoot ==  nullptr) {
            return;
        }
        std::cout<< pRoot->getElement() << " ";
        preOrderAux(pRoot->getLeft());
        preOrderAux(pRoot->getRight());
    }

   BSTNode<T>* insertAux(BSTNode<T> *pRoot, T element) {
        if (pRoot == nullptr){
            return new BSTNode<T>(element);
        }
        if (element < pRoot->getElement()) {
            pRoot->setLeft(insertAux(pRoot->getLeft(), element));
        }
        else {
            pRoot->setRight(insertAux(pRoot->getRight(), element));
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

    void splay(BSTNode<T>* pRoot) {
        while(pRoot != root) {
        pRoot = splayAux(pRoot);
        }
    }

    BSTNode<T>* splayAux(BSTNode<T>* pRoot) {
        if(root == pRoot) {
            return root;
        }

        if(root->getLeft() ==  pRoot) {
            root = rotateRight(root);
            return root;
        }

        if(root->getRight() == pRoot) {
            root = rotateLeft(root);
            return root;
        }

        BSTNode<T>* grandParent = findParent(findParent(pRoot));

        if (grandParent == root) {
            root = zigZag(pRoot, root);
            return root;
        }
        else {
            BSTNode<T>* greatGrandParent = findParent(grandParent);
            if (greatGrandParent->getLeft() == grandParent) {
                greatGrandParent->setLeft(zigZag(pRoot, grandParent));
                return greatGrandParent->getLeft();
            } else {
                greatGrandParent->setRight(zigZag(pRoot, grandParent));
                return greatGrandParent->getRight();
            }
        }
    }

    BSTNode<T>* zigZag(BSTNode<T>* pRoot, BSTNode<T>* pGrandParent) {
        BSTNode<T>* result;
        if (pGrandParent->getLeft() != nullptr) {
            if (pGrandParent->getLeft()->getLeft() == pRoot) {
                result = rotateRight(pGrandParent);
                result = rotateRight(result);
                return result;
            }
            if (pGrandParent->getLeft()->getRight() == pRoot) {
                pGrandParent->setLeft(rotateLeft(pGrandParent->getLeft()));
                result = rotateRight(pGrandParent);
                return result;
            }
        }

        if (pGrandParent->getRight() != nullptr) {
            if (pGrandParent->getRight()->getRight() == pRoot) {
                result = rotateLeft(pGrandParent);
                result = rotateLeft(result);
                return result;
            }
            if (pGrandParent->getRight()->getLeft() == pRoot) {
                pGrandParent->setRight(rotateRight(pGrandParent->getRight()));
                result = rotateLeft(pGrandParent);
                return result;
            }
        }
        return nullptr;
    }

    BSTNode<T> *findParent(BSTNode<T>* pChild) {
        if (pChild == nullptr) {
            throw runtime_error("null node cannot have a parent");
        }
        if (pChild ==  root) {
            throw runtime_error("Root node cant have a parent");
        }
        return findParentAux(root, pChild);
    }

    BSTNode<T>* findParentAux(BSTNode<T> * pRoot, BSTNode<T>* pChild) {
        if (pRoot->getLeft() == pChild) {
            return pRoot;
        }
        if (pRoot->getRight() == pChild) {
            return pRoot;
        }
        if (pChild->getElement() < pRoot->getElement()) {
            return findParentAux(pRoot->getLeft(), pChild);
        } else {
            return findParentAux(pRoot->getRight(), pChild);
        }
    }

    BSTNode<T>* findNode(T element) {
        return findNodeAux(root, element);
    }

    BSTNode<T>* findNodeAux(BSTNode<T> *pRoot, T element) {
        if(pRoot ==  nullptr) {
            return nullptr;
        }
        if (element == pRoot->getElement()) {
            return pRoot;
        }
        if (element < pRoot->getElement()) {
            return findNodeAux(pRoot->getLeft(), element);
        }
        else {
            return findNodeAux(pRoot->getRight(), element);
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



public:
    SplayTree() {
        root = nullptr;
    }
    ~SplayTree() {
        clearAux(root);
    }
    void insert(T element) {
        root = insertAux(root, element);
        BSTNode<T>* newNode = findNode(element);
        splay(newNode);
    }

    void inOrder() {
        inOrderAux(root);
        std::cout<<std::endl;
    }

    void preOrder() {
        preOrderAux(root);
        std::cout<<std::endl;
    }

    T find(T element) {
        return findAux(element);
    }

    T remove(T element) {
        BSTNode<T>* toDelete = findNode(element);
        T result = toDelete->getElement();
        if (toDelete != root) {
            BSTNode<T> * parent = findParent(toDelete);
            root = removeAux(root, element);
            splay(parent);
        } else {
            root = removeAux(root, element);
        }
        return result;
    }

    void printRootValue () {
        std::cout << root->getElement() << std::endl;
    }

    T search(T element) {
        BSTNode<T>* result = findNode(element);
        splay(result);
        return root->getElement();
    }

    bool contains(T element) {
        BSTNode<T>* result = findNode(element);
        if (result ==  nullptr) {
            return false;
        }
        else {
            splay(result);
            return true;
        }
    }

    void clear() {
        clearAux(root);
        root = nullptr;
    }



};

#endif // SPLAYTREE_H
