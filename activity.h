#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <QString>
class Activity
{
public:
    Activity();
    Activity(QString title,QString desc,QString fechaE,QString prioridad,QString estado,int usercode);
    QString getTitle();
    int getUserCode();
    int compare(Activity another);
    QString title;
    QString desc;
    QString fechaE;
    QString prioridad;
    QString estado;
    int usercode;
};
#endif // ACTIVITY_H
