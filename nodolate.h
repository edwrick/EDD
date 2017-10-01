#ifndef NODOLATE_H
#define NODOLATE_H
#include "listah.h"
class NodoLat {
public:

    /*
     * Constructor de la clase MyNode
     */
    NodoLat(int y,QString title,QString desc,QString fechaini,QString fechaEnd,QString estado,QString lider) {
        this->title = title;
        this->desc = desc;
        this->fechaini = fechaini;
        this->fechaEnd = fechaEnd;
        this->estado = estado;
        this->lider = lider;
        this->y = y;
        this->ant =nullptr;
        this->next= nullptr;
        this->row = new ListaH();
    }
    /*
     * Metodo para obtener el valor del nodo
     */
    QString getTitle(){
        return this->title;
    }
    QString getDesc(){
        return this->desc;
    }
    QString getFechaIni(){
        return this->fechaini;
    }
    QString getFechaEnd(){
        return this->fechaEnd;
    }
    QString getEstado(){
        return this->estado;
    }
    QString getLider(){
        return this->lider;
    }

    // Apuntador al siguiente nodo
    NodoLat *ant;
    NodoLat *next;
    ListaH* row;
    QString title,desc,fechaini,fechaEnd,estado,lider;
    int y;
private:
    // Valor
};
#endif // NODOLATE_H
