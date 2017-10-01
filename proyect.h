#ifndef PROYECT_H
#define PROYECT_H
#include <QString>
class Proyect
{
public:
    Proyect();
    Proyect(QString title,QString desc,QString fechaini,QString fechaEnd,QString estado,QString lider);
    QString getTitle();
    int compare(Proyect another);
    QString title;
    QString desc;
    QString fechaini;
    QString fechaEnd;
    QString estado;
    QString lider;

};
#endif // PROYECT_H
