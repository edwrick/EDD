#ifndef AVLTREE_H
#define AVLTREE_H
#include "nodoavl.h"
#include "user.h"
#include <QtDebug>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include<stdio.h>
#include <sstream>
using namespace std;
template <typename T> //Definicion del tipo generico T (template en C++)
class AVLTree
{
public:

    //Constructores
    AVLTree() {
        actual = nullptr;
        raiz =nullptr;

    }
    ~AVLTree() { Podar(raiz); }

    bool EsHoja(NodoAVL<T> *r) { return !r->derecho && !r->izquierdo; }

    bool Vacio(NodoAVL<T> *r) { return r==NULL; }

    void Podar(NodoAVL<T>* &nodo)
    {
       // Algoritmo recursivo, recorrido en postorden
       if(nodo) {
          Podar(nodo->izquierdo); // Podar izquierdo
          Podar(nodo->derecho);   // Podar derecho
          delete nodo;            // Eliminar nodo
          nodo = NULL;
       }
    }

    bool NodeNull(NodoAVL<T> *act){
        try{
            User data = act->dato;
            return true;
        }catch(...) {
            return false;
            throw;
         }
    }
    void Insertar(const T dat)
    {

       NodoAVL<T> *padre  = nullptr;
       User u = dat;
       //cout << "Insertar: " << u.cod << endl;
       User actualdata;
       User padredata;
       actual = raiz;
       if(!Vacio(actual)){
           actualdata=actual->dato;
       }
       // Buscar el dato en el �rbol, manteniendo un puntero al nodo padre
       while(!Vacio(actual) && u.cod != actualdata.cod) {
          padre = actual;
          if(u.cod > actualdata.cod){
              actual = actual->derecho ;
              if (!Vacio(actual)) actualdata = actual->dato;
          }else if(u.cod < actualdata.cod){
              actual = actual->izquierdo;
              if (!Vacio(actual)) actualdata = actual->dato;
          }
        }
       if(!Vacio(padre)){
           padredata = padre->dato;
       }
       // Si se ha encontrado el elemento, regresar sin insertar
       if(!Vacio(actual)) return;
       // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
       // el nodo raiz
       if(Vacio(padre)){
       raiz = new NodoAVL<T>(dat);
       // Si el dato es menor que el que contiene el nodo padre, lo insertamos
       // en la rama izquierda

       }else if(u.cod < padredata.cod) {
          padre->izquierdo = new NodoAVL<T>(dat, padre);
          Equilibrar(padre, IZQUIERDO, true);
       }
       // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
       // en la rama derecha
       else if(u.cod > padredata.cod) {
          padre->derecho = new NodoAVL<T>(dat, padre);
          Equilibrar(padre, DERECHO, true);
       }
       size++;
    }
    void Equilibrar(NodoAVL<T> *nodo, int rama, bool nuevo)
    {
       bool salir = false;

       // Recorrer camino inverso actualizando valores de FE:
       while(nodo && !salir) {
          if(nuevo)
             if(rama == IZQUIERDO) nodo->FE--; // Depende de si a�adimos ...
             else                  nodo->FE++;
          else
             if(rama == IZQUIERDO) nodo->FE++; // ... o borramos
             else                  nodo->FE--;
          if(nodo->FE == 0) salir = true; // La altura de las rama que
                                          // empieza en nodo no ha variado,
                                          // salir de Equilibrar
          else if(nodo->FE == -2) { // Rotar a derechas y salir:
             if(nodo->izquierdo->FE == 1) RDD(nodo); // Rotaci�n doble
             else RSD(nodo);                         // Rotaci�n simple
             salir = true;
          }
          else if(nodo->FE == 2) {  // Rotar a izquierdas y salir:
             if(nodo->derecho->FE == -1) RDI(nodo); // Rotaci�n doble
             else RSI(nodo);                        // Rotaci�n simple
             salir = true;
          }
          if(nodo->padre)
             if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
          nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
       }
    }
    // Rotaci�n doble a derechas
    void RDD(NodoAVL<T>* nodo)
    {
       cout << "RDD" << endl;
       NodoAVL<T> *Padre = nodo->padre;
       NodoAVL<T> *P = nodo;
       NodoAVL<T> *Q = P->izquierdo;
       NodoAVL<T> *R = Q->derecho;
       NodoAVL<T> *B = R->izquierdo;
       NodoAVL<T> *C = R->derecho;

       if(Padre)
         if(Padre->derecho == nodo) Padre->derecho = R;
         else Padre->izquierdo = R;
       else raiz = R;

       // Reconstruir �rbol:
       Q->derecho = B;
       P->izquierdo = C;
       R->izquierdo = Q;
       R->derecho = P;

       // Reasignar padres:
       R->padre = Padre;
       P->padre = Q->padre = R;
       if(B) B->padre = Q;
       if(C) C->padre = P;

       // Ajustar valores de FE:
       switch(R->FE) {
          case -1: Q->FE = 0; P->FE = 1; break;
          case 0:  Q->FE = 0; P->FE = 0; break;
          case 1:  Q->FE = -1; P->FE = 0; break;
       }
       R->FE = 0;
    }

    // Rotaci�n doble a izquierdas
    void RDI(NodoAVL<T>* nodo)
    {
       cout << "RDI" << endl;
       NodoAVL<T> *Padre = nodo->padre;
       NodoAVL<T> *P = nodo;
       NodoAVL<T> *Q = P->derecho;
       NodoAVL<T> *R = Q->izquierdo;
       NodoAVL<T> *B = R->izquierdo;
       NodoAVL<T> *C = R->derecho;

       if(Padre)
         if(Padre->derecho == nodo) Padre->derecho = R;
         else Padre->izquierdo = R;
       else raiz = R;

       // Reconstruir �rbol:
       P->derecho = B;
       Q->izquierdo = C;
       R->izquierdo = P;
       R->derecho = Q;

       // Reasignar padres:
       R->padre = Padre;
       P->padre = Q->padre = R;
       if(B) B->padre = P;
       if(C) C->padre = Q;

       // Ajustar valores de FE:
       switch(R->FE) {
          case -1: P->FE = 0; Q->FE = 1; break;
          case 0:  P->FE = 0; Q->FE = 0; break;
          case 1:  P->FE = -1; Q->FE = 0; break;
       }
       R->FE = 0;
    }

    // Rotaci�n simple a derechas
    void RSD(NodoAVL<T>* nodo)
    {
       cout << "RSD" << endl;
       NodoAVL<T> *Padre = nodo->padre;
       NodoAVL<T> *P = nodo;
       NodoAVL<T> *Q = P->izquierdo;
       NodoAVL<T> *B = Q->derecho;

       if(Padre)
         if(Padre->derecho == P) Padre->derecho = Q;
         else Padre->izquierdo = Q;
       else raiz = Q;

       // Reconstruir �rbol:
       P->izquierdo = B;
       Q->derecho = P;

       // Reasignar padres:
       P->padre = Q;
       if(B) B->padre = P;
       Q->padre = Padre;

       // Ajustar valores de FE:
       P->FE = 0;
       Q->FE = 0;
    }

    // Rotaci�n simple a izquierdas
    void RSI(NodoAVL<T>* nodo)
    {
       cout << "RSI" << endl;
       NodoAVL<T> *Padre = nodo->padre;
       NodoAVL<T> *P = nodo;
       NodoAVL<T> *Q = P->derecho;
       NodoAVL<T> *B = Q->izquierdo;

       if(Padre)
         if(Padre->derecho == P) Padre->derecho = Q;
         else Padre->izquierdo = Q;
       else raiz = Q;

       // Reconstruir �rbol:
       P->derecho = B;
       Q->izquierdo = P;

       // Reasignar padres:
       P->padre = Q;
       if(B) B->padre = P;
       Q->padre = Padre;

       // Ajustar valores de FE:
       P->FE = 0;
       Q->FE = 0;
    }

    // Eliminar un elemento de un �rbol AVL
    void Borrar(NodoAVL<T> * nododel)
    {
       NodoAVL<T> *padre = NULL;
       NodoAVL<T> *nodo;
       int aux;

       actual = raiz;
       // Mientras sea posible que el valor est� en el �rbol
       while(!Vacio(actual)) {
          if(nododel == actual) { // Si el valor est� en el nodo actual
             if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
                if(padre) // Si tiene padre (no es el nodo raiz)
                   // Anulamos el puntero que le hace referencia
                   if(padre->derecho == actual) padre->derecho = NULL;
                   else if(padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                // El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
                // FE es cero, pero debemos seguir el camino a partir de su padre, si existe.
                if((padre->derecho == actual && padre->FE == 1) ||
                   (padre->izquierdo == actual && padre->FE == -1)) {
                   padre->FE = 0;
                   actual = padre;
                   padre = actual->padre;
                }
                if(padre)
                   if(padre->derecho == actual) Equilibrar(padre, DERECHO, false);
                   else                         Equilibrar(padre, IZQUIERDO, false);
                return;
             }
             else { // Si el valor est� en el nodo actual, pero no es hoja
                // Buscar nodo
                padre = actual;
                // Buscar nodo m�s izquierdo de rama derecha
                if(actual->derecho) {
                   nodo = actual->derecho;
                   while(nodo->izquierdo) {
                      padre = nodo;
                      nodo = nodo->izquierdo;
                   }
                }
                // O buscar nodo m�s derecho de rama izquierda
                else {
                   nodo = actual->izquierdo;
                   while(nodo->derecho) {
                      padre = nodo;
                      nodo = nodo->derecho;
                   }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que s�lo se eliminan nodos hoja.
                User udata;
                udata = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = udata;
                actual = nodo;
             }
          }
          else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
             padre = actual;
             User udata = actual->dato;
             User odata = nododel->dato;
             if(odata.cod > udata.cod) actual = actual->derecho;
             else if(odata.cod < udata.cod) actual = actual->izquierdo;
          }
       }
       size--;
    }

    QList<QString> getContactList(){
        NodoAVL<T>* dad= raiz;
        QString contacts = getChildren(dad);
        QList<QString> lista = contacts.split(',');
        return lista;

    }

    QString getChildren(NodoAVL<T>* padre){

        if(hasChildren(padre->izquierdo)) getChildren(padre->izquierdo);
        if(hasChildren(padre->derecho)) getChildren(padre->derecho);

        if(padre->izquierdo){
            User u = padre->izquierdo->getDato();
            contacts+= u.cod +",";
        }
        if(padre->derecho){
            User u = padre->derecho->getDato();
            contacts+= u.cod +",";
        }
        if(padre==raiz){
            User u = padre->getDato();
            contacts+= u.cod;
        }
        return contacts;
    }

    bool hasChildren(NodoAVL<T>* padre){
        if(padre){
        if(padre->izquierdo || padre->derecho) return true;
        }
        return false;
    }
    User Buscar(QString code)
    {
       actual = raiz;
       // Todav�a puede aparecer, ya que quedan nodos por mirar
       while(!Vacio(actual)) {
          us = actual->dato;
          if(code == us.cod) return us; // dato encontrado
          else if(code > us.cod) actual = actual->derecho; // Seguir
          else if(code < us.cod) actual = actual->izquierdo;
       }
       User nu("null");
       return nu; // No est� en �rbol
    }
    NodoAVL<T>* getNode(QString code)
    {
       actual = raiz;
       // Todav�a puede aparecer, ya que quedan nodos por mirar
       while(!Vacio(actual)) {
          us = actual->dato;
          if(code == us.cod) return actual; // dato encontrado
          else if(code > us.cod) actual = actual->derecho; // Seguir
          else if(code < us.cod) actual = actual->izquierdo;
       }
       User nu("null");
       return NULL; // No est� en �rbol
    }

    QList<QString> usersList(){
        texto="";
        loadUsers(raiz);
        QList<QString> lista = texto.split(',');
        int a = lista.size();
        User u = raiz->dato;
        lista[a-1]=u.cod;
        return lista;

    }

    void loadUsers(NodoAVL<T>* padre){

        if(padre->izquierdo && padre->derecho){
            User uder = padre->derecho->dato;
            User uiz = padre->izquierdo->dato;
            texto += uder.cod+","+uiz.cod+",";
            loadUsers(padre->izquierdo);
            loadUsers(padre->derecho);
        }else{
            if(padre->izquierdo){
                User uiz = padre->izquierdo->dato;
                texto += uiz.cod+",";
                loadUsers(padre->izquierdo);
            }
            if(padre->derecho){
                User uder = padre->derecho->dato;
                texto += uder.cod+",";
                loadUsers(padre->derecho);
            }
        }

    }

    void graphAVL(NodoAVL<T>* padre)
    {
        if(padre){
        if(padre->izquierdo && padre->derecho){
            User udata= padre->dato;
            User uder = padre->derecho->dato;
            User uiz = padre->izquierdo->dato;
            texto+="\""+udata.cod+"\" -> \""+uiz.cod+"\";\n";
            texto+="\""+udata.cod+"\" -> \""+uder.cod+"\";\n";
            graphAVL(padre->izquierdo);
            graphAVL(padre->derecho);
        }else{
            if(padre->izquierdo){
                User udata= padre->dato;
                User uiz = padre->izquierdo->dato;
                texto+="\""+udata.cod+"\" -> \""+uiz.cod+"\";\n";
                graphAVL(padre->izquierdo);
            }
            if(padre->derecho){
                User udata= padre->dato;
                User uder = padre->derecho->dato;
                texto+="\""+udata.cod+"\" -> \""+uder.cod+"\";\n";
                graphAVL(padre->derecho);
            }
        }

        }
    }
        void pruebaGraph(){

        qDebug()<<"\nGenerar grafica: ";
        texto="digraph G{ rankdir= \"LR\" \n";
        if(raiz!=NULL){
           graphAVL(raiz);
        }
        texto+="\n }";
        string text = texto.toStdString();
        ofstream outputFile;
        outputFile.open("textograph.txt");
        outputFile <<text <<endl;
        outputFile.close();
        qDebug()<<"\n Archivo generado.\n";
        system("dot -Tpng textograph.txt -o graphBiblio.png");


        //--------------------------
        }

    User getUserData(NodoAVL<T>* padre,QString code,bool search){

        if(hasChildren(padre->izquierdo)) getUserData(padre->izquierdo,code,search);
        if(hasChildren(padre->derecho)) getUserData(padre->derecho,code,search);
        if(search) us = padre->dato;
        if(padre->izquierdo && search){
            us = padre->izquierdo->getDato();
            if(us.cod==code){
                search=false;
                return padre->izquierdo->getDato();
            }else{
                us = padre->dato;
            }
        }
        if(padre->derecho && search){
            us = padre->derecho->getDato();
            if(us.cod==code){
                search=false;
                return padre->derecho->getDato();
            }else{
                us = padre->dato;
            }
        }
        if(padre==raiz && search){
            us = padre->getDato();
            if(us.cod==code){
                search=false;
                return padre->getDato();
            }
        }
        return us;
    }
    User us;
    QString contacts;
    int size=0;
    NodoAVL<T> *raiz;
    QString texto;
private:
    enum {IZQUIERDO, DERECHO};
    // Punteros de la lista, para cabeza y nodo actual:

    NodoAVL<T> *actual;

    int contador;
    int altura;
};
#endif // AVLTREE_H
