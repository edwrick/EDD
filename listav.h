#ifndef LISTAV_H
#define LISTAV_H
#include <QtDebug>
#include "nodoorto.h"
using namespace std;

class ListaV
{
public:

    /*
     * Constructor de la clase MyList
     */
    ListaV() {
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

    NodoOrto* get(int y){
        if(!Vacia()){
            NodoOrto* aux=first;
            while(aux->abajo!=NULL){
                if(aux->y==y){
                    return aux;
                }
                aux= aux->abajo;
            }
            if(aux->y==y){
                return aux;
            }
        }
        cout<< "Nodo ortogonal inexistente";
        return NULL;
    }

    NodoOrto* searchByPos(int no){
        if(!Vacia()){
            NodoOrto* aux=first;
            for(int i=0;i<no;i++){
                aux = aux->abajo;
            }
            return aux;
        }
        cout<<"Lista vacia";
        return NULL;
    }

    void add(NodoOrto *nodo){
        if(Vacia()){
            first=last= nodo;
        }else{
            if(nodo->y<first->y){
                addFirst(nodo);
            }else if(nodo->y>last->y){
                addLast(nodo);
            }else{
                addMiddle(nodo);
            }
        }
        size++;
    }

    void addLast(NodoOrto *nodo){
        last->abajo = nodo;
        nodo->up = last;
        last = last->abajo;
    }

    void addFirst(NodoOrto *nodo){
        first->up=nodo;
        nodo->abajo= first;
        first=first->up;
    }

    void addMiddle(NodoOrto *nodo){
        NodoOrto *temp1;
        NodoOrto *temp2;
        temp1 = first;
        while(temp1->y<nodo->y){
            temp1 = temp1->abajo;
        }
        temp2 = temp1->up;
        temp2->abajo = nodo;
        temp1->up = nodo;
        nodo->abajo = temp1;
        nodo->up = temp2;
    }

    void recorrer(){
        if(!Vacia()){
        NodoOrto *temp=first;
        while(temp!=NULL){
            cout<<"y: "<<temp->y<<endl;
            temp = temp->abajo;
        }
        }
    }
int size;
private:
    NodoOrto *first;
    NodoOrto *last;

};

#endif // LISTAV_H
