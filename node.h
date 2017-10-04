#ifndef NODE_H
#define NODE_H
#include "QString"
class NodoS {
public:

    /*
     * Constructor de la clase MyNode
     */
    NodoS(QString title,QString desc,QString fechaE,QString prioridad,QString estado,QString usercode) {
        this->title = title;
        this->desc = desc;
        this->fechaE = fechaE;
        this->prioridad = prioridad;
        this->estado = estado;
        this->usercode = usercode;
        this->next = nullptr;
    }

    NodoS(QString usercode){
        this->next=nullptr;
        this->usercode=usercode;
    }
    /*
     * Metodo para obtener el valor del nodo
     */

    QString getTitle() {
        return this->title;
    }
    QString getDesc() {
        return this->desc;
    }
    QString getFechaE() {
        return this->fechaE;
    }
    QString getEstado() {
        return this->estado;
    }
    QString getPrioridad() {
        return this->prioridad;
    }

    // Apuntador al siguiente nodo
    NodoS *next;
    QString usercode;
private:
    // Valor
    QString title,desc,fechaE,prioridad,estado;


};
#endif // NODE_H
