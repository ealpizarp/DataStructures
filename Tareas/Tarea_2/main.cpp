#include <iostream>
#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "SortedArrayList.h"
#include "SortedLinkedList.h"
#include <time.h>

using namespace std;

int main()
{
    int value=0;
    int opc=0;
    ArrayList<int> arl;
    srand(time(0));
for(int i=0; i<1000; i++){
    arl.append(rand()%100);
}
cout<<"--------------------------------------------------------------------------"<<endl;
cout<<"                         BIENVENIDO A LA TAREA-2                          "<<endl;
cout<<"--------------------------------------------------------------------------"<<endl;
    arl.Print();
    cout<<"A que posicion desea ir?"; cin>>opc;
     arl.goToPos(opc);
     cout<<"El valor del elemento de la posicion es de: ";
     cout<<arl.getElement()<<endl;
     cout<<"Digite el numero que quiere probar si contiene: "; cin>>opc;
     if(arl.contains(opc)){
        cout<<"El numero que selecciono si esta contenido"<<endl;
     }
     else{
        cout<<"El numero que digito no esta contenido"<<endl;
     }

     cout<<"Ahora digite el numero al que le desea averiguar su posicion: "; cin>>opc;

     if(arl.indexOf(opc)==-1){
        cout<<"No existe este elemento"<<endl;
     }
     else{
     cout<<arl.indexOf(opc)<<endl;
     }

     arl.Print();

     cout<<"Ahora vamos a agragar una lista con parametros a la lista anterior, digite el tamano de la nueva lista: "; cin>>opc;


     ArrayList<int> *arl1 = new ArrayList<int>(opc);

    for(int i=0; i< opc; i++){
    cout<<"Inserte elemento [ "<<i<<" ] ";cin>>value;
   arl1->append(value);
   }


     arl.extend(arl1);
     arl.Print();

system("PAUSE");

   system("cls");
   cout<<"Ahora vamos a crear una lista enlazada..."<<endl;
   system("PAUSE");
   LinkedList<int> LinkL;
   for(int i=0; i< 1000; i++){
   LinkL.append(rand()%100);
   }
   cout<<"Esta es la lista enlazada creada...."<<endl;
   LinkL.print(); cout<<endl;
   system("PAUSE");
   cout<<endl<<endl;
   cout<<"Ahora vamos a revertirla..."<<endl;
   system("PAUSE");
   LinkL.reverse();
   LinkL.print();
   cout<<endl;
   cout<<"Ahora veamos si la lista es igual a otra lista creada por parametros, para esto vamos a borrar los elementos de la lista"<<endl;system("PAUSE");
   LinkL.clear();
   cout<<"--------------------------------AVISO------------------------------"<<endl;
   cout<<"             Los elementos se han borrado exitosamente             "<<endl;
   cout<<"-------------------------------------------------------------------"<<endl;
   system("PAUSE");
   system("cls");
   cout<<"Digite cuantos elementos desea agregarle a la lista: "; cin>>opc;
   for(int i=0; i<opc; i++){
   cout<<"Inserte elemento [ "<<i<<" ] ";cin>>value;
   LinkL.append(value);
   }
   cout<<"Esta es la lista con sus nuevos valores"<<endl;
   LinkL.print();
   cout<<endl;
    LinkedList<int> * LinkL1 = new LinkedList<int>();
   cout<<"Ahora ingrese la cantidad de elementos que desea agregar a la lista 2: "; cin>>opc;
     for(int i=0; i<opc; i++){
   cout<<"Inserte elemento [ "<<i<<" ] ";cin>>value;
   LinkL1->append(value);
   }
   cout<<"Esta es la lista 2"<<endl;
   LinkL1->print();
    cout<<endl;
   if(LinkL.equals(LinkL1)==true){
    cout<<"La lista es igual a la anterior "<<endl;
   }
   else{
    cout<<"La lista es diferente a la anterior"<<endl;
   }

   system("PAUSE");
   system("cls");



   cout<<"Ahora vamos a crear una lista (array list) ordenada"<<endl;

   cout<<"Digite que el tamano de la lista que desea implementar: "; cin>>opc;

   SortedArrayList<int> Sarl(opc);

   cout<<"Digite valores enteros para llenar la lista..."<<endl;

   for(int i=0; i<opc; i++){

    cout<<"Inserte elemento [ "<<i<<" ] ";cin>>value;
    Sarl.insert(value);
   }
   cout<<"Esta es la lista ordenada"<<endl;
   Sarl.Print();
   cout<<"Ahora digite el elemento al que desea averiguarle la posicion mediante busqueda binaria: ";cin>>value;
   cout<<"La posicion del elemento es: "<<Sarl.indexOf(value)<<endl;

   system("PAUSE");
   system("cls");

   cout<<"Ahora vamos a crear una lista enlazada (Linked List) ordenada..."<<endl;

   SortedLinkedList<int> SLinkL;

   cout<<"Digite los elementos que desea insertarle a la lista: ";cin>>opc;

     for(int i=0; i<opc; i++){

    cout<<"Inserte elemento [ "<<i<<" ] ";cin>>value;
    SLinkL.insert(value);
   }
cout<<"Esta es la lista ordenada"<<endl;
   SLinkL.print();









}
