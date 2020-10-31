#ifndef KVPAIR_H
#define KVPAIR_H

template <typename K, typename V>
class KVPair {
private:
    K key;
    V value;

public:
    KVPair(){};              //Es importante tener el constructor vacio
    KVPair(K key){
        this->key=key;
    }
    KVPair(K key, V value){
    this->key = key;
    this->value = value;
    }
    K getKey(){
    return key;
    }
    void setKey(K key){
    this->key=key;
    }
    V getValue(){
    return value;
    }
    void setValue(V value){
    this->value=value;
    }
    void operator= (const KVPair &other){
    key = other.key;
    value = other.value;
    }
    bool operator==(const KVPair &other){
        return key == other.key;
    }
    bool operator!= (const KVPair &other){
        return key != other.key;
    }
    bool operator< (const KVPair &other){
        return key < other.key;
    }
    bool operator<= (const KVPair &other){
        return key <= other.key;
    }
    bool operator> (const KVPair &other){
        return key > other.key;
    }
    bool operator>= (const KVPair &other){
        return key >= other.key;
    }

};

#endif // KVPAIR_H
