#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qjsondocument.h"
#include "qjsonarray.h"
#include "qjsonobject.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QStandardItemModel>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(80,80,745,500);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setStyleSheet("QTableWidget::item{background-color: #EFEBE7;}");
    QTableWidgetItem * protoitem = new QTableWidgetItem("asd");
     protoitem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItemPrototype(protoitem);
    ui->tableWidget->setItem(0,0,protoitem);
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("Hello 2"));
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setRowCount(15);
    ui->twFrame->setVisible(false);
    ui->dbFrame->setGeometry(10,50,731,371);
    ui->dbFrame->setVisible(true);
    /*model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));
*/

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

    /*Teamwork tw("Prograamigos","Somos buenos","456231");
    mat->h->add("Prograamigos","Somos buenos","456231");
    cout<<"Fin";
    cout<<"otra cosa";
    //asd;*/
    cargarJsonAct();
}

void MainWindow::cargarJsonContacts(){
    QString fname = QFileDialog::getOpenFileName(this);
    QFile file(fname);
    file.open(QFile::ReadOnly | QFile::Text);
    QString val;
          QTextStream ReadFile(&file);
          val = ReadFile.readAll();
          file.close();
          qWarning() << val;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    if(doc.isArray()){
        QJsonArray array = doc.array();
        for(int i = 0; i < array.size(); i++){
            QJsonObject elem = array[i].toObject();
            qDebug() << "Usuario:";
            qDebug() << "\tcodigo -> " << elem["codigo"].toString();
            qDebug() << "\tnombres -> " << elem["nombres"].toString();
            User u(elem["nombres"].toString(),elem["apellidos"].toString(),elem["fecha_nacimiento"].toString(),elem["codigo"].toString(),elem["fecha_contrato"].toString(),elem["rol"].toString(),elem["anotaciones"].toString(),elem["password"].toString(),elem["correo"].toString());
            arbolAVL->Insertar(u);
        }
    }
    string s;
}
void MainWindow::cargarJsonTW(){
    QString fname = QFileDialog::getOpenFileName(this);
    QFile file(fname);
    file.open(QFile::ReadOnly | QFile::Text);
    QString val;
          QTextStream ReadFile(&file);
          val = ReadFile.readAll();
          file.close();
          qWarning() << val;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    if(doc.isArray()){
        QJsonArray array = doc.array();
        for(int i = 0; i < array.size(); i++){
            QJsonObject elem = array[i].toObject();
            mat->h->add(elem["nombre"].toString(),elem["descripcion"].toString(),elem["especialista"].toString());
            QJsonArray arrayHijo = elem["empleados"].toArray();
            for(int j=0;j<arrayHijo.size();j++){
                mat->h->search(mat->h->searchWTitle(elem["nombre"].toString()))->listita->addUserCode(arrayHijo[j].toString());
            }

        }
    }
    string s;
}
void MainWindow::cargarJsonPro(){
    QString fname = QFileDialog::getOpenFileName(this);
    QFile file(fname);
    file.open(QFile::ReadOnly | QFile::Text);
    QString val;
          QTextStream ReadFile(&file);
          val = ReadFile.readAll();
          file.close();
          qWarning() << val;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    if(doc.isArray()){
        QJsonArray array = doc.array();
        for(int i = 0; i < array.size(); i++){
            QJsonObject elem = array[i].toObject();
            qDebug() << "Proyecto:";
            mat->l->add(elem["titulo"].toString(),elem["descripcion"].toString(),elem["fecha_inicio"].toString(),elem["fecha_final"].toString(),elem["estado"].toString(),elem["lider"].toString());
        }
    }
    string s;
}
void MainWindow::cargarJsonAct(){
    QString fname = QFileDialog::getOpenFileName(this);
    QFile file(fname);
    file.open(QFile::ReadOnly | QFile::Text);
    QString val;
          QTextStream ReadFile(&file);
          val = ReadFile.readAll();
          file.close();
          qWarning() << val;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    if(doc.isArray()){
        QJsonArray arrayPadre = doc.array();
        for(int i = 0; i < arrayPadre.size(); i++){
            QJsonObject elem = arrayPadre[i].toObject();
            int x =mat->h->searchWTitle(elem["equipo"].toString());
            int y = mat->l->searchWTitle(elem["proyecto"].toString());
            mat->insert(x,y,"Tarea"+i);
            QJsonArray arrayHijo = elem["actividades"].toArray();
            for(int j=0;j<arrayHijo.size();j++){
                QJsonObject elemhijo = arrayHijo[j].toObject();
                NodoOrto* temp;
                temp = mat->search(x,y);
                temp->listita->add(elemhijo["titulo"].toString(),elemhijo["descripcion"].toString(),elemhijo["fecha_entrega"].toString(),elemhijo["prioridad"].toString(),elemhijo["estado"].toString(),elemhijo["responsable"].toString());
            }
        }
    }
    string s;
}

void MainWindow::on_pushButton_2_clicked()
{
    cargarJsonContacts();
}

void MainWindow::on_pushButton_3_clicked()
{
    cargarJsonPro();
}

void MainWindow::on_pushButton_4_clicked()
{
    cargarJsonTW();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("amigos"));
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->jsonframe->setVisible(false);
    ui->dbFrame->setGeometry(10,50,731,371);
    ui->dbFrame->setVisible(true);
    ui->userFrame->setVisible(false);
    ui->actFrame->setVisible(false);
    ui->proFrame->setVisible(false);
    ui->twFrame->setVisible(false);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->jsonframe->setGeometry(10,120,731,111);
    ui->dbFrame->setVisible(false);
    ui->jsonframe->setVisible(true);
    ui->userFrame->setVisible(false);
    ui->actFrame->setVisible(false);
    ui->proFrame->setVisible(false);
    ui->twFrame->setVisible(false);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->actFrame->setGeometry(10,50,731,371);
    ui->actFrame->setVisible(true);
    ui->dbFrame->setVisible(false);
    ui->jsonframe->setVisible(false);
    ui->userFrame->setVisible(false);
    ui->proFrame->setVisible(false);
    ui->twFrame->setVisible(false);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->userFrame->setGeometry(100,50,511,401);
    ui->userFrame->setVisible(true);
    ui->jsonframe->setVisible(false);
    ui->dbFrame->setVisible(false);
    ui->actFrame->setVisible(false);
    ui->proFrame->setVisible(false);
    ui->twFrame->setVisible(false);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->proFrame->setGeometry(50,50,651,401);
    ui->proFrame->setVisible(true);
    ui->userFrame->setVisible(false);
    ui->jsonframe->setVisible(false);
    ui->dbFrame->setVisible(false);
    ui->actFrame->setVisible(false);
    ui->twFrame->setVisible(false);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->twFrame->setGeometry(120,50,491,391);
    ui->twFrame->setVisible(true);
    ui->proFrame->setVisible(false);
    ui->userFrame->setVisible(false);
    ui->jsonframe->setVisible(false);
    ui->dbFrame->setVisible(false);
    ui->actFrame->setVisible(false);
}
