#ifndef LISTAH_H
#define LISTAH_H
#include <QtDebug>
#include "nodoorto.h"
using namespace std;

class ListaH
{
public:

    /*
     * Constructor de la clase MyList
     */
    ListaH() {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    bool Vacia(){
        if(first==nullptr){
            return true;
        }
        return false;
    }

    void add(NodoOrto *nodo){
        if(Vacia()){
            first=last= nodo;
        }else{
            if(nodo->x<first->x){
                addFirst(nodo);
            }else if(nodo->x>last->x){
                addLast(nodo);
            }else{
                addMiddle(nodo);
            }
        }
        size++;
    }

    void addLast(NodoOrto *nodo){
        last->derecha = nodo;
        nodo->izquierda = last;
        last = last->derecha;
    }

    void addFirst(NodoOrto *nodo){
        first->izquierda=nodo;
        nodo->derecha= first;
        first=first->izquierda;
    }

    void addMiddle(NodoOrto *nodo){
        NodoOrto *temp1;
        NodoOrto *temp2;
        temp1 = first;
        while(temp1->x<nodo->x){
            temp1 = temp1->izquierda;
        }
        temp2 = temp1->derecha;
        temp2->izquierda = nodo;
        temp1->derecha = nodo;
        nodo->izquierda = temp1;
        nodo->derecha = temp2;
    }

    void recorrer(){
        if(!Vacia()){
        NodoOrto *temp=first;
        while(temp!=NULL){
            cout<<"x: "<<temp->x<<endl;
            temp = temp->derecha;
        }
        }
    }

private:
    NodoOrto *first;
    NodoOrto*last;
    int size;
};
#endif // LISTAH_H
