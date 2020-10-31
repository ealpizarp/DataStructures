#ifndef TRIE_H
#define TRIE_H
#include<string>
#include<stdexcept>
#include "TrieNode.h"

using std::runtime_error;

using std::string;

class Trie {

private:
    TrieNode* root;

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
    }
    /*
    bool containsWord(string word) {
        TrieNode* current = root;
        for (unsigned int i = 0; i < word.size(); i++) {
            if(!current->contains(word[i])) {
                return false;
            }
            current = current->getChild(word[i]);
        }
        return current->getIsFinal();
    }

    bool containsPrefix(string prefix) {
        TrieNode* current = root;
        for (unsigned int i = 0; i < word.size(); i++) {
            if(!current->contains(word[i])) {
                return false;
            }
            current = current->getChild(word[i]);
        }
        return true;
    }
    */

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


    void clear() {
        clearAux(root);
        root = new TrieNode();
    }




};

#endif // TRIE_H
