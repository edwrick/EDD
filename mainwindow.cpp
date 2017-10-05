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
    ui->rolUserCB->addItem("Administrador");
    ui->rolUserCB->addItem("Especialista");
    ui->rolUserCB->addItem("Líder");
    ui->rolUserCB->addItem("Operativo");
    ui->tableWidget->setStyleSheet("QTableWidget::item{background-color: #EFEBE7;}");
    QTableWidgetItem * protoitem = new QTableWidgetItem("asd");
     protoitem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItemPrototype(protoitem);
    //ui->tableWidget->setItem(0,0,protoitem);
    //ui->tableWidget->setItem(0,1,new QTableWidgetItem("Hello 2"));
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setColumnWidth(0,500);
    ui->tableWidget->setColumnWidth(1,500);
    ui->tableWidget->setRowCount(15);
    ui->twFrame->setVisible(false);
    ui->dbFrame->setGeometry(10,50,731,371);
    ui->dbFrame->setVisible(true);
    ui->prioriActCB->addItem("urgente");
    ui->prioriActCB->addItem("alta");
    ui->prioriActCB->addItem("media");
    ui->prioriActCB->addItem("baja");
    ui->estadoActCB->addItem("en ejecucion");
    ui->estadoActCB->addItem("pendiente");
    ui->estadoActCB->addItem("en pausa");
    ui->estadoActCB->addItem("finalizada");
    ui->estadoActCB->addItem("cancelada");
    /*model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));
*/
    nodito = new NodoOrto();
    arbolAVL = new AVLTree<User>();
    mat = new Matriz();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDash(){
    int c = mat->l->size;
    for(int i=0; i<c;i++){
        QTableWidgetItem *it=new QTableWidgetItem(mat->l->getTitle(i));
        it->setForeground(QBrush(QColor("#be8019")));
         it->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget->setItem(i+1,0,it);
         QFont font = ui->tableWidget->item(i+1,0)->font();
         font.setBold(true);
         font.setOverline(true);
         //font.setUnderline(true);
         ui->tableWidget->item(i+1,0)->setFont( font );
    }

int z = mat->h->size;
    for(int i=0; i<z;i++){
        QTableWidgetItem *it=new QTableWidgetItem(mat->h->getName(i));
        it->setForeground(QBrush(QColor("#2d1f1a")));
         it->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget->setItem(0,i+1,it);
         QFont font = ui->tableWidget->item(0,i+1)->font();
         font.setBold(true);
         font.setOverline(true);
         //font.setUnderline(true);
         ui->tableWidget->item(0,i+1)->setFont( font );
    }

    for(int i=0;i<z;i++){
        int columnsize = mat->h->search(i)->column->size;
        for(int j=0;j<columnsize;j++){
            NodoOrto* temp;
            temp = mat->h->search(i)->column->searchByPos(j);
            int x= temp->x;
            int y = temp->y;
            QString title = "Tarea con "+ QString::number(temp->listita->size) +" acti";
            QTableWidgetItem *iti = new QTableWidgetItem(title);
            ui->tableWidget->setItem(y+1,x+1,iti);
        }
    }

}

void MainWindow::loadTw(){
    ui->twCB->clear();
    int longi = mat->h->size;
    for(int i=0;i<longi;i++){
        ui->twCB->addItem(mat->h->getNameByPos(i));
    }
}

void MainWindow::loadPro(){
    ui->proProCB->clear();
    int longi = mat->l->size;
    for(int i=0;i<longi;i++){
        ui->proProCB->addItem(mat->l->getNameByPos(i));
    }
}

void MainWindow::loadUsers(){
    ui->userCB->clear();
    QList<QString> users = arbolAVL->getContactList();
    for(int i=0;i<users.size();i++){
        ui->userCB->addItem(users[i]);
        ui->reportUserCB->addItem(users[i]);
    }
}

void MainWindow::loadAct(){
    ui->actList->clear();
    for(int i=0;i<mat->h->size;i++){
        ui->twActCB->addItem(mat->h->getName(i));
    }
    for(int i=0;i<mat->l->size;i++){
        ui->proActCB->addItem(mat->l->getTitle(i));
    }
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
    loadDash();
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
    loadAct();
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
    loadUsers();
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
    loadPro();
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
    loadTw();
}

void MainWindow::on_btnSaveTW_clicked()
{

}

void MainWindow::on_twCB_currentIndexChanged(int index)
{
    ui->listMembersTW->clear();
    cout<< "index ahora es: " << index <<endl;
    if(index>=1){
    NodoHeader* temp = mat->h->getNodeByTitle(ui->twCB->itemText(index));
    ui->txtTWname->setText(temp->getNombre());
    ui->txtDescTW->setText(temp->desc);
    ui->txtEspTW->setText(temp->code);
    int longi = temp->listita->size;
    for(int i=0;i<longi;i++){
        ui->listMembersTW->addItem(temp->listita->getCodeByPos(i));
    }
    }
}

void MainWindow::on_proProCB_currentIndexChanged(int index)
{
    cout<< "index ahora es: " << index <<endl;
    if(index>=0){
    NodoLat* temp = mat->l->getNodeByTitle(ui->proProCB->itemText(index));
    ui->txtTitlePro->setText(temp->getTitle());
    ui->txtDescPro->setText(temp->desc);
    ui->txtIniPro->setText(temp->fechaini);
    ui->txtFinPro->setText(temp->fechaEnd);
    ui->txtEstadoPro->setText(temp->estado);
    ui->txtLiderPro->setText(temp->lider);
    }
}

void MainWindow::on_userCB_currentIndexChanged(int index)
{
    cout<< "index ahora es: " << index <<endl;
    if(index>=0){
    QString prueba = ui->userCB->itemText(index);
    User u = arbolAVL->Buscar(ui->userCB->itemText(index));
    ui->txtUsername->setText(u.nombre);
    ui->txtUserLName->setText(u.apellido);
    ui->txtUsercode->setText(u.cod);
    ui->txtUsername->setText(u.nombre);
    ui->txtPswd->setText(u.pswd);
    ui->txtContractDate->setText(u.fechaC);
    ui->txtBornDate->setText(u.fecha);
    ui->txtAnotaUser->setText(u.anota);
    if(u.rol=="Administrador") ui->rolUserCB->setCurrentIndex(0);
    if(u.rol=="Especialista") ui->rolUserCB->setCurrentIndex(1);
    if(u.rol=="Líder") ui->rolUserCB->setCurrentIndex(2);
    if(u.rol=="Operativo") ui->rolUserCB->setCurrentIndex(3);
    }

}

void MainWindow::on_proActCB_currentIndexChanged(int index)
{
    ui->actList->clear();
    NodoLat* pro = mat->l->getNodeByTitle(ui->proActCB->itemText(index));
    NodoHeader* head = mat->h->getNodeByTitle(ui->twActCB->itemText(ui->twActCB->currentIndex()));
    for(int i=0;i<head->column->size;i++){
        NodoOrto* temp = head->column->searchByPos(i);

        if(pro->y==temp->y){
             nodito=temp;
            for(int j=0;j<temp->listita->size;j++){
                NodoS* aux= temp->listita->getNodeByPos(j);
                QString actividad = aux->title +"\r\n"+aux->fechaE+" || Prioridad:"+aux->prioridad;
                ui->actList->addItem(actividad);
            }
        }
    }
}

void MainWindow::on_twActCB_currentIndexChanged(int index)
{
    ui->actList->clear();
    NodoLat* pro = mat->l->getNodeByTitle(ui->proActCB->itemText(ui->proActCB->currentIndex()));
    NodoHeader* head = mat->h->getNodeByTitle(ui->twActCB->itemText(index));
    for(int i=0;i<head->column->size;i++){
        NodoOrto* temp = head->column->searchByPos(i);

        if(pro->y==temp->y){
            nodito=temp;
            for(int j=0;j<temp->listita->size;j++){
                NodoS* aux= temp->listita->getNodeByPos(j);
                QString actividad = aux->title +"\r\n"+aux->fechaE;
                ui->actList->addItem(actividad);
            }
        }
    }
}

void MainWindow::on_proProCB_activated(const QString &arg1)
{

}

void MainWindow::on_proProCB_currentIndexChanged(const QString &arg1)
{

}



void MainWindow::on_btnGraphAVL_clicked()
{

}





void MainWindow::on_actList_activated(const QModelIndex &index)
{
    QList<QListWidgetItem*> arr = ui->actList->selectedItems();
    QListWidgetItem* b = arr.at(0);
    QString todo = b->text();
    QList<QString> array = todo.split('\n');
    QList<QString> titlearr = array.at(0).split('\r');
    QString title = titlearr.at(0);
    NodoS* act = nodito->listita->getNodeByTitle(title);
    ui->txtActTitle->setText(act->title);
    ui->txtActDate->setText(act->fechaE);
    ui->txtActResp->setText(act->usercode);
    ui->descActCB->setText(act->desc);
    if(act->prioridad =="urgente") ui->prioriActCB->setCurrentIndex(0);
    if(act->prioridad =="alta") ui->prioriActCB->setCurrentIndex(1);
    if(act->prioridad =="media") ui->prioriActCB->setCurrentIndex(2);
    if(act->prioridad =="baja") ui->prioriActCB->setCurrentIndex(3);
    if(act->estado =="en ejecucion") ui->estadoActCB->setCurrentIndex(0);
    if(act->estado =="pendiente") ui->estadoActCB->setCurrentIndex(1);
    if(act->estado =="en pausa") ui->estadoActCB->setCurrentIndex(2);
    if(act->estado =="finalizada") ui->estadoActCB->setCurrentIndex(3);
    if(act->estado =="cancelada") ui->estadoActCB->setCurrentIndex(4);
    cout <<"error";
}
