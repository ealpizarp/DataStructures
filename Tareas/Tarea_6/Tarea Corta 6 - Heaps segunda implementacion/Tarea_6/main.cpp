#include <iostream>
#include"MaxHeap.h"
#include"HeapNode.h"
#include<limits>
#include<time.h>

using namespace std;

int read_input()
{
    int input = -1;
    bool valid= false;
    do
    {
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Opcion invalida porfavor reingrese la opcion." << endl;
        }
    } while (!valid);

    return (input);
}

int main()
{
    int opc = 0;
    MaxHeap<int, int> heap(20000);
    cout<< R"(
 ______                                     ____
/\__  _\                                   /'___\
\/_/\ \/    __     _ __    __     __      /\ \__/
   \ \ \  /'__`\  /\`'__\/'__`\ /'__`\    \ \  _``\
    \ \ \/\ \L\.\_\ \ \//\  __//\ \L\.\_   \ \ \L\ \
     \ \_\ \__/.\_\\ \_\\ \____\ \__/.\_\   \ \____/
      \/_/\/__/\/_/ \/_/ \/____/\/__/\/_/    \/___/


    )"<<'\n';

    srand(time(0));

    cout<<"Digite la cantidad de elementos que desea ordenar "; opc = read_input();
    int *arreglo = new int[opc];
    cout<<"Ingresando numeros..."<<endl;
    for (int i=0; i < opc; i++){
        arreglo[i] = rand();
        cout<<arreglo[i]<<" ";
    }


    cout<<endl;
    cout<<"Insertando al Heap..."<<endl;
    for (int i=0; i < opc; i++){
        int ValorArreglo = arreglo[i];
        heap.insert(ValorArreglo, ValorArreglo);
    }

    cout<<"Numeros insertados exitosamente!"<<endl;
    system("pause");

    cout<<"Ahora vamos a remover los datos del heap y mostrar el arreglo nuevamente"<<endl;
    system("pause");
    int *number = new int(0);
    //int number = 0;
    while (heap.getSize() > 0){
        HeapNode<int, int> temp = heap.removeFirst();
        arreglo[*number] = temp.getElement();
        cout << arreglo[*number] << " ";
        *number += 1;
    }
    cout<<endl;
    delete number;
    delete [] arreglo;
    return 0;

}
