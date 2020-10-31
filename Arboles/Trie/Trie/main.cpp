#include <iostream>
#include"BSTreeDictionary.h"
#include"TrieNode.h"
#include"Trie.h"
using namespace std;

int main()
{
    Trie palabras;

    palabras.insert("palabras");
    palabras.insert("padre");
    palabras.insert("padrino");
    palabras.insert("casa");
    palabras.insert("polaco");
    palabras.insert("nube");
    palabras.insert("no");
    palabras.insert("nulo");
    palabras.insert("celia");
    palabras.insert("nilo");
    cout << "Contiene el prefij o pad: " << palabras.containsPrefix("pad") << endl;

    cout << "Cantidad de palabras con p: " << palabras.prefixCount("p") << endl;
    cout << "Cantidad de palabras con cel: " << palabras.prefixCount("cel") << endl;
    cout << "Cantidad de palabras con pad: " << palabras.prefixCount("pad") << endl;
    cout << "El trie contiene la palabra 'celia': " << palabras.containsWord("celia") << endl;
    palabras.remove("palabras");
    palabras.remove("nilo");
    List<string> *lista = palabras.getMatches("n");
    for(lista->goToStart(); !lista->atEnd(); lista->next()) {
        cout << lista->getElement() << " ";
    }
    cout<<endl;
    lista = palabras.getMatches("");
    for(lista->goToStart(); !lista->atEnd(); lista->next()) {
        cout << lista->getElement() << " ";
    }
    delete lista;
    cout<<endl;

}
