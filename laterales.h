#ifndef LATERALES_H
#define LATERALES_H
#include <QtDebug>
#include "nodolate.h"
#include <proyect.h>
using namespace std;
class Laterales
{
public:
    Laterales() {
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

    QString getNameByPos(int x){
        if(!Vacia()){
            NodoLat* temp;
            temp = first;
            for(int i=0;i<x;i++){
                temp = temp->next;
            }
            return temp->title;
        }else{
            return "inexistente";
        }
    }

    NodoLat* getNodeByTitle(QString title){
        if(existsWTitle(title)){
            NodoLat* temp;
            temp = first;
            while(temp->getTitle()!= title){
                temp = temp->next;

            }
            return temp;
        }else{
            return NULL ;
        }
    }
    void add(QString title,QString desc,QString fechaini,QString fechaEnd,QString estado,QString lider){
        NodoLat *nodo;
        if(Vacia()){
            nodo = new NodoLat(0,title,desc,fechaini,fechaEnd,estado,lider);
            first=last= nodo;
        }else{
            nodo = new NodoLat(size,title,desc,fechaini,fechaEnd,estado,lider);
            nodo->ant = last;
            last->next = nodo;
            last = nodo;
        }
        size++;
    }

    void addLast(NodoLat *nodo){
        last->next = nodo;
        nodo->ant = last;
        last = last->next;
    }

    void addFirst(NodoLat*nodo){
        first->ant=nodo;
        nodo->next= first;
        first=first->ant;
    }

    void addMiddle(NodoLat *nodo){
        NodoLat *temp1;
        NodoLat *temp2;
        temp1 = first;
        while(temp1->y<nodo->y){
            temp1 = temp1->ant;
        }
        temp2 = temp1->next;
        temp2->ant = nodo;
        temp1->next = nodo;
        nodo->ant = temp1;
        nodo->next = temp2;
    }

    void recorrer(){
        if(!Vacia()){
        NodoLat *temp=first;
        while(temp!=NULL){
            cout<<"y: "<<temp->y<<endl;
            temp = temp->next;
        }
        }
    }

    bool existsWTitle(QString title){
        if(Vacia()){
            return false;
        }else{
            NodoLat* temp;
            temp = first;
            while(temp!=nullptr){
                if(temp->getTitle() == title){
                    return true;
                }else if(temp->next==nullptr){
                    return false;
                }
                temp = temp->next;

            }
        }
        return false;
    }
    int searchWTitle(QString title){
        if(existsWTitle(title)){
            NodoLat* temp;
            temp = first;
            while(temp->getTitle()!= title){
                temp = temp->next;

            }
            return temp->y;
        }else{
            return NULL;
        }
    }

    bool exists(int y){
        if(Vacia()){
            return false;
        }else{
            NodoLat* temp;
            temp = first;
            while(temp!=nullptr){
                if(temp->y == y){
                    return true;
                }else if(temp->next==nullptr){
                    return false;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    NodoLat* search(int y){
        if(exists(y)){
            NodoLat* temp;
            temp = first;
            while(temp->y != y){
                temp = temp->next;
            }
            return temp;
        }else{
            return NULL ;
        }
    }
    QString getTitle(int y){
        if(exists(y)){
            NodoLat* temp;
            temp = first;
            while(temp->y != y){
                temp = temp->next;
            }
            return temp->title;
        }else{
            return "inexistente";
        }
    }

    NodoLat *first;
    NodoLat *last;
    int size;
};
#endif // LATERALES_H
