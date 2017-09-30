#ifndef USER_H
#define USER_H
#include <QString>
class User
{
public:
    User();
    User(QString nombre,QString apellido,QString fecha,int cod,QString fechaC,QString rol,QString anota,QString pswd);
    QString getRol();
    int getCod();
    int compare(User another);

    QString nombre;
    QString apellido;
    QString fecha;
    int cod;
    QString fechaC;
    QString rol;
    QString anota;
    QString pswd;
};
#endif // USER_H
