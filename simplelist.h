#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include <QtDebug>
#include "node.h"

/*
 * Lista simplemente enlazada que utiliza tipos genericos (llamados template),
 * utiliza dos atributos para tener el inicio y el contador de elementos y cuenta
 * con tres metodos.
 *
 * MyList() esta lista cuenta con un constructor
 * add(T val) un metodo para agregar nuevos elementos
 * print() un metodo para recorrer la lista e imprimir sus valores en consola.
 *
 * IMPORTANTE: La clase MyNode tambien esta "tipada" con el typename T.
 */


//Definicion del tipo generico T (template en C++)
class SimpleList
{
public:

    /*
     * Constructor de la clase MyList
     */
    SimpleList() {
        first = nullptr;
        size = 0;
    }

    /*
     * Inserta un nuevo nodo al inicio de la lista
     */
    void add(QString title,QString desc,QString fechaE,QString prioridad,QString estado,QString usercode) {
        NodoS *theNew = new NodoS(title,desc,fechaE,prioridad,estado,usercode);
        if(first==nullptr){
            qInfo() << "Primer elemento de la lista";
            first = theNew;
            size++;
            return;
        }else{
            NodoS *temp=first;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = theNew;
        }
        size++;
    }

    void addUserCode(QString usercode) {
        NodoS *theNew = new NodoS(usercode);
        if(first==nullptr){
            qInfo() << "Primer elemento de la lista";
            first = theNew;
            size++;
            return;
        }else{
            NodoS *temp=first;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = theNew;
        }
        size++;
    }

    /*
     * Recorre la lista, imprimiendo sus valores en consola
     */
    void print() {
        NodoS*aux = first;
        while (aux != nullptr) {
            qInfo() << aux->getTitle();
            aux = aux->next;
        }
    }
int size;
private:
    NodoS *first;

};
#endif // SIMPLELIST_H
