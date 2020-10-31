#include <iostream>
#include"SplayTree.h"

using namespace std;

int main()
{
    SplayTree<int> st;

    st.insert(43);
    st.insert(32);
    st.insert(454);
    st.insert(232);

    st.printRootValue();

    cout << "Ahora vamos a buscar el numero 454..." <<endl;
    cout << st.search(454) << endl;
    cout << "La raiz del arbol es: "; st.printRootValue(); cout << endl;
    cout << "El arbol contiene el 32: " << st.contains(32) << endl;
    cout << "La raiz del arbol es: "; st.printRootValue(); cout << endl;
    st.contains(32223);
    cout << "La raiz del arbol es: "; st.printRootValue(); cout << endl;
return 0;
}
