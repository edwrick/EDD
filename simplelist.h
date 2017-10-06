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



    bool Vacia(){
        if (first) return false;

        return true;
    }
    /*
     * Inserta un nuevo nodo al inicio de la lista
     */

    void borrar(NodoS* nodo){
        sup_en_lista(nodo);
    }
    int sup_inicio (){
      if (size == 0)
        return -1;
      NodoS *sup_elemento;
      sup_elemento = first;
      first = first->next;
      if (size == 1) first = NULL;
      size--;
      return 0;
    }
    int sup_en_lista (NodoS *nodo){

      NodoS *actual;
      NodoS *sup_elemento;
      actual = first;
      if(size==1){
          first=NULL;
          size=0;
          return 0;
      }
      if(nodo==first){
          first=first->next;
          size--;
          return 0;
      }
      while(actual!=nodo){
          sup_elemento=actual;
          actual=actual->next;
      }
      if(actual->next){
      sup_elemento->next=actual->next;
      size--;
      return 0;
      }else{
          sup_elemento->next=NULL;
          size--;
          return 0;
      }
    }
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

    NodoS* getNodeByPos(int x){
        if(!Vacia()){
        NodoS* aux = first;
        for(int i=0;i<x;i++){
            aux = aux->next;
        }
        return aux;
        }
        return NULL;

    }
    NodoS* getNodeByTitle(QString title){
        if(!Vacia()){
        NodoS* aux = first;
        while(aux){
            if(aux->title==title) return aux;
            aux = aux->next;
        }

        }
        return NULL;

    }
    NodoS* getNodeUCode(QString code){
        if(!Vacia()){
        NodoS* aux = first;
        while(aux){
            if(aux->usercode==code) return aux;
            aux = aux->next;
        }

        }
        return NULL;

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


    QString getCodeByPos(int x){
        if(!Vacia()){
            NodoS* temp;
            temp = first;
            for(int i=0;i<x;i++){
                temp = temp->next;
            }
            return temp->usercode;
        }else{
            return "inexistente";
        }
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
