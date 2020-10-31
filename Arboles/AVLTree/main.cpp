#include <iostream>
#include"AVLTree.h"

using namespace std;

int main()
{
    AVLTree<int> arbol;
    arbol.insert(37);
    arbol.insert(21);
    arbol.insert(45);
    arbol.insert(40);
    arbol.print();
    arbol.insert(432);
    arbol.insert(-4323);
    arbol.insert(6453);
    arbol.insert(97673);
    arbol.remove(40);
    List<int> *lista = arbol.getElements();
    for (lista->goToStart(); !lista->atEnd(); lista->next()) {
        cout<<lista->getElement()<<" ";
    }
    cout<<endl;
    cout<<endl;
    arbol.print();
    cout<<endl;
    //delete lista;

    arbol.clear();
    cout<<"Cantidad de nodos: "<<arbol.getSize()<<endl;
    return 0;
}
