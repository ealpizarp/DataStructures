/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File TRIE.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David Gonzales Agüero
*
*   Fecha de ultima modificación: 02/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene la implementacion de la estructura de datos Trie
*   o Arbol trie con varias modificaciones y funciones adicionales para el
*   funcionamiento especifico de neuratext.

********************************************************************************
*/

#ifndef TRIE_H
#define TRIE_H
#include<string>
#include<stdexcept>
#include "TrieNode.h"
#include "MaxHeap.h"
#include "HeapNode.h"
#include "ArrayList.h"

using std::runtime_error;

using std::string;

class Trie {

private:
    TrieNode* root;
    int size = 0;

    TrieNode* containsAux(string word) {
        TrieNode* current = root;
        for (unsigned int i = 0; i < word.size(); i++) {
            if(!current->contains(word[i])) {
                return nullptr;
            }
            current = current->getChild(word[i]);
        }
        return current;
    }

    void getMatchesAux(TrieNode* current, string prefix, List<string>* words) {
        if (current->getIsFinal()) {
            words->append(prefix);
        }
        List<char> *children = current->getChildren();
        for (children->goToStart(); !children->atEnd(); children->next()) {
            char c = children->getElement();
            string newPrefix = prefix;
            newPrefix.append(1,c);
            getMatchesAux(current->getChild(c), newPrefix, words);
        }
        delete children;
    }

    void clearAux(TrieNode* current) {
        List<TrieNode*>* pointers = current->getChildrenPointers();
        for (pointers->goToStart(); !pointers->atEnd(); pointers->next()){
            clearAux(pointers->getElement());
        }
        delete current;
    }

    void getDepthWordsAux(TrieNode* current, int depth, string depthWords, List<string>* words) {
        if (current->getIsFinal()) {
            words->append(depthWords);
        }
        if (depth != 0) {
        List<char> *children = current->getChildren();
        for (children->goToStart(); !children->atEnd(); children->next()) {

            char c = children->getElement();
            string newWord = depthWords;
            newWord.append(1, c);
            getDepthWordsAux(current->getChild(c), depth - 1, newWord, words);
        }
        delete children;
        }
    }

    void getMostFrequentWordsAux(TrieNode* current, string FrequentWords, MaxHeap<int, string>* maxheap) {
        if (current->getIsFinal()) {
            maxheap->insert(current->getFrequency(), FrequentWords);
        }
        List<char> *children = current->getChildren();
        for (children->goToStart(); !children->atEnd(); children->next()) {
            char c = children->getElement();
            string newFrequentWords = FrequentWords;
            newFrequentWords.append(1, c);
            getMostFrequentWordsAux(current->getChild(c), newFrequentWords, maxheap);
        }


    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear();
        delete root;
    }

    void insert(string word) {
        if(containsWord(word)) {
            throw runtime_error("Word already in trie");
        }
        TrieNode *current = root;
        for(unsigned int i = 0; i < word.size(); i++) {
            current->increaseCount();
            if (!current->contains(word[i])) {
                TrieNode *newNode = new TrieNode();
                current->add(word[i], newNode);
            }
            current = current->getChild(word[i]);
        }
        current->increaseCount();
        current->setIsFinal(true);
        size++;
    }

    void insertWithLine(string word, int line) {
        if(containsWord(word)) {
            throw runtime_error("Word already in trie");
        }
        TrieNode *current = root;
        for(unsigned int i = 0; i < word.size(); i++) {
            current->increaseCount();
            if (!current->contains(word[i])) {
                TrieNode *newNode = new TrieNode();
                current->add(word[i], newNode);
            }
            current = current->getChild(word[i]);
        }
        current->increaseCount();
        current->addLine(line);
        current->setIsFinal(true);
        size++;
    }

    bool containsWord(string word) {
        TrieNode* result = containsAux(word);
        if (result != nullptr) {
            return result->getIsFinal();
        }
        return false;
    }

    bool containsPrefix(string word) {
        TrieNode* result = containsAux(word);
        if (result != nullptr) {
            return true;
        }
        return false;
    }

    int prefixCount(string prefix) {
        TrieNode* current = root;
        for(unsigned int i = 0; i < prefix.size(); i++) {
            if (!current->contains(prefix[i])) {
                return 0;
            }
            current = current->getChild(prefix[i]);
        }
        return current->getPrefixCount();
    }

    void remove(string word) {
        if(!containsWord(word)) {
            throw runtime_error("Word not found");
        }
        TrieNode* current = root;
        for (unsigned int i = 0; i < word.size(); i++) {
            current->decreaseCount();
            TrieNode *child = current->getChild(word[i]);
            if (current->getPrefixCount() == 0) {
                delete current;
            }
            else if (child->getPrefixCount() == 1) {
                current->remove(word[i]);
            }
            current = child;
        }
        current->decreaseCount();
        if (current->getPrefixCount() == 0) {
            delete current;
        }
        else {
            current->setIsFinal(false);
        }
        size--;
    }

    void increaseWordFrequency(string word) {
        if(!containsWord(word)) {
            throw runtime_error("Word not found, cannot increase frequency");
        }
        TrieNode* current = root;
        for (unsigned int i = 0; i < word.size(); i++) {
            current = current->getChild(word[i]);
        }
        current->increaseFrecuency();
    }

    void addLine(string word, int line) {
        if(!containsWord(word)) {
            throw runtime_error("Word not found, cannot add line");
        }
        TrieNode* current = root;
        for (unsigned int i = 0; i < word.size(); i++) {
            current = current->getChild(word[i]);
        }
        current->addLine(line);
    }



    List<string>* getMatches(string prefix) {
        List<string> *words = new DLinkedList<string>();
        TrieNode* current =  root;
        for (unsigned int i = 0; i < prefix.size(); i++) {
            if (!current->contains(prefix[i])) {
                return words;
            }
            else {
                current = current->getChild(prefix[i]);
            }
        }
        getMatchesAux(current, prefix, words);
        return words;
    }

    List<string>* getDepthWords(int depth) {
        List<string> *words = new DLinkedList<string>();
        TrieNode* current = root;
        string depthWords = "";
        getDepthWordsAux(current, depth, depthWords,words);
        return words;
    }

    List<string>* getMostFrequentWords() {
        List<string>* words = new ArrayList<string>(size);
        MaxHeap<int, string>* maxheap = new MaxHeap<int, string>(size);
        TrieNode* current = root;
        string frequentWords = "";
        getMostFrequentWordsAux(current, frequentWords, maxheap);

        while (maxheap->getSize() > 0){
            HeapNode<int, string> temp = maxheap->removeFirst();
            words->append(temp.getElement());
        }
        delete maxheap;
        return words;
    }

    int getWordFrequency(string word) {
        TrieNode* result = containsAux(word);
        return result->getFrequency();
    }

    List<int>* getWordLines(string word) {
        TrieNode* result = containsAux(word);
        return result->getLines();

    }

    int getSize() {
        return size;
    }


    void clear() {
        clearAux(root);
        root = new TrieNode();
        size = 0;
    }




};

#endif // TRIE_H
