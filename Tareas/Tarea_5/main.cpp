#include <iostream>
#include"BSTree.h"
#include"HashTable.h"
#include<time.h>
#include<string>
#include"List.h"
#include"LinkedList.h"
#include<stdexcept>

using namespace std;


int main()
{

        cout<< R"(
  ______                         ______
 /_  __/___ _________  ____ _   / ____/
  / / / __ `/ ___/ _ \/ __ `/  /___ \
 / / / /_/ / /  /  __/ /_/ /  ____/ /
/_/  \__,_/_/   \___/\__,_/  /_____/

    )"<<'\n';

    cout<<"Primero se van a insertar e imprimir 2000 numeros en cada estructura"<<endl;

    system("pause");

    List<int> * RandomValuesList = new LinkedList<int>;
    List<int> * UsedValues = new LinkedList<int>;
    for(int i = 0; i < 10001; i++) {
        RandomValuesList->append(i);
    }

    BSTree<int, string> Tree;
    HashTable<int, string> hashTable(2021);
    srand(time(0));

    for(int i = 0; i < 2000; i++){
        RandomValuesList->goToPos(rand() % RandomValuesList->getSize());
        int randomNumber = RandomValuesList->remove();
        string stringRepresentation = to_string(randomNumber);
        Tree.insert(randomNumber, stringRepresentation);
        hashTable.insert(randomNumber, stringRepresentation);
        UsedValues->append(randomNumber);
    }

    Tree.inOrder();

    cout<<endl<<"Estos fueron los elementos insertados en el BST"<<endl;
    system("pause");

    cout<<endl<<endl<<endl;
    List<string> *values = hashTable.getValues();
    for(values->goToStart(); !values->atEnd(); values->next()) {
        cout << values->getElement()<<" ";
    }

    cout<<endl<<"Estos fueron los elementos insertados en el hash table"<<endl;
    system("pause");
    system("cls");
    cout<<"Ahora vamos a remover 100 elementos de cada estructura"<<endl;
    system("pause");

    for(int i = 0; i < 100; i++){
    UsedValues->goToPos(rand() % UsedValues->getSize());
    int randomUsedValue = UsedValues->remove();
    cout<<"remove Tree(): "<< Tree.remove(randomUsedValue)<<endl;
    cout<<"remove HashTable(): "<< hashTable.remove(randomUsedValue)<<endl;
    }
    system("pause");
    system("cls");
    cout<<"Finalmente se van a buscar que elementos contiene cada estructura del 1-1000"<<endl;
    system("pause");

    for(int i =0; i<1000; i++) {
        try {
            cout << "Tree element "<<i<<": "<< Tree.find(i)<<endl;
        }
        catch (runtime_error &e) {
            cout<<e.what()<<endl;
        }
    }

    cout<<endl<<endl;

      for(int i =0; i<1001; i++) {
        try {
            cout <<"Hash element: "<<i<<": "<< hashTable.getValue(i)<<endl;
        }
        catch (runtime_error &e) {
            cout<<e.what()<<endl;
        }
    }
    delete values;
    delete RandomValuesList;
    return 0;
}
