#include "user.h""
#include <QString>

User::User(){}

User::User(QString nombre,QString apellido,QString fecha,int cod,QString fechaC,QString rol,QString anota,QString pswd)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->fecha = fecha;
    this->cod = cod;
    this->fechaC = fechaC;
    this->rol = rol;
    this->anota = anota;
    this->pswd = pswd;
}

int User::getCod()
{
    return this->cod;
}

QString User::getRol()
{
    return this->rol;
}

int User::compare(User another)
{

}
