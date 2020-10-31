#include <iostream>
#include "DLinkedList.h"

using namespace std;

int main()
{
    int opc;
    int aux;
    DLinkedList<int> Dll;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"             Bienvenido a la parte de listas doblemente enlazadas             "<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;

    cout<<"Digite cuantos elementos desea insertarle a la lista "; cin>> opc;


    for(int i=0; i<opc; i++){
        cout<<"Inserte el elemento"<<"["<<i<<"] "; cin>>aux;
        Dll.append(aux);
    }

    Dll.goToStart();
    for(int i=0; i<Dll.getSize(); i++){
        cout<<Dll.getElement()<<" ";
        Dll.next();
    }
    cout<<"Elementos insertados exitosamente"<<endl;


    cout<<"Ahora vamos a ordenar los elementos"<<endl;

    Dll.sort();

    Dll.goToStart();

        for(int i=0; i<Dll.getSize(); i++){
        cout<<Dll.getElement()<<" ";
        Dll.next();
    }
}
