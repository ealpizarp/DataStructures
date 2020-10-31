#ifndef HEAPNODE_H
#define HEAPNODE_H

template <typename Key, typename E>
class HeapNode
{
private:
    Key key;
    E element;

public:
    HeapNode() {}

    HeapNode(Key key){
        this->key=key;
    }

    HeapNode(Key key, E element){
    this->key = key;
    this->element = element;
    }

    ~HeapNode() {}

    Key getKey() {
        return key;
    }
    void setKey(Key pKey) {
        key = pKey;
    }
    E getElement() {
        return element;
    }
    void setElement(E pElement) {
        element = pElement;
    }
    void operator= (const HeapNode &other){
    key = other.key;
    element = other.element;
    }
    bool operator==(const HeapNode &other){
        return key == other.key;
    }
    bool operator!= (const HeapNode &other){
        return key != other.key;
    }
    bool operator< (const HeapNode &other){
        return key < other.key;
    }
    bool operator<= (const HeapNode &other){
        return key <= other.key;
    }
    bool operator> (const HeapNode &other){
        return key > other.key;
    }
    bool operator>= (const HeapNode &other){
        return key >= other.key;
    }
};

#endif // HEAPNODE_H
