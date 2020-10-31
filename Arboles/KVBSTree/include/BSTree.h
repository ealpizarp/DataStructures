#ifndef BSTREE_H
#define BSTREE_H
#include "BSTNode.h"
#include <stdexcept>

using namespace std;

template <typename Key, typename E>
class BSTree
{
private:
    BSTNode<Key, E>* root;

    // Función auxiliar de inOrder()
    // Realiza un recorrido inOrder imprimiendo en consola
    void inOrderAux(BSTNode<Key, E>* pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        inOrderAux(pRoot->getLeft());
        cout << pRoot->getElement() << " ";
        inOrderAux(pRoot->getRight());
    }
    // Función auxiliar de insert()
    // Inserta un nuevo par llave-valor en el árbol.
    // Retorna un puntero al árbol modificado.
    BSTNode<Key, E>* insertAux(BSTNode<Key, E>* pRoot, Key pKey, E pElement) {
        if (pRoot == nullptr) {
            return new BSTNode<Key, E>(pKey, pElement);
        }
        if (pKey < pRoot->getKey()) {
           pRoot->setLeft(insertAux(pRoot->getLeft(), pKey, pElement));
        }
        else {
           pRoot->setRight(insertAux(pRoot->getRight(), pKey, pElement));
        }
        return pRoot;
    }
    // Función auxiliar de find()
    // Busca el nodo con la llave indicada y retorna su valor.
    // Lanza una excepción si no se encuentra.
    E findAux(BSTNode<Key, E>* pRoot, Key pKey) {
        if (pRoot == nullptr) {
            throw runtime_error("Key not found.");
        }
        if (pKey == pRoot->getKey()) {
            return pRoot->getElement();
        }
        if (pKey < pRoot->getKey()) {
            return findAux(pRoot->getLeft(), pKey);
        }
        else {
            return findAux(pRoot->getRight(), pKey);
        }
    }
    // Función auxiliar de remove()
    // Elimina el nodo con la llave indicada.
    // Lanza excepción si el nodo no se encuentra.
    BSTNode<Key, E>* removeAux(BSTNode<Key, E>* pRoot, Key pKey) {
        if (pRoot == nullptr) {
            throw runtime_error("Key not found.");
        }
        if (pKey < pRoot->getKey()) {
            pRoot->setLeft(removeAux(pRoot->getLeft(),pKey));
            return pRoot;
        }
        if (pKey > pRoot->getKey()) {
            pRoot->setRight(removeAux(pRoot->getRight(), pKey));
            return pRoot;

        } else {
            if (pRoot->isLeaf()) {
                delete pRoot;
                return nullptr;
            }
            if (pRoot->childrenCount() == 1) {
                BSTNode<Key, E> *temp = pRoot->getUniqueChild();
                delete pRoot;
                return temp;
            }
            else {
                BSTNode<Key, E> *succesor = pRoot->getSuccessor();
                swap(pRoot, succesor);
                pRoot->setRight(removeAux(pRoot->getRight(), pKey));
                return pRoot;
            }
        }
    }
    // Intercambia la llave y elemento de dos nodos indicados.
    void swap(BSTNode<Key, E>* pNode1, BSTNode<Key, E>* pNode2) {
        Key tempK = pNode1->getKey();
        E tempE = pNode1->getElement();
        pNode1->setKey(pNode2->getKey());
        pNode1->setElement(pNode2->getElement());
        pNode2->setKey(tempK);
        pNode2->setElement(tempE);
    }

public:
    BSTree() {
        root = nullptr;
    }

    ~BSTree(){
        //clear();
    }
    // Inserta un nuevo par llave-valor en el árbol.
    void insert(Key pKey, E pElement) {
        root = insertAux(root, pKey, pElement);
    }
    // Imprime el recorrido inOrder en la consola.
    void inOrder() {
        inOrderAux(root);
        cout << endl;
    }
    // Retorna el elemento asociado a la llave indicada.
    // Lanza excepción si no lo encuentra.
    E find(Key pKey) {
        return findAux(root, pKey);
    }
    // Elimina el elemento asociado a la llave indicada.
    // Lanza excepción si no lo encuentra.
    E remove(Key pKey) {
        E result = find(pKey);
        root = removeAux(root, pKey);
        return result;
    }
};

#endif // BSTREE_H
