#ifndef NODOAVL_H
#define NODOAVL_H

#include <QtDebug>
template <typename T> //Definicion del tipo generico T (template en C++)
class NodoAVL {
public:

    /*
     * Constructor de la clase MyNode
     */
    NodoAVL(T dato) {
        this->dato = dato;
        this->izquierdo = nullptr;
        this->derecho = nullptr;
        this->padre = nullptr;
        this->FE=0;
    }
    NodoAVL(T dato,NodoAVL *padre) {
        this->dato = dato;
        this->padre = padre;
        this->izquierdo = nullptr;
        this->derecho = nullptr;
        this->FE=0;
    }
    /*
     * Metodo para obtener el valor del nodo
     */
    T getDato() {
        return this->dato;
    }

    // Apuntador al siguiente nodo
    NodoAVL *izquierdo;
    NodoAVL *derecho;
    NodoAVL *padre;
    T dato;
    int FE;
private:
    // Valor



};
#endif // NODOAVL_H
