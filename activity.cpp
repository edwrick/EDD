#include "activity.h""
#include <QString>

Activity::Activity(){}

Activity::Activity(QString title,QString desc,QString fechaE,QString prioridad,QString estado,int usercode)
{
    this->title = title;
    this->desc = desc;
    this->fechaE = fechaE;
    this->prioridad = prioridad;
    this->estado = estado;
    this->usercode = usercode;

}

QString Activity::getTitle()
{
    return this->title;
}

int Activity::getUserCode(){
    return this->usercode;
}

int Activity::compare(Activity another)
{

}
