#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arbolAVL = new AVLTree<User>();
    mat = new Matriz();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*User u("Arnoldo","Lopez","12/10/98",8021,"12/10/2010","Admin","Es gordito","123");
    arbolAVL->Insertar(u);
    cout<<"Insertado"<<endl;
    User u1("Arnoldo","Lopez","12/10/98",9021,"12/10/2010","Admin","Es gordito","123");
    arbolAVL->Insertar(u1);
    cout<<"Insertado"<<endl;
    User u2("Arnoldo","Lopez","12/10/98",9221,"12/10/2010","Admin","Es gordito","123");
    arbolAVL->Insertar(u2);
    cout<<"Insertado"<<endl;*/

    Teamwork tw("Prograamigos","Somos buenos","456231");
    mat->h->add("Prograamigos","Somos buenos","456231");
    cout<<"Fin";
    cout<<"otra cosa";
    //asd;
}
