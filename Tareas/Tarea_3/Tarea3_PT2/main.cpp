#include <iostream>
#include"DCircleList.h"
#include"DLinkedList.h"
#include<time.h>
#include<limits>
using namespace std;

int main()
{
    DCircleList<int> DCLL;

    int opc=0;
    int aux=0;
    bool band;
    bool reverse;

    cout<<"Digite cuantos elementos desea insertarle a la lista circular: "; cin>> opc;


    for(int i=0; i<opc; i++){
        cout<<"Inserte el elemento"<<"["<<i<<"] "; cin>>aux;
        DCLL.insert(aux);
    }



    cout<<"Esta es la lista circular doblemente enlazada insertada..."<<endl;
      for(int i=0; i<DCLL.getSize(); i++){
        cout<<DCLL.getFront()<<" ";
        DCLL.next();
    }
    cout<<endl;

    cout<< "Ahora vamos a remover el elemento con valor de "<<DCLL.remove()<<endl;
          for(int i=0; i<DCLL.getSize(); i++){
        cout<<DCLL.getFront()<<" ";
        DCLL.next();
    }
    cout<<endl;
    system("PAUSE");
    while(!band){
    cout<<"Desea hacer la lista circular doblemente enlazada derivada normal o inversa? "<<endl;
    cout<<"NORMAL                                                    1"<<endl;
    cout<<"INVERTIDA                                                 2"<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin>>opc;
    if(opc==1){ band=true; reverse = true;}
    else if(opc==2){ band=true; reverse =false; }
    else{ band = false;}
    }

     DLinkedList<int> * RDLL = DCLL.getElements(reverse);

     cout<<"Esta es la lista circular doblemente enlazada "; if(reverse) {cout<<"normal.."<<endl;} else{cout<<"invertida.."<<endl; }
        for(int i=0; i<RDLL->getSize(); i++){
        cout<<RDLL->getElement()<<" ";
        RDLL->next();
    }

    cout<<endl;
    system("PAUSE");
    system("cls");
    srand (time(NULL));

    DCLL.clear();
    cin.clear();

    cout<<"Ahora vamos a realizar una prueba masiva..."<<endl;

    cout<<"Inserte el rango de elementos que desea insertarle a la lista: "; cin>>opc;

     for(int i=0; i<opc; i++){
        DCLL.insert(rand()% 100);
    }

    cout<<"Esta es la lista circular doblemente enlazada insertada..."<<endl;

      for(int i=0; i<DCLL.getSize(); i++){
        cout<<DCLL.getFront()<<" ";
        DCLL.next();
    }
    cout<<endl;

    system("PAUSE");

    band=false;
   while(!band){
    cout<<"Desea hacer la lista circular doblemente enlazada derivada normal o inversa? "<<endl;
    cout<<"NORMAL                                                    1"<<endl;
    cout<<"INVERTIDA                                                 2"<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin>>opc;
    if(opc==1){ band=true; reverse = true;}
    else if(opc==2){ band=true; reverse =false; }
    else{ band = false;}
    }
    cout<<endl;

    DLinkedList<int> * RDLL1 = DCLL.getElements(reverse);

    cout<<"Esta es la lista circular doblemente enlazada "; if(reverse) {cout<<"normal.."<<endl;} else{cout<<"invertida.."<<endl; }

        for(int i=0; i<RDLL1->getSize(); i++){
        cout<<RDLL1->getElement()<<" ";
        RDLL1
        ->next();
    }
    cout<<endl;
    cout<<"Hasta Luego!"<<endl;







}


