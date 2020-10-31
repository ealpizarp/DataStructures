#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;

int main()
{
    cout<<"NEURATEXT ANALISIS" << endl;
    string MegaEstructura[100];
    setlocale(LC_ALL, "");
    string linea;
    ifstream archivo("PruebaMegaEstructura.txt");
    int contador = 0;
    if (archivo.is_open()) {
        while (archivo.good()) {
            cout << "Analizando la linea: " << contador << endl;
            getline(archivo, linea);
            MegaEstructura[contador] = linea;
            contador++;
        }
        cout<< "Analisando el archivo..";
    archivo.close();
    }
    else {
        cout << "File not found or cannot be opened!" << endl;
    }
    cout<<endl;
    cout << "Archivo analizado exitosamente"<< endl;
    for (int i = 0; i < 3; i++) {
        cout << "Linea " << i << " del archivo: " << MegaEstructura[i] << endl;
    }

}
