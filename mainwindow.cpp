#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,&MainWindow::sendInfoToProcA,procA,&ProcA::getBoolShit);
    connect(this,&MainWindow::sendInfoToProcB,procB,&ProcB::getBoolShit);

    connect(procA,&ProcA::sendInfoA,this,&MainWindow::setInfoAboutProc);
    connect(procB,&ProcB::sendInfoB,this,&MainWindow::setInfoAboutProc);

    connect(procA,&ProcA::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procB,&ProcB::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::mSecToSec(double mSec)
{
    return mSec/1000;
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString text_r1 = ui->lineEdit->text();

    if(text_r1 == "true"){
        m_r1 = true;
    } else if (text_r1 == "false") {
        m_r1 = false;
    } else {
        // сделать q message
    }

    ui->lineEdit->setReadOnly(true);
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    QString text_r2 = ui->lineEdit_2->text();

    if(text_r2 == "true"){
        m_r2 = true;
    } else if (text_r2 == "false") {
        m_r2 = false;
    } else {
        // сделать q message
    }

    ui->lineEdit_2->setReadOnly(true);
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    QString text_r3 = ui->lineEdit_3->text();

    if(text_r3 == "true"){
        m_r3 = true;
    } else if (text_r3 == "false") {
        m_r3 = false;
    } else {
        // сделать q message
    }

    ui->lineEdit_3->setReadOnly(true);
}

void MainWindow::setProgressBar(int num, int count)
{
    switch (num) {

    case 1:
        ui->progressBar->setValue(count);
        if(count == 100){ui->label_stat_A->setText("Завершен");}
        break;
    case 2:
        ui->progressBar_2->setValue(count);
        if(count == 100){ui->label_stat_B->setText("Завершен");}
        break;
    case 3:
        ui->progressBar_3->setValue(count);
        if(count == 100){ui->label_stat_C->setText("Завершен");}
        break;
    case 4:
        ui->progressBar_4->setValue(count);
        if(count == 100){ui->label_stat_D->setText("Завершен");}
        break;
    case 5:
        ui->progressBar_5->setValue(count);
        if(count == 100){ui->label_stat_E->setText("Завершен");}
        break;
    case 6:
        ui->progressBar_6->setValue(count);
        if(count == 100){ui->label_stat_F->setText("Завершен");}
        break;
    case 7:
        ui->progressBar_7->setValue(count);
        if(count == 100){ui->label_stat_G->setText("Завершен");}
        break;
    case 8:
        ui->progressBar_8->setValue(count);
        if(count == 100){ui->label_stat_H->setText("Завершен");}
        break;
    case 9:
        ui->progressBar_9->setValue(count);
        if(count == 100){ui->label_stat_K->setText("Завершен");}
        break;
    }
}

void MainWindow::setInfoAboutProc(char procName, QString parentName, QString newProc, double startTime, double endTime, QString answer)
{
    switch (procName) {
        case 'A':
            ui->label_A->setText(QString(procName));
            ui->label_par_A->setText(parentName);
            ui->label_par_A_2->setText(newProc);
            ui->label_t_A->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_A_2->setText(QString::number(mSecToSec(endTime)));
            ui->label_A_resualt->setText(answer);
            ui->label_t_B->setText(QString::number(mSecToSec(endTime)));
            emit sendInfoToProcB(m_r1, m_r2, m_r3);
            emit sendInfoToProcC(m_r1, m_r2, m_r3);
            emit sendInfoToProcD(m_r1, m_r2, m_r3);
        break;
        case 'B':
            ui->label_B->setText(QString(procName));
            ui->label_par_B->setText(parentName);
            ui->label_par_B_2->setText(newProc);
            //ui->label_t_B->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_B_2->setText(QString::number(mSecToSec(endTime)));
            ui->label_B_resualt->setText(answer);
        break;
        case 'C':
            ui->label_C->setText(QString(procName));
            ui->label_par_C->setText(parentName);
            ui->label_par_C_2->setText(newProc);
            ui->label_t_C->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_C_2->setText(QString::number(mSecToSec(endTime)));
            ui->label_C_resualt->setText(answer);
        break;
        case 'D':
            ui->label_D->setText(QString(procName));
            ui->label_par_D->setText(parentName);
            ui->label_par_D_2->setText(newProc);
            ui->label_t_D->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_D_2->setText(QString::number(mSecToSec(endTime)));
            ui->label_D_resualt->setText(answer);
        break;
    }
}

void MainWindow::on_pushButton_Start_clicked()
{
    emit sendInfoToProcA(m_r1, m_r2, m_r3);
}
