#include <iostream>
#include "DLinkedList.h"

using namespace std;

int main()
{

    int array[6];
    array[0]= 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;
    array[6] = 7;

    for (int i = 0 ; i< 7; i++){
        cout<<array[i]<<endl;
    }
    system("pause");

    int opc;
    int aux;
    DLinkedList<int> Dll;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"             Bienvenido a la parte de listas doblemente enlazadas             "<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;

    cout<<"Digite cuantos elementos desea insertarle a la lista: "; cin>> opc;


    for(int i=0; i<opc; i++){
        cout<<"Inserte el elemento"<<"["<<i<<"] "; cin>>aux;
        Dll.append(aux);
    }

    Dll.goToStart();
    for(int i=0; i<Dll.getSize(); i++){
        cout<<Dll.getElement()<<" ";
        Dll.next();
    }
    cout<<endl;
    cout<<"Elementos insertados exitosamente"<<endl;
    system("PAUSE");
    system("cls");

    cout<<"Ahora vamos a ordenar los elementos"<<endl;

    Dll.sort();

    Dll.goToStart();

        for(int i=0; i<Dll.getSize(); i++){
        cout<<Dll.getElement()<<" ";
        Dll.next();
    }
}
