/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File NEURATEXT.H
*
*   Fecha de ultima modificación: 02/08/2020
*
*   Descripcion breve de la clase:
*   Esta clase contiene las funciones principlaes de analisis de texto las cuales utiliza
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
                    //std::cout << "Linea: " << numLinea << " oracion: " << word << std::endl;
                    //std::cout << "Linea: " << numLinea << " palabra: " << word << std::endl;
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

    void agregarPalabraIgnorarAux(string palabra) {
        ofstream archivo("ignore.txt", ios::app);
        if(archivo.is_open()) {
            archivo<<endl;
            archivo<<palabra;
            archivo.close();
        }
    }


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

    void cargarArchivo(string nombre) {
        cargarArchivoAux(nombre);
    }

    void cargarArchivoSecundario(string nombre) {
        cargarArchivoAuxSecundario(nombre);
    }


    void imprimirArchivo() {
    for(MegaEstructura->goToStart(); !MegaEstructura->atEnd(); MegaEstructura->next()) {
        std::cout<<MegaEstructura->getElement()<<std::endl;
    }
    }

    void cargarPalabrasIgnorar(string nombre) {
        cargarPalabrasIgnorarAux(nombre);
    }

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

    void eliminarPalabrasIgnorar() {
        ofstream archivo("ignore.txt");
        archivo.open("ignore.txt", ofstream::out | ofstream::trunc);                    //Hacer la ecepcion por si no lo encuentra
        StopWords->clear();
    }

    void mostrarPalabrasTrie() {
        List<string>* palabras;
        palabras = trie->getMatches("");
        for (palabras->goToStart(); !palabras->atEnd(); palabras->next()) {
            std::cout << palabras->getElement() << std::endl;
        }
        std::cout<<std::endl;
        delete palabras;
    }

    void mostrarPalabrasPorProfundidad(int profundidad) {
        List<string>* palabras;
        palabras = trie->getDepthWords(profundidad);
        for(palabras->goToStart(); !palabras->atEnd(); palabras->next()) {
            std::cout<<palabras->getElement() << " ";
        }
        std::cout << std::endl;
        delete palabras;
    }

    void CargarPalabrasMasUtilizadas() {
        MostFrequentWords = trie->getMostFrequentWords();
    }

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

    void ConsultarPrefijo(string prefijo) {
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

    void imprimirPalabrasIgnorar() {
        StopWords->inOrder();
    }

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
