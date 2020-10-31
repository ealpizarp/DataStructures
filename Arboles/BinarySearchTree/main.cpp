#include <iostream>
#include"BSTree.h"

using namespace std;

int main()
{
    BSTree<int> arbol;
    arbol.insert(37);
    arbol.insert(21);
    arbol.insert(45);
    arbol.insert(40);
    arbol.insert(432);
    arbol.insert(-4323);
    arbol.insert(6453);
    arbol.insert(97673);

    List<int> *lista = arbol.getElements();
    for (lista->goToStart(); !lista->atEnd(); lista->next()) {
        cout<<lista->getElement()<<" ";
    }
    cout<<endl;
    delete lista;

    arbol.clear();
    cout<<"Cantidad de nodos: "<<arbol.getSize()<<endl;

    return 0;
}
