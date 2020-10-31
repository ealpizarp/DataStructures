#ifndef KVPAIR_H
#define KVPAIR_H
#include <iostream>

using std::ostream;

template <typename K, typename V>
class KVPair {
private:
    K key;
    V value;
public:
    KVPair() {}
    KVPair(K key) {
        this->key = key;
    }
    KVPair(K key, V value) {
        this->key = key;
        this->value = value;
    }
    void operator= (const KVPair &other) {
        key = other.key;
        value = other.value;
    }
    bool operator== (const KVPair &other) {
        return key == other.key;
    }
    bool operator!= (const KVPair &other) {
        return key != other.key;
    }
    bool operator< (const KVPair &other) {
        return key < other.key;
    }
    bool operator<= (const KVPair &other) {
        return key <= other.key;
    }
    bool operator> (const KVPair &other) {
        return key > other.key;
    }
    bool operator>= (const KVPair &other) {
        return key >= other.key;
    }
    void setKey(K key) {
        this->key = key;
    }
    K getKey() const { // el const es necesario para poder sobrescribir el operador <<
        return key;
    }
    void setValue(V value) {
        this->value = value;
    }
    V getValue() const { // el const es necesario para poder sobrescribir el operador <<
        return value;
    }
};

// Esta función "solitaria" sirve para sobrescribir el funcionamiento
// del operador << con el KVPair.
// Aparentemente no se puede sobrescribir desde dentro de la clase
// y hay que hacerlo en una función aparte.
template<typename K, typename V>
ostream& operator<<(ostream& os, const KVPair<K, V>& p) {
    os << p.getKey() << ", " << p.getValue();
    return os;
}
#endif // KVPAIR_H
