#include <iostream>
#include"ArrayStack.h"
#include"LinkedStack.h"
#include<string>

using namespace std;


void ingresarDatos(int n, Stack<int>* pila){
    int element = 0;
  for(int i=0; i < n; i++){
        cout<<"Digite el elemento de la posicion [ "<<i<<" ]"<<endl;
        cin>>element;
        pila->push(element);
    }
}

void vaciarPila(Stack<int>* pila){
    while(pila->getSize() > 0){
    cout << pila->pop() << "  ";
    }
    cout<<endl;
}

string reconocimientoCaracteres(string cadena){
Stack<char>* pila = new LinkedStack<char>();
for(int i = 0; i < cadena.length(); i++){
    if((cadena.at(i) == '(') || (cadena.at(i) == '{') || (cadena.at(i) == '[') ){
      pila->push(cadena.at(i));
    }
    else if((cadena.at(i) == ')' && pila->topValue() != '(' ) || (cadena.at(i) == '}' && pila->topValue() != '{' ) || (cadena.at(i) == ']' && pila->topValue() != '[' )){
            return "Secuencia de caracteres no valida!";
    }
    else if((cadena.at(i) == ')') || (cadena.at(i) == '}') ||(cadena.at(i) ==  ']')){
            pila->pop();
    }
}
if(pila->getSize() == 0){
    return "Secuencia de caracteres valida!";
}
else{
    return "Secuencia de caracteres no valida!";
}
}


int main()
{
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"                            Bienvenid@s a la tarea #4 (Parte 1)                            "<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;

    cout<<"Vamos a generar unas pruebas con ambos tipos de pilas"<<endl;
    Stack<int>* AS = new ArrayStack<int>(5);
    Stack<int>* LS = new LinkedStack<int>();
    int element = 0;
    string frase;
    cout<<"Primero tenemos que ingresarle 8 elementos a una pila enlazada o LinkedStack..."<<endl;
    ingresarDatos(8,LS);
    LS->print();
    system("PAUSE");
    cout<<"Ahora ingresemosle unos 4 elementos mas..."<<endl;
    ingresarDatos(4, LS);
    LS->print();
    system("PAUSE");
    cout<<"Muy bien, seguidamente vamos a probar la pila con arreglos o ArrayStack..."<<endl;
    system("PAUSE");
    cout<<"A esta pila le vamos a poner un tamano de cinco elementos pero le vamos a ingresar unos 9..."<<endl;
    ingresarDatos(9,AS);
    AS->print();
    system("PAUSE");
    cout<<"Ahora vamos a vaciar ambas pilas, primero la enlazada y luego la de arreglos"<<endl;
    vaciarPila(LS);
    vaciarPila(AS);
    cout<<"Las pruebas de pilas han concluido, ahora vamos para el programa de reconocimiento de secuencias de caracteres"<<endl;
    system("PAUSE");
    system("CLS");
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"              Bienvenid@s al programa de reconocimiento de secuencia de caracteres              "<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<endl;
    cout<<"Digite la frase que desea analizar su secuencia de caracteres"<<endl;
    cin.ignore();
    getline(cin, frase);
    cout<<reconocimientoCaracteres(frase)<<endl;

}
