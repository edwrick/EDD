#include "proyect.h""
#include <QString>

Proyect::Proyect(){}

Proyect::Proyect(QString title,QString desc,QString fechaini,QString fechaEnd,QString estado,QString lider)
{
    this->title = title;
    this->desc = desc;
    this->fechaini = fechaini;
    this->fechaEnd = fechaEnd;
    this->estado = estado;
    this->lider = lider;

}

QString Proyect::getTitle()
{
    return this->title;
}


int Proyect::compare(Proyect another)
{

}
