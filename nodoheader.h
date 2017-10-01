#ifndef NODOHEADER_H
#define NODOHEADER_H
#include "listav.h"
#include "simplelist.h"
class NodoHeader {
public:

    /*
     * Constructor de la clase MyNode
     */
    NodoHeader(int x,QString nombre, QString desc, QString code) {
        this->nombre = nombre;
        this->desc = desc;
        this->code = code;
        this->x = x;
        this->next =nullptr;
        this->ant = nullptr;
        this->column = new ListaV();
        this->listita = new SimpleList();
    }
    /*
     * Metodo para obtener el valor del nodo
     */
    QString getNombre() {
        return this->nombre;
    }
    QString getDesc() {
        return this->desc;
    }
    QString getCode() {
        return this->code;
    }
    // Apuntador al siguiente nodo
    NodoHeader *ant;
    NodoHeader *next;
    ListaV* column;
    SimpleList* listita;
    QString nombre,desc,code;
    int x;
private:
    // Valor
};
#endif // NODOHEADER_H
