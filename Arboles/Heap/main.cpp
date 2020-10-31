#include <iostream>
#include"MinHeap.h"
#include<cstdlib>
#include<time.h>

using namespace std;

int main()
{
    MinHeap<int> heap;
    srand(time(0));

    for (int i=0; i < 100; i++){
        heap.insert(rand());
    }
    while (heap.getSize() > 0){
        cout<<heap.removeFirst()<<" ";
    }
    cout<<endl;
    return 0;
}
