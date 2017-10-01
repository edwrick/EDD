#ifndef TEAMWORK_H
#define TEAMWORK_H
#include <QString>
class Teamwork
{
public:
    Teamwork();
    Teamwork(QString nombre,QString desc,QString cod);
    QString getName();
    int compare(Teamwork another);
    QString nombre;
    QString desc;
    QString cod;


};
#endif // TEAMWORK_H
