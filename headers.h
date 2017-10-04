#ifndef HEADERS_H
#define HEADERS_H
#include <QtDebug>
#include "nodoheader.h"
#include <teamwork.h>
using namespace std;


class Headers
{
public:
    Headers() {
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

    bool existsWTitle(QString title){

        if(Vacia()){
            return false;
        }else{
            NodoHeader* temp;
            temp = first;
            while(temp!=nullptr){
                if(temp->getNombre()== title){
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
            NodoHeader* temp;
            temp = first;
            while(temp->getNombre()!= title){
                temp = temp->next;

            }
            return temp->x;
        }else{
            return NULL ;
        }
    }
    bool exists(int x){
        if(Vacia()){
            return false;
        }else{
            NodoHeader* temp;
            temp = first;
            while(temp!=nullptr){
                if(temp->x == x){
                    return true;
                }else if(temp->next==nullptr){
                    return false;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    NodoHeader* search(int x){
        if(exists(x)){
            NodoHeader* temp;
            temp = first;
            while(temp->x != x){
                temp = temp->next;
            }
            return temp;
        }else{
            return NULL ;
        }
    }
    NodoHeader* searchByPos(int x){
        if(!Vacia()){
            NodoHeader* temp;
            temp = first;
            for(int i=0;i<x;i++){
                temp = temp->next;
            }
            return temp;
        }else{
            return NULL;
        }
    }

    NodoHeader* getNodeByTitle(QString title){
        if(existsWTitle(title)){
            NodoHeader* temp;
            temp = first;
            while(temp->getNombre()!= title){
                temp = temp->next;

            }
            return temp;
        }else{
            return NULL ;
        }
    }

    void add(QString nombre, QString desc, QString code){
        NodoHeader *nodo;
        if(Vacia()){
            nodo = new NodoHeader(0,nombre,desc,code);
            first=last= nodo;
        }else{
            nodo = new NodoHeader(size,nombre,desc,code);
            nodo->ant = last;
            last->next = nodo;
            last = nodo;
        }
        size++;
    }

    /*void addLast(NodoHeader<T> *nodo){
        last->next = nodo;
        nodo->ant = last;
        last = last->next;
    }

    void addFirst(NodoHeader<T> *nodo){
        first->ant=nodo;
        nodo->next= first;
        first=first->ant;
    }

    void addMiddle(NodoHeader<T> *nodo){
        NodoHeader<T> *temp1;
        NodoHeader<T> *temp2;
        temp1 = first;
        while(temp1->x<nodo->x){
            temp1 = temp1->ant;
        }
        temp2 = temp1->next;
        temp2->ant = nodo;
        temp1->next = nodo;
        nodo->ant = temp1;
        nodo->next = temp2;
    }*/
    QString getName(int x){
        if(exists(x)){
            NodoHeader* temp;
            temp = first;
            while(temp->x != x){
                temp = temp->next;
            }
            return temp->nombre;
        }else{
            return "inexistente";
        }
    }

    QString getNameByPos(int x){
        if(!Vacia()){
            NodoHeader* temp;
            temp = first;
            for(int i=0;i<x;i++){
                temp = temp->next;
            }
            return temp->nombre;
        }else{
            return "inexistente";
        }
    }

    void recorrer(){
        if(!Vacia()){
        NodoHeader *temp=first;
        while(temp!=NULL){
            cout<<"x: "<<temp->x<<endl;
            temp = temp->next;
        }
        }
    }
    int size;
private:
    NodoHeader *first;
    NodoHeader *last;

};
#endif // HEADERS_H
