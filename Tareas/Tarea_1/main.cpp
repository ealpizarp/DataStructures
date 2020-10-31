#include <iostream>
#include "DynamicMatrix.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"                    Bienvenid@ a la tarea # 1 (Matriz dinamica)                    "<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;

    int p=0;
    DynamicMatrix<int> m(8, 10);
    srand(time(0));

    for (int r = 0; r < m.getRows(); r++) {
        for (int c = 0; c < m.getColumns(); c++) {
            m.setValue(r, c, rand()%100);
        }
    }
    for (int r = 0; r < m.getRows(); r++) {
        for (int c = 0; c < m.getColumns(); c++) {
            cout << m.getValue(r, c) << "\t";
        }
        cout << endl;
    }

cout<<"Ahora se va a trasposicionar la matriz"<<endl;\
    system("PAUSE");

    m.traspose();
    m.print();

cout<<"Digite el valor que le desea agregar a la nueva linea de la matriz ";cin>>p;
   m.addRow(p);
   m.print();
   cin.clear();
   cin.ignore();
cout<<"Digite el valor que le desea agregar a la nueva columna de la matriz ";cin>>p;
m.addColumn(p);
  m.print();
  cout<<"Digite la posicion de la linea de quedea borrar "<<endl;cin>>p;
  m.removeRow(p);
  m.print();
    cout<<"Digite la posicion de la columna de quedea borrar "<<endl;
  cin>>p;
  m.removeCol(p);
  m.print();
  cout<<"Digite el valor que le desea insertar a toda la matriz ";
    cin>>p;
    m.setAll(p);
    m.print();
cout<<"-------------------------------------------"<<endl;
cout<<"Muchas gracias por utilizar DynamicMatrix!"<<endl;
cout<<"-------------------------------------------"<<endl;
    return 0;
};
