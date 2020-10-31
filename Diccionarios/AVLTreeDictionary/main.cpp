#include <iostream>
#include"AVLTreeDictionary.h"
#include "DLinkedList.h"
#include<fstream>
#include<string>

using namespace std;

int main()
{
    cout<<"NEURATEXT ANALISIS" << endl;
    AVLTreeDictionary<int, string> AVLdict;
    setlocale(LC_ALL, "");
    string linea;
    ifstream archivo("Centeno.txt");
    int contador = 0;
    if (archivo.is_open()) {
        while (archivo.good()) {
            getline(archivo, linea);
            AVLdict.insert(contador,linea);
            contador++;
        }
        cout<< "Analizando el archivo..";
    archivo.close();
    }
    else {
        cout << "File not found or cannot be opened!" << endl;
    }
    cout << "Archivo analizado exitosamente"<< endl;
    cout<< "Este es el tiempo que dura haciendo la insercion de todas las lineas en el AVL" <<endl;
    system("pause");
    system("cls");

    string s = "";
    s = "áol#21*$ esto es una prueba *43+3 jaja";
    for (unsigned int i = 0 ; i < s.size(); i++) {
    if (isalpha(s[i])) {
        cout << "La posicion " << i << " del string es alfabetica"<<endl;
        cout << "Caracter " << s[i] << " analizado"<<endl;
    } else {
    cout << "La posicion " << i << " del string SI es alfanumerica"<<endl;
    cout << "Caracter " << s[i] << " analizado"<<endl;
    }
    }



    string temp = "";
    for (int i = 0; i < AVLdict.getSize(); i++) {
        temp = AVLdict.getValue(i);
        string word = "";
        for (unsigned int i = 0; i < temp.size(); i++) {
            if(isalpha(temp[i]) && !isspace(temp[i])) {
                word = word + temp[i];
            }
            if(isspace(temp[i])) {
                if (word != ""){
                cout << word << endl;
                }
             word = "";
            }
        }

    }




    //List<string>* values = AVLdict.getValues();

    /*
    cout << "Estos son los elementos en el AVLTree dictionary: "<<endl;
    for(values->goToStart(); !values->atEnd(); values->next()) {
        cout << values->getElement() << endl;
    }
    */

    //delete values;
}
