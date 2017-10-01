#include "teamwork.h""
#include <QString>

Teamwork::Teamwork(){}

Teamwork::Teamwork(QString nombre,QString desc,QString cod)
{
    this->nombre = nombre;
    this->desc = desc;
    this->cod = cod;


}

QString Teamwork::getName()
{
    return this->nombre;
}


int Teamwork::compare(Teamwork another)
{

}
