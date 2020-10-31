#include"windows.h"
#include"NeuraText.h"
#include"Trie.h"
#include<locale>
#include<limits>
#include <chrono>
#include<filesystem>

using namespace std::chrono;

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


void gotoxy(int x, int y)
{
    HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    pos.X=x;
    pos.Y=y;

    SetConsoleCursorPosition(console,pos);
}

void imprimirNombre() {
    cout<< R"(
  ________   _______   ___  ___  ________  ________          _________  _______      ___    ___ _________
|\   ___  \|\  ___ \ |\  \|\  \|\   __  \|\   __  \        |\___   ___\\  ___ \    |\  \  /  /|\___   ___\
\ \  \\ \  \ \   __/|\ \  \\\  \ \  \|\  \ \  \|\  \       \|___ \  \_\ \   __/|   \ \  \/  / ||___ \  \_|
 \ \  \\ \  \ \  \_|/_\ \  \\\  \ \   _  _\ \   __  \           \ \  \ \ \  \_|/__  \ \    / /     \ \  \
  \ \  \\ \  \ \  \_|\ \ \  \\\  \ \  \\  \\ \  \ \  \           \ \  \ \ \  \_|\ \  /     \/       \ \  \
   \ \__\\ \__\ \_______\ \_______\ \__\\ _\\ \__\ \__\           \ \__\ \ \_______\/  /\   \        \ \__\
    \|__| \|__|\|_______|\|_______|\|__|\|__|\|__|\|__|            \|__|  \|_______/__/ /\ __\        \|__|
                                                                                   |__|/ \|__|


    )"<<'\n';
}

void imprimirMensajeSalida() {
    cout<< R"(
   ______                _                                         __  _ ___                                                 __            __  __
  / ____/________ ______(_)___ ______   ____  ____  _____   __  __/ /_(_) (_)___  ____ ______   ____  ___  __  ___________ _/ /____  _  __/ /_/ /
 / / __/ ___/ __ `/ ___/ / __ `/ ___/  / __ \/ __ \/ ___/  / / / / __/ / / /_  / / __ `/ ___/  / __ \/ _ \/ / / / ___/ __ `/ __/ _ \| |/_/ __/ /
/ /_/ / /  / /_/ / /__/ / /_/ (__  )  / /_/ / /_/ / /     / /_/ / /_/ / / / / /_/ /_/ / /     / / / /  __/ /_/ / /  / /_/ / /_/  __/>  </ /_/_/
\____/_/   \__,_/\___/_/\__,_/____/  / .___/\____/_/      \__,_/\__/_/_/_/ /___/\__,_/_/     /_/ /_/\___/\__,_/_/   \__,_/\__/\___/_/|_|\__(_)
                                    /_/
    )"<<'\n';
}


void imprimirMenuPrincipal() {

    cout << "Consultar por prefijo                                                                      1"<<endl;
    cout << "Buscar palabra                                                                             2"<<endl;
    cout << "Buscar por cantidad de letras                                                              3"<<endl;
    cout << "Palabras mas utilizadas                                                                    4"<<endl;
    cout << "Salir del programa                                                                         5"<<endl;
}

void imprimirMenuSecundario() {
    cout << "Imprimir lista de palabras a ignorar                                                       1"<<endl;
    cout << "Agregar palabras a ignorar                                                                 2"<<endl;
    cout << "Limpiar lista de palabras a ignorar                                                        3"<<endl;
    cout << "Ver top de palabras mas utilizadas                                                         4"<<endl;
    cout << "Ver top de palabras menos utilizadas                                                       5"<<endl;
    cout << "Volver al menu principal                                                                   6"<<endl;
}


int main()
{
    setlocale(LC_ALL, "");

    NeuraText text;

    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleOutputCP(65001);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    imprimirNombre();

    //Aqui vamos a definir las variables necesarias

    string archivo = "";
    string prefijo = "";
    string palabra = "";
    int opc = 0;
    int profundidad = 0;
    int valorTop = 0;

    cout << "Bienvenido! este programa consiste en el analisis de archivos de texto " << endl;

    cout << "INSERTE EL NOMBRE DEL ARCHIVO QUE DESEA ANALIZAR: "; cin >> archivo;

    auto start = high_resolution_clock::now();

    text.cargarArchivo(archivo);
    text.cargarPalabrasIgnorar("Ignore.txt");
    text.CargarPalabrasMasUtilizadas();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Archivo analizado exitosamente en: " << duration.count() << " microsegundos" << endl;
    system("pause");


    do {
    system("cls");
    imprimirNombre();
    imprimirMenuPrincipal();
    cout << "Digite la opcion que desea: "; opc = read_input();
    switch(opc) {

        case 1:
            cout << "Digite el prefijo que desea consultar: "; cin >> prefijo;
            text.ConsultarPrefijo(prefijo);
            system("pause");
            break;
        case 2:
            cout << "Digite la palabra a la que le desea consultar las lineas: "; cin >> palabra;
            cout << "Estas son las lineas del texto que contienen las palabra "<< palabra << ": " << endl;
            text.imprimirLineasPalabra(palabra);
            system("pause");
            break;
        case 3:
            cout << "Digite la profundundidad que desea consultar: "; cin >> profundidad;
            text.mostrarPalabrasPorProfundidad(profundidad);
            system("pause");
            break;
        case 4:
            do {
                system("cls");
                imprimirNombre();
                imprimirMenuSecundario();
                cout << "Digite la opcion que desea: "; opc = read_input();
                switch(opc) {
                    case 1:
                        cout << "Esta es la lista de palabras a ignorar: " << endl;
                        text.imprimirPalabrasIgnorar();
                        system("pause");
                        break;
                    case 2:
                        cout << "Que palabra desea agregar a la lista de ignorar: "; cin >> palabra;
                        text.agregarPalabraIgnorar(palabra);
                        system("pause");
                        break;
                    case 3:
                        text.eliminarPalabrasIgnorar();
                        cout << "Palabras eliminadas extitosamente!" << endl;
                        system("pause");
                        break;
                    case 4:
                        cout << "Digite el rango que desea ver el top de la lista de palabras mas frecuentes: "; cin >> valorTop;
                        text.palabrasMasUtilizadas(valorTop);
                        system("pause");
                        break;
                    case 5:
                        cout << "Digite el rango que desea ver el top de la lista de palabras mas frecuentes: "; cin >> valorTop;
                        text.palabrasMenosUtilizadas(valorTop);
                        system("pause");
                        break;
                }

            } while (opc != 6);
            break;
        default:
            if (opc == 5) {
                system("cls");
                imprimirMensajeSalida();
            }
            else {
            cout<<"Opcion no valida!" << endl;
            system("pause");
            }
    }

    } while(opc != 5);

}
