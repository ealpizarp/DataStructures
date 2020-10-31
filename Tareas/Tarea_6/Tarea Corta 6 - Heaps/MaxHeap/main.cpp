#include <iostream>
#include "include\MaxHeap.h"
#include <string>
#include<time.h>

using namespace std;

int main()
{

    MaxHeap<int> heap;
    srand(time(0));

    for (int i=0; i < 100; i++){
        heap.insert(rand());
    }
    while (heap.getSize() > 0){
        cout<<heap.removeFirst()<<" ";
    }
    cout<<endl;
    cout << "Such emptyness." << endl;
    return 0;
}
