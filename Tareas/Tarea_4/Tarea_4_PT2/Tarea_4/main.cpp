#include <iostream>
#include"LinkedQueue.h"
#include"ArrayQueue.h"
#include <stdlib.h>
#include <time.h>
#include<string>

using namespace std;

void randomEnqueue(Queue<int>* cola, int cantidad){
    srand(time(0));
    for(int i=0; i< cantidad; i++){
    cola->enqueue(rand()%100);
    }
}

void userEnqueue(Queue<int>* cola, int cantidad){
    int element = 0;
    for(int i=0; i< cantidad; i++){
        cout<<"Digite el elemento ["<<i<<"] que desea ingresar "; cin>>element;
        cola->enqueue(element);
    }
}


void userEnqueueFront(Queue<int>* cola, int cantidad){
    int element = 0;
    for(int i=0; i< cantidad; i++){
        cout<<"Digite el elemento ["<<i<<"] que desea ingresar "; cin>>element;
        cola->enqueueFront(element);
    }
}

void MultipleDequeue(Queue<int>* cola, int cantidad){
    int element = 0;
    for(int i=0; i<cantidad; i++){
        cout<<cola->dequeue()<<" ";
    }
    cout<<endl;
}
void MultipleDequeueRear(Queue<int>* cola, int cantidad){
    int element = 0;
    for(int i=0; i<cantidad; i++){
        cout<<cola->dequeueRear()<<" ";
    }
    cout<<endl;
}

void imprimirInformacionCola(Queue<int>* cola){
     cout<<"Tamano de la cola: "<<cola->getSize()<<endl;
     cout<<"Esta es la cola actual: "; cola->print();
}

void menu(Queue<int>* AQ){

    int opc = 0;
   cout<<"-----------------------------------------------------------------"<<endl;
   cout<<"                      Bienvend@s a la parte 2                      "<<endl;
   cout<<"-----------------------------------------------------------------"<<endl;
   cout<<"Insertando 10 elementos a  la cola..."<<endl;
   userEnqueue(AQ, 10);
   AQ->print();
   cout<<"Los elementos fueron insertados correctamente"<<endl;
   system("PAUSE");
   cout<<"Ahora vamos a realizar 5 dequeues a la cola"<<endl;
   MultipleDequeue(AQ, 5);
   system("PAUSE");
   cout<<"Ahora realizemos unos 3 enqueue front"<<endl;
   userEnqueueFront(AQ, 3);
   AQ->print();
   cout<<"Esta es la cola actual"<<endl;
   system("PAUSE");
   cout<<"Perfecto, vamos a hacer un enqueue de 30 numeros aleatorios en la cola"<<endl;
   randomEnqueue(AQ, 30);
   AQ->print();
   cout<<"Esta es la cola que quedo despues de los 30 enqueues"<<endl;
   system("PAUSE");
   cout<<"Ahora vamos a hacer 15 dequeueRear..."<<endl;
   MultipleDequeueRear(AQ,15);
   system("PAUSE");
   cout<<"Muy bien, seguidamente vamos a ir al programa de CantidadOperaciones"<<endl;
   system("PAUSE");
   system("cls");
   cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<"                      Bienvend@s al programa personalizado de cantidad de operaciones                      "<<endl;
   cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<endl;
   AQ->clear();
   cout<<"Digite un numero entero"<<endl;
   cin>>opc;
   for(int i =0; i < opc; i++){

    if(rand()%4 == 0 && !AQ->isEmpty()){
        cout<<"dequeue(): "<< AQ->dequeue()<<endl;
        cout<<"Tamano de la cola: "<<AQ->getSize();
        cout<<"Esta es la cola actual:"; AQ->print();
    }
    else if(rand()%4 == 0 && !AQ->isEmpty()){
        cout<<"dequeueRear(): "<<AQ->dequeueRear()<<endl;
        imprimirInformacionCola(AQ);
    }
    else if(rand()%2 == 0){
         int r = rand()%100;
        cout<<"enqueueFront("<<r<<")"<<endl;
        AQ->enqueueFront(r);
        imprimirInformacionCola(AQ);
    }
    else{
        int r = rand()%100;
        AQ->enqueue(r);
        cout<<"enqueue("<<r<<")"<<endl;
        imprimirInformacionCola(AQ);
    }

   }



}

int main()
{
    Queue<int>* AQ = new ArrayQueue<int>();
    Queue<int>* LQ = new LinkedQueue<int>();

    cout<<"Vamos a probar primero la cola enlazada"<<endl;
    system("PAUSE");
    system("cls");
    menu(LQ);
    system("PAUSE");
    system("cls");
    cout<<"Ahora vamos a probar la cola de arreglos"<<endl;
    system("PAUSE");
    system("cls");
    menu(AQ);
}
