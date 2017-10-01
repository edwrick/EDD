#ifndef MATRIZ_H
#define MATRIZ_H
#include <QtDebug>
#include "laterales.h"
#include "headers.h"
using namespace std;
class Matriz
{
public:
    Matriz(){
        this->l = new Laterales();
        this->h = new Headers();
    }
    void insert(int x, int y,QString tarea){
        NodoOrto* nodo;
        nodo = new NodoOrto(tarea,x,y);

        NodoHeader* tempH;
        NodoLat* tempL;
        tempH = h->search(x);
        tempL = l->search(y);
        tempH->column->add(nodo);
        tempL->row->add(nodo);
        cout<<"Dato insertado en pos: "<<x<<","<<y<<endl;
    }


    void fill(int x, int y){
        int d=0;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                insert(i,j,"d");
                d++;
            }
        }
    }
    Laterales *l;
    Headers *h;
private:


};
#endif // MATRIZ_H
