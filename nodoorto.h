#ifndef NODOORTO_H
#define NODOORTO_H
#include "simplelist.h"
#include <QtDebug>
 //Definicion del tipo generico T (template en C++)
class NodoOrto {
public:

    /*
     * Constructor de la clase MyNode
     */
    NodoOrto(){}
    NodoOrto(QString name,int x,int y) {
        this->name=name;
        this->x=x;
        this->y=y;
        this->izquierda=NULL;
        this->derecha=NULL;
        this->up=NULL;
        this->abajo=NULL;
        this->listita = new SimpleList();
    }
    /*
     * Metodo para obtener el valor del nodo
     */
    QString getName(){
        return this->name;
    }

    // Apuntador al siguiente nodo
    NodoOrto *izquierda;
    NodoOrto *derecha;
    NodoOrto *up;
    NodoOrto *abajo;
    SimpleList* listita;
    QString name;
    int x,y;
private:
    // Valor
};
#endif // NODOORTO_H
