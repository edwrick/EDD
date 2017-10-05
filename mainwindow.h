#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "avltree.h"
#include "user.h"
#include "matriz.h"
#include <QMainWindow>

namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void drawPDF();
    void on_pushButton_clicked();
    void cargarJsonContacts();
    void cargarJsonAct();
    void cargarJsonPro();
    void cargarJsonTW();
    void loadDash();
    void loadTw();
    void loadPro();
    void loadUsers();
    void loadAct();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_btnSaveTW_clicked();

    void on_twCB_currentIndexChanged(int index);

    void on_proProCB_activated(const QString &arg1);

    void on_proProCB_currentIndexChanged(const QString &arg1);

    void on_proProCB_currentIndexChanged(int index);

    void on_btnGraphAVL_clicked();

    void on_userCB_currentIndexChanged(int index);

    void on_proActCB_currentIndexChanged(int index);

    void on_twActCB_currentIndexChanged(int index);

    void on_actList_activated(const QModelIndex &index);

    void on_btnPDFUser_clicked();

private:
    NodoOrto* nodito;
    Ui::MainWindow *ui;
    AVLTree<User> *arbolAVL;
    Matriz *mat;
};

#endif // MAINWINDOW_H
