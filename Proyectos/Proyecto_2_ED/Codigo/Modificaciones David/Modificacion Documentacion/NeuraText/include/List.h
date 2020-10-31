/*
********************************************************************************
*   Tecnológico de Costa Rica
*   Proyecto Programado de Estructuras de Datos.
********************************************************************************
*
*   File LIST.H
*
*   Autores de la clase:
*   Eric Alpizar Prendas
*   David González Agüero
*
*   Fecha de ultima modificación: 16/07/2020
*
*   Descripcion breve de la clase:
*   Esta es la clase abstracta List la cual muchos las estructuras de datos
*   secuenciales como las listas hacen uso mediante la herencia.

********************************************************************************
*/

#ifndef LIST_H
#define LIST_H

template <typename T>

class List {
private:
    void operator =(const List&) {}
    List(const List& obj) {}

public:
    List() {}
    virtual ~List() {}
    virtual void insert(T element) = 0;
    virtual void append(T element) = 0;
    virtual T remove() = 0;
    virtual void clear() = 0;
    virtual T getElement() = 0;
    virtual void goToStart() = 0;
    virtual void goToEnd() = 0;
    virtual void goToPos(int pos) = 0;
    virtual void next() = 0;
    virtual bool atEnd() = 0;
    virtual void previous() = 0;
    virtual bool atStart() = 0;
    virtual int getPos() = 0;
    virtual int getSize() = 0;
};

#endif // LIST_H
