#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString text_r1 = ui->lineEdit->text();
    bool r1 = true;
    if(text_r1 == "true"){
        r1 = true;
    } else if (text_r1 == "false") {
        r1 = false;
    } else {
        // сделать q message
    }

}

void MainWindow::on_lineEdit_2_editingFinished()
{
    QString text_r2 = ui->lineEdit_2->text();
    bool r2 = false;
    if(text_r2 == "true"){
        r2 = true;
    } else if (text_r2 == "false") {
        r2 = false;
    } else {
        // сделать q message
    }

}


void MainWindow::on_lineEdit_3_editingFinished()
{
    QString text_r3 = ui->lineEdit_3->text();
    bool r3 = true;
    if(text_r3 == "true"){
        r3 = true;
    } else if (text_r3 == "false") {
        r3 = false;
    } else {
        // сделать q message
    }

}
