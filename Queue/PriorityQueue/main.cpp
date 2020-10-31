#include <iostream>
#include"LinkedPriorityQueue.h"
#include <string>
#include<time.h>
#include<cstdlib>

using namespace std;

int main()
{
    PriorityQueue<string> * Q = new LinkedPriorityQueue<string>(10);
    srand(time(0));

    for(int i=0; i< 100; i++){
        if(rand() % 2 == 0  && !Q->isEmpty()) {
        cout<<"removeMin(): "<<Q->removeMin()<<endl;
        }
        else{
            int r = rand();
            int priority = r % 10;
            string value = to_string(r);
            Q->insert(value, priority);
            cout<<"Insert( "<<value<<", "<<priority<<")"<<endl;
            cout<<Q->isEmpty();
        }
    }


    delete Q;
    return 0;
}
