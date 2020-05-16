#ifndef UNSORTEDARRAYDICTIONARY_H
#define UNSORTEDARRAYDICTIONARY_H

#include "Dictionary.h"
#include "KVPair.h"
#include "DlinkedList.h"
#include "ArrayList.h"

template <typename K, typename V>

class UnsortedArrayDictionary : public Dictionary<K, V> {

private:
    ArrayList<KVPair<K,V> > *pairs;    //Nota: Es importante notar que preferiblemente se deja un espacio entre  ArrayList<KVPair<K,VV> > ya que el compilador se puede confundior
    void checkNotExisting(K key){
        if(contains(key))
            throw runtime_error("Duplicated Key.");
    }
    void checkExisting(K key){
        if(!contains(key))
            throw runtime_error("Key not found.");
    }

public:
    UnsortedArrayDictionary(int max = MAX_SIZE) {   //Para inicializarlo de manera estatica seria utilizando : pairs(max)
    pairs = new ArrayList<KVPair<K,V> >(max);
    }

    ~UnsortedArrayDictionary() {
    delete pairs;
    }

    void insert(K key, V value){
        checkNotExisting(key);
        KVPair<K, V> p(key, value);
        pairs->append(p);
    }

    V remove(K key){
        checkExisting(key);
        KVPair<K, V> p = pairs->remove();
        return p.getValue();    // return pairs->getElement().getValue(); train wreck. No es recomendable
    }

    V getValue(K key){
        checkExisting(key);
        KVPair<K, V> p = pairs->getElement();
        return p.getValue();
    }

    void setValue(K key, V value){
        checkExisting(key);
        KVPair<K, V> p(key, value);
        pairs->remove();
        pairs->append(p);
    }

    void clear(){
        pairs->clear();
    }

    bool contains(K key){
        KVPair<K, V> p(key);
        for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
            if(p == pairs->getElement())
                return true;
        }
        return false;
    }

    List<K>* getKeys(){
        List<K>* keys = new DLinkedList<K>();
        for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
            KVPair<K,V> p = pairs->getElement();
            keys->append(p.getKey());
        }
        return keys;
    }

    List<V>* getValues(){
        List<V>* values = new DLinkedList<V>();
        for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
            KVPair<K,V> p = pairs->getElement();
            values->append(p.getValue());
        }
        return values;
    }

    int getSize(){
    return pairs->getSize();
    }


};

#endif // UNSORTEDARRAYDICTIONARY_H
