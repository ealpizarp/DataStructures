/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File NEURATEXT.H
*
*   Fecha de ultima modificación: 04/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene las funciones principales de análisis de texto las cuáles utiliza
*   el programa neuratext.

********************************************************************************
*/

#ifndef NEURATEXT_H
#define NEURATEXT_H

#define ACCENT_A -96
#define ACCENT_ATEXT -31
#define ACCENT_E -126
#define ACCENT_ETEXT -23
#define ACCENT_I -95
#define ACCENT_ITEXT -19
#define ACCENT_O -94
#define ACCENT_OTEXT -13
#define ACCENT_U -93
#define ACCENT_UTEXT -6
#define ACCENT_UD -127
#define ACCENT_UDTEXT -4
#define ACCENT_N -92
#define ACCENT_NTEXT -15

#include<fstream>
#include <iostream>
#include<stdexcept>

#include "AVLTreeDictionary.h"
#include "SplayTree.h"
#include "Trie.h"
#include "ArrayList.h"

using std::string;

using std:: runtime_error;

using std::fstream;



class NeuraText {

private:

    //Los atributos privados de la clase son declarados

    List<string>* MegaEstructura;

    Trie* trie = new Trie();

    List<string>* MostFrequentWords;

    SplayTree<string>* StopWords = new SplayTree<string>();


    //Principales funciones privadas y auxiliares

    /*
    Nombre del método: cargarPalabrasIgnorarAux
    Descripción: Función que carga el archivo que contiene las palabras a ignorar
    Parámetros de entrada: string con el nombre del archivo.
    Salida: void
    Cambios dentro de la función: Dentro del StopWords se insertan las palabras a ignorar.
    */
    void cargarPalabrasIgnorarAux(string nombre) {
        string linea;
        std::ifstream archivo(nombre);
        if (archivo.is_open()) {
            std::cout<< "Cargando palabras a ignorar..." << std::endl;
            while (archivo.good()) {
                getline(archivo, linea);
                StopWords->insert(linea);
            }
        archivo.close();
        }
        else {
            throw runtime_error("File not found or cannot be opened!");
        }
    }

    /*
    Nombre del método: cargarArchivoAuxSecundario
    Descripción: Función encargada en abrir el archivo de texto y cargarlo en la Mega estructura
    Parámetros de entrada: string con el nombre del archivo
    Salida: void
    Cambios dentro de la función: Agrega en la megaEstructura cada línea con el texto correspondiente a la línea.
    */
    void cargarArchivoAuxSecundario(string nombre) {
        MegaEstructura = new ArrayList<string>(getFileSize(nombre));
        string linea;
        std::ifstream archivo(nombre);

        if (archivo.is_open()) {
            std::cout<< "Analizando el archivo.." << std::endl;
            while (archivo.good()) {
                getline(archivo, linea);
                MegaEstructura->append(linea);
                string word;
                for (unsigned int i = 0; i < linea.size(); i++) {
                    if(isalpha(linea[i]) && !isspace(linea[i])) {
                        linea[i] = tolower(linea[i]);
                        word = word + linea[i];
                    }
                    if(isspace(linea[i]) || i == linea.size() -1) {
                        bool contains = trie->containsWord(word);
                        if (word != "" && !contains){
                            trie->insert(word);
                        }
                        if(contains) {
                            trie->increaseWordFrequency(word);
                        }
                        word = "";
                    }
                }
            }
            archivo.close();
        }
        else {
            throw runtime_error("File not found or cannot be opened!");
        }
    }

    /*
    Nombre del método: cargarArchivoAux
    Descripción:Método encargado en abrir el archivo de texto y cargarlo en la Mega estructura junto al número de línea
    Parámetros de entrada: string con el nombre del archivo.txt
    Salida: void
    Cambios dentro de la función: inserción dentro de la MegaEstructura.
    */
    void cargarArchivoAux(string nombre) {
        MegaEstructura = new ArrayList<string>(getFileSize(nombre));
        int numLinea = 0;
        string linea;
        std::ifstream archivo(nombre);

        if (archivo.is_open()) {
            std::cout<< "Analizando el archivo.." << std::endl;
            while (archivo.good()) {
                getline(archivo, linea);
                MegaEstructura->append(linea);
                string word;
                for (unsigned int i = 0; i < linea.size(); i++) {
                if(isalpha(linea[i]) && !isspace(linea[i])) {
                    linea[i] = tolower(linea[i]);
                    word = word + linea[i];
                }
                if(isspace(linea[i]) || i == linea.size() -1) {
                    bool contains = trie->containsWord(word);
                    if (word != "" && !contains){
                    trie->insertWithLine(word, numLinea);
                    }
                    if(contains) {
                        trie->increaseWordFrequency(word);
                        trie->addLine(word, numLinea);
                    }
                 word = "";
                }
            }
            numLinea++;
            }
        archivo.close();
        }
        else {
            throw runtime_error("File not found or cannot be opened!");
        }
    }

    /*
    Nombre del método: agregarPalabraIgnorarAux
    Descripción: Función auxiliar de agregarPalabraIgnorar. Agrega dentro del archivo ignore.txt las palabras nuevas a ignorar.
    Parámetros de entrada: string con la nueva palabra para ignorar.
    Salida: void
    Cambios dentro de la función: Modifica el archivo ignore.txt agregando una palabra.
    */
    void agregarPalabraIgnorarAux(string palabra) {
        ofstream archivo("ignore.txt", ios::app);
        if(archivo.is_open()) {
            archivo<<endl;
            archivo<<palabra;
            archivo.close();
        }
    }


    /*
    Nombre del método: imprimirLinea
    Descripción: Imprime en la consola una línea específica del texto.
    Parámetros de entrada: int con el número de línea que se desea imprimir
    Salida: void
    Cambios dentro de la función: N/A
    */
    void imprimirLinea(int linea) {
        MegaEstructura->goToPos(linea);
        std::cout << "Linea " << linea << ": " << MegaEstructura->getElement() << std::endl;
    }



public:

    NeuraText() {
    }


    ~NeuraText() {
    delete MegaEstructura;
    delete trie;
    delete MostFrequentWords;
    delete StopWords;
    }

    //Funciones principales de acceso público

    /*
    Nombre del método: getFileSize
    Descripción: Encargada en contar el número total de líneas que un archivo tiene.
    Parámetros de entrada: string con el nombre del archivo
    Salida: int con la cantidad total de líneas
    Cambios dentro de la función:N/A
    */
    int getFileSize(string nombre) {
        int numLineas = 0;
        string linea;
        std::ifstream archivo(nombre);
        if (archivo.is_open()) {
            while (!archivo.eof()) {
                getline(archivo, linea);
                numLineas++;
            }
            archivo.close();
        }
        else {
            throw runtime_error("File not found or cannot be opened!");
        }

        return numLineas;
    }


    /*
    Nombre del método: cargarArchivo
    Descripción: LLama al método privado cargarArchivoAux
    Parámetros de entrada: String con el nombre del archivo
    Salida: void
    Cambios dentro de la función:N/A
    */
    void cargarArchivo(string nombre) {
        cargarArchivoAux(nombre);
    }


    /*
    Nombre del método: cargarArchivoSecundario
    Descripción: Llama al método privado cargarArchivoAuxSecundario
    Parámetros de entrada: string con el nombre del archivo
    Salida: void
    Cambios dentro de la función: N/A
    */
    void cargarArchivoSecundario(string nombre) {
        cargarArchivoAuxSecundario(nombre);
    }



    /*
    Nombre del método: imprimirArchivo
    Descripción:
    Parámetros de entrada:
    Salida:
    Cambios dentro de la función:
    */
    void imprimirArchivo() {
    for(MegaEstructura->goToStart(); !MegaEstructura->atEnd(); MegaEstructura->next()) {
        std::cout<<MegaEstructura->getElement()<<std::endl;
    }
    }


    /*
    Nombre del método: cargarPalabrasIgnorar
    Descripción: Método que llama a cargarPalabrasIgnorarAux
    Parámetros de entrada: string con el nombre del archivo con las palabras a ignorar
    Salida: void
    Cambios dentro de la función:N/A
    */
    void cargarPalabrasIgnorar(string nombre) {
        cargarPalabrasIgnorarAux(nombre);
    }


    /*
    Nombre del método: agregarPalabreIgnorar
    Descripción: Llama al método agregarPalabraIgnorarAux siempre y cuando la palabra que van a agregar no exista.
    Parámetros de entrada: string con la palabra que se quiere agregar
    Salida: void
    Cambios dentro de la función: inserción en StopWords
    */
    void agregarPalabraIgnorar(string palabra) {
        if(!StopWords->contains(palabra)) {
            agregarPalabraIgnorarAux(palabra);
            StopWords->insert(palabra);
            std::cout << "Palabra agragada con exito!" << std::endl;
        }
        else {
            std::cout << "La palabra ya esta en el archivo ignorar.txt" << std::endl;
        }
    }


    /*
    Nombre del método: eliminarPalabrasIgnorar
    Descripción: Modifica el archivo donde se encuentran las palabras a ignorar, eliminando de la lista una palabra
    Parámetros de entrada: N/A
    Salida: void
    Cambios dentro de la función: modificación del archivo que contiene las palabras a ignorar.
    */
    void eliminarPalabrasIgnorar() {
        ofstream archivo("ignore.txt");
        archivo.open("ignore.txt", ofstream::out | ofstream::trunc);
        StopWords->clear();
    }


    /*
    Nombre del método: mostrarPalabrasTrie
    Descripción: imprime en consola todas las palabras que se almacenaron en la estructura Trie
    Parámetros de entrada: N/A
    Salida: void
    Cambios dentro de la función:N/A
    */
    void mostrarPalabrasTrie() {
        List<string>* palabras;
        palabras = trie->getMatches("");
        for (palabras->goToStart(); !palabras->atEnd(); palabras->next()) {
            std::cout << palabras->getElement() << std::endl;
        }
        std::cout<<std::endl;
        delete palabras;
    }


    /*
    Nombre del método: mostrarPalabrasPorProfundidad
    Descripción: Muestra las palabras por profundidad de letras.
    Parámetros de entrada: int con el número de profundidad
    Salida: void
    Cambios dentro de la función:N/A
    */
    void mostrarPalabrasPorProfundidad(int profundidad) {
        List<string>* palabras;
        palabras = trie->getDepthWords(profundidad);
        for(palabras->goToStart(); !palabras->atEnd(); palabras->next()) {
            string word = palabras->getElement();
            std::cout << word << " frecuencia: " << trie->getWordFrequency(word) + 1 << endl;
        }
        std::cout << std::endl;
        delete palabras;
    }


    /*
    Nombre del método: CargarPalabrasMasUtilizadas
    Descripción: Almacena en una lista, las palabras más frecuentes en el archivo
    Parámetros de entrada: N/A
    Salida: void
    Cambios dentro de la función: Se asigna el valor a MostFrequentWords.
    */
    void CargarPalabrasMasUtilizadas() {
        MostFrequentWords = trie->getMostFrequentWords();
    }


    /*
    Nombre del método: palabrasMenosUtilizadas
    Descripción: muestra las palabras menos utilizadas
    Parámetros de entrada: int con el rango de palabras a mostrar
    Salida: void
    Cambios dentro de la función:N/A
    */
    void palabrasMenosUtilizadas(int rango) {
        int size = MostFrequentWords->getSize();
        string word = "";
        if (rango >= size) {
            throw runtime_error("Not enough words to satisfy the given range.");
        }
        MostFrequentWords->goToPos(size - 1);
        int contador = 0;
        for (int i = size; i > size - rango; i--) {
            word = MostFrequentWords->getElement();
            if (!StopWords->contains(word)) {
                std::cout<< contador + 1 << ": " << word << ". frecuencia: " << trie->getWordFrequency(word) + 1 << endl;
                MostFrequentWords->previous();
            } else {
                MostFrequentWords->previous();
                i++;
            }
            contador++;
        }
    }



    /*
    Nombre del método: palabrasMasUtilizadas
    Descripción: Muestra las palabras más utilizadas mostrandolas por un rango
    Parámetros de entrada: int con el rango de palabras que se quieren mostrar
    Salida: void
    Cambios dentro de la función:N/A
    */
    void palabrasMasUtilizadas(int rango) {
        string word = "";
        if (rango >= MostFrequentWords->getSize()) {
            throw runtime_error("Not enough words to satisfy the given range.");
        }
        MostFrequentWords->goToStart();
        for (int i = 0; i < rango; i++) {
            word = MostFrequentWords->getElement();
            if (!StopWords->contains(word)) {
                std::cout<< i + 1 <<": " << word << ". frecuencia: " << trie->getWordFrequency(word) + 1 << std::endl;
                MostFrequentWords->next();
            }
            else {
                MostFrequentWords->next();
                i--;
            }
        }
    }


    /*
    Nombre del método: ConsultarPrefijo
    Descripción: Se encarga de mostrar la lista de palabras con el prefijo indicado
    Parámetros de entrada: string con el prefijo
    Salida: void
    Cambios dentro de la función: N/A
    */
    void ConsultarPrefijo(string prefijo) {
        prefijo = acentos(prefijo);
        List<string>* PrefixWords;
        PrefixWords = trie->getMatches(prefijo);
        if (PrefixWords->getSize() == 0) {
            std::cout<< "No existen palabras en el archivo con este prefijo " << endl;
        }
        for (PrefixWords->goToStart(); !PrefixWords->atEnd(); PrefixWords->next()) {
            string word = PrefixWords->getElement();
            std::cout << word << " frecuencia: " << trie->getWordFrequency(word) + 1 << endl;
        }
        std::cout << std::endl;
    }


    /*
    Nombre del método: imprimirLineasPalabra
    Descripción: Método encargado en imprimir las líneas enteras en donde la palabra ingresada como parámetro aparece
    Parámetros de entrada: string con la palabra a consultar
    Salida: void
    Cambios dentro de la función: N/A
    */
    void imprimirLineasPalabra(string palabra) {
        palabra = acentos(palabra);
        if (!trie->containsWord(palabra)) {
            std::cout << "Esta palabra no se encuentra en el texto " << std::endl;
        }
        else {
            List<int>* lineas = trie->getWordLines(palabra);

            for (lineas->goToStart(); !lineas->atEnd(); lineas->next()) {
                imprimirLinea(lineas->getElement());
            }
        }
    }


    /*
    Nombre del método: imprimirPalabrasIgnorar
    Descripción: Hace un recorrido inOrden y a la vez imprime las palabras a Ignorar
    Parámetros de entrada: N/A
    Salida: void
    Cambios dentro de la función: N/A
    */
    void imprimirPalabrasIgnorar() {
        StopWords->inOrder();
    }


    /*
    Nombre del método: acentos
    Descripción: Función encargada en modificar los acentos del lenguaje español de entrada para que sea compatible los acentos del archivo.
    Parámetros de entrada: string con la palabra
    Salida: string con la palabra modificada
    Cambios dentro de la función: Se cambian los valores de los acentos del lenguaje español por medio de su código.
    */
    string acentos(string palabra) {
        char letra;
        for(unsigned int i = 0; i<palabra.size(); i++)
        {
            if(palabra[i] == ACCENT_A)//á
            {
                letra = ACCENT_ATEXT; //á
                palabra[i] = letra; //á
            }
            else if(palabra[i] == ACCENT_E) //é
            {
                letra = ACCENT_ETEXT;
                palabra[i] = letra;
            }
            else if(palabra[i] == ACCENT_I) //í
            {
                letra = ACCENT_ITEXT;
                palabra[i] = letra;
            }
            else if(palabra[i] == ACCENT_O) //ó
            {
                letra = ACCENT_OTEXT;
                palabra[i] = letra;
            }
            else if(palabra[i] == ACCENT_U) //ú
            {
                letra = ACCENT_UTEXT;
                palabra[i] = letra;
            }
            else if(palabra[i] == ACCENT_UD)    //ü
            {
                letra = ACCENT_UDTEXT;
                palabra[i] = letra;
            }
            else if(palabra[i] == ACCENT_N) //ñ
            {
                letra = ACCENT_NTEXT;
                palabra[i] = letra;
            }
        }
        return palabra;
    }

};

#endif // NEURATEXT_H
