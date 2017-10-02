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
    void on_pushButton_clicked();
    void cargarJsonContacts();
    void cargarJsonAct();
    void cargarJsonPro();
    void cargarJsonTW();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:

    Ui::MainWindow *ui;
    AVLTree<User> *arbolAVL;
    Matriz *mat;
};

#endif // MAINWINDOW_H
