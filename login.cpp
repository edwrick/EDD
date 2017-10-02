#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    if (ui->user->text()=="SUP3R" && ui->pswd->text()=="edd1234"){
        MainWindow *x = new MainWindow(0);
        x->show();
        this->hide();
    }
}
