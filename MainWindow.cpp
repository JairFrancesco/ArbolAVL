#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    avl = new ArbolAVL();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//Insertar
{
    msg.setWindowTitle("Insertando Nodo");
    msg.setText("Accion NO Realizada");
    if(ui->txtValor->text() != ""){
        int valor = ui->txtValor->text().toInt();
        avl->Insertar(valor);
        msg.setText("Accion Realizada");
        //cout<<avl->EsVacio(avl->raiz)<<endl;
    }
    msg.exec();
}

void MainWindow::on_pushButton_2_clicked()//Eliminar
{
    msg.setWindowTitle("Eliminando Nodo");
    msg.setText("Accion NO Realizada");
    if(ui->txtValor->text() != ""){
        int valor = ui->txtValor->text().toInt();
        avl->Borrar(avl->raiz, valor);
        msg.setText("Accion Realizada");
    }
    msg.exec();
}

void MainWindow::on_pushButton_3_clicked()//Pertenece
{
    msg.setWindowTitle("Pertenece al Arbol?");
    msg.setText("No Pertenece");
    if(ui->txtValor->text() != ""){
        int valor = ui->txtValor->text().toInt();
        bool pertenece = avl->Pertenece(avl->raiz, valor);
        if(pertenece)
            msg.setText("Si Pertenece");
    }
    msg.exec();
}
