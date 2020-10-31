#include <iostream>
#include "DLinkedList.h"
#include<time.h>

using namespace std;

int main()
{
        int opc;
        int aux;
        DLinkedList<int> Dll;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"             Bienvenid@ a la parte de listas doblemente enlazadas!            "<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;

        cout<<"Digite cuantos elementos desea insertarle a la lista: "; cin>> opc;


        for(int i=0; i<opc; i++){
            cout<<"Inserte el elemento"<<"["<<i<<"]  "; cin>>aux;
            Dll.append(aux);
        }
        Dll.goToStart();
        for(int i=0; i<Dll.getSize(); i++){
            cout<<Dll.getElement()<<" ";
            Dll.next();
        }
        cout<<endl<<"Elementos insertados exitosamente..."<<endl;
        system("PAUSE");
        cout<<"Ahora vamos a ordenar los elementos..."<<endl;
        Dll.sort();
        Dll.goToStart();
            for(int i=0; i<Dll.getSize(); i++){
            cout<<Dll.getElement()<<" ";
            Dll.next();
        }
        cout<<endl;
        system("PAUSE");
        system("cls");
        Dll.clear();
        cout<<"Ahora vamos a realizar una prueba masiva..."<<endl;
        srand (time(NULL));
        cout<<"Inserte el rango de numeros que desea agregar a la lista "; cin>> aux;
            for(int i=0; i<aux; i++){
            Dll.append(rand() % 100);
            }

        cout<<"Esta es la lista doblemente enlazada que ingreso..."<<endl;
        Dll.goToStart();
        for(int i=0; i<Dll.getSize(); i++){
            cout<<Dll.getElement()<<" ";
            Dll.next();
        }
        cout<<endl;
        system("PAUSE");
        cout<<"Ahora vamos a ordenarla..."<<endl;
        system("PAUSE");
        Dll.sort();
        Dll.goToStart();
        for(int i=0; i<Dll.getSize(); i++){
            cout<<Dll.getElement()<<" ";
            Dll.next();
        }
        cout<<endl;
        cout<<"Hasta Luego!"<<endl;

}
