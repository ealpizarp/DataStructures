#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Dictionary.h"
#include "KVPair.h"
#include "LinkedList.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

using namespace std;

template <typename K, typename V>
class HashTable : public Dictionary<K, V> {
private:
    LinkedList<KVPair<K, V> > *buckets;
    int nbuckets;

    int h(K key) {
        return compress(hashCodePolynomial(key));
    }
    // Genera un c�digo hash polinomial con constante de 33
    int hashCodePolynomial(K pKey) {
        int a = 33;
        int result = 0;
        char* bytes =reinterpret_cast<char*>(& pKey);
        for(unsigned int i = 0; i < sizeof(K); i++) {
            result += bytes[i] * pow(a, i);
        }
        return result;

    }
    // Genera un c�digo hash con corrimiento c�clico con corrimientos
    // de 7 hacia la izquierda y 25 a la derecha. Usa XOR para unir
    // los bits.
    template <typename T>
    int hashCodeCyclicShift(T pKey) {
        int result = 0;
        char* bytes = reinterpret_cast<char*>(&pKey);
        for (unsigned int i = 0; i < sizeof(pKey); i++) {
            result = (result << (7)) ^ (result >> (25));
            result += (int) bytes[i];
        }
        return result;
    }
    int hashCodeCyclicShift(string pKey) {
        int result = 0;
        for (unsigned int i = 0; i < pKey.length(); i++) {
            result = (result << (7)) ^ (result >> (25));
            result += (int) pKey.at(i);
        }
        return result;
    }
    // Funci�n de compresi�n por multiplicaci�n, suma y divisi�n
    int compress(int pHashCode) {
        int a = 1097;
        int b = 1279;
        return abs(a * pHashCode + b) % nbuckets;
        // COMPLETAR

        return 0;
    }
    // Funci�n que dibuja los bits de un entero, para prop�sitos
    // de prueba
    void printBits(int n) {
        int value = n;
        string result = "";
        for (int i = 0; i < 32; i++) {
            result = (value % 2? "o" : "_") + result;
            value = value / 2;
        }
        cout << result << endl;
    }
    // M�todo auxiliar que verifica que una llave no exista.
    // Si se encuentra la llave, lanza exepci�n.
    void checkNotExisting(K key) throw (runtime_error) {
        int pos = h(key);
        if (buckets[pos].contains(key))
            throw runtime_error("Duplicated key.");
    }
    // M�todo auxiliar que verifica que una llave s� exista.
    // Si no se encuentra la llave, lanza excepci�n
    void checkExisting(K key) throw (runtime_error) {
        int pos = h(key);
        if (!buckets[pos].contains(key)) {
            throw runtime_error("Key not found.");
        }
    }

public:
    HashTable(int nbuckets = 1021) {
        buckets = new LinkedList<KVPair<K, V> >[nbuckets];
        this->nbuckets = nbuckets;
    }
    ~HashTable() {
        delete [] buckets;
    }
    void insert(K key, V value) {
        checkNotExisting(key);
        KVPair<K,V> p(key,value);
        buckets[h(key)].append(p);
        // COMPLETAR

    }
    V remove(K key) {
        checkNotExisting(key);
        KVPair<K,V> p(key);
        int pos = h(key);
        int listpos = buckets[pos].indexOf(p);
        buckets[pos].goToPos(listpos);
        p = buckets[pos].remove();
        return p.getValue();
    }
    V getValue(K key) {
        checkExisting(key);
        int pos = h(key);
        KVPair<K, V> p(key);
        int listPos = buckets[pos].indexOf(p);
        buckets[pos].goToPos(listPos);
        p = buckets[pos].getElement();
        return p.getValue();
    }
    void setValue(K key, V value) {
        checkExisting(key);
        int pos = h(key);
        KVPair<K, V> p(key);
        int listPos = buckets[pos].indexOf(p);
        buckets[pos].goToPos(listPos);
        buckets[pos].remove();
        p.setValue(value);
        buckets[pos].indexOf(p);
        // COMPLETAR

    }
    void clear() {
        for (int i = 0; i < nbuckets; i++) {
            buckets[i].clear();
        }
    }
    bool contains(K key) {
        return buckets[h(key)].contains(key);
    }
    List<K>* getKeys() {
        List<K> *keys = new LinkedList<K>();
        for (int i = 0; i < nbuckets; i++) {
            buckets[i].goToStart();
            while (!buckets[i].atEnd()) {
                KVPair<K, V> p;
                p = buckets[i].getElement();
                keys->append(p.getKey());
                buckets[i].next();
            }
        }
        return keys;
    }
    List<V>* getValues() {
        List<V> *values = new LinkedList<V>();
        for (int i = 0; i < nbuckets; i++) {
            buckets[i].goToStart();
            while (!buckets[i].atEnd()) {
                KVPair<K, V> p;
                p = buckets[i].getElement();
                values->append(p.getValue());
                buckets[i].next();
            }
        }
        return values;
    }
    int getSize() {
        int size = 0;
        for (int i = 0; i < nbuckets; i++) {
            size += buckets[i].getSize();
        }
        return size;
    }
};

#endif // HASHTABLE_H
