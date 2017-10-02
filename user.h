#ifndef USER_H
#define USER_H
#include <QString>
class User
{
public:
    User();
    User(QString code);
    User(QString nombre,QString apellido,QString fecha,QString cod,QString fechaC,QString rol,QString anota,QString pswd,QString mail);
    QString getRol();
    QString getCod();
    int compare(User another);
    QString nombre;
    QString apellido;
    QString fecha;
    QString mail;
    QString cod;
    QString fechaC;
    QString rol;
    QString anota;
    QString pswd;
};
#endif // USER_H
