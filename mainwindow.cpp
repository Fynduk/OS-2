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
    connect(this,&MainWindow::sendInfoToProcC,procC,&ProcC::getBoolShit);
    connect(this,&MainWindow::sendInfoToProcD,procD,&ProcD::getBoolShit);
    connect(this,&MainWindow::sendInfoToProcE,procE,&ProcE::getBoolShit);
    connect(this,&MainWindow::sendInfoToProcF,procF,&ProcF::getBoolShit);
    connect(this,&MainWindow::sendInfoToProcG,procG,&ProcG::getBoolShit);
    connect(this,&MainWindow::sendInfoToProcH,procH,&ProcH::getBoolShit);
    connect(this,&MainWindow::sendInfoToProcK,procK,&ProcK::getBoolShit);

    connect(procA,&ProcA::sendInfoA,this,&MainWindow::setInfoAboutProc);
    connect(procB,&ProcB::sendInfoB,this,&MainWindow::setInfoAboutProc);
    connect(procC,&ProcC::sendInfoC,this,&MainWindow::setInfoAboutProc);
    connect(procD,&ProcD::sendInfoD,this,&MainWindow::setInfoAboutProc);
    connect(procE,&ProcE::sendInfoE,this,&MainWindow::setInfoAboutProc);
    connect(procF,&ProcF::sendInfoF,this,&MainWindow::setInfoAboutProc);
    connect(procG,&ProcG::sendInfoG,this,&MainWindow::setInfoAboutProc);
    connect(procH,&ProcH::sendInfoH,this,&MainWindow::setInfoAboutProc);
    connect(procK,&ProcK::sendInfoK,this,&MainWindow::setInfoAboutProc);

    connect(procA,&ProcA::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procB,&ProcB::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procC,&ProcC::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procD,&ProcD::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procE,&ProcE::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procF,&ProcF::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procG,&ProcG::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procH,&ProcH::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
    connect(procK,&ProcK::sendUpdateProgressBar,this,&MainWindow::setProgressBar);
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
            ui->label_t_C->setText(QString::number(mSecToSec(endTime)));
            ui->label_t_D->setText(QString::number(mSecToSec(endTime)));
            emit sendInfoToProcB(m_r1, m_r2, m_r3);
            emit sendInfoToProcC(m_r1, m_r2, m_r3);
            emit sendInfoToProcD(m_r1, m_r2, m_r3);
        break;
        case 'B':
            ui->label_t_A_2->text().toDouble();
            ui->label_B->setText(QString(procName));
            ui->label_par_B->setText(parentName);
            ui->label_par_B_2->setText(newProc);
            //ui->label_t_B->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_B_2->setText(QString::number(ui->label_t_A_2->text().toDouble() + mSecToSec(endTime)));
            ui->label_B_resualt->setText(answer);
            m_vec.append('B');
            bool r1;
            answer == "1" ? r1 = 1 : r1 = 0;
            m_r1 = r1;
        break;
        case 'C':
            ui->label_C->setText(QString(procName));
            ui->label_par_C->setText(parentName);
            ui->label_par_C_2->setText(newProc);
            //ui->label_t_C->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_C_2->setText(QString::number(ui->label_t_A_2->text().toDouble() + mSecToSec(endTime)));
            ui->label_C_resualt->setText(answer);
            ui->label_t_E->setText(QString::number(ui->label_t_C_2->text().toDouble()));
            bool infoToProcE;
            answer == "1" ? infoToProcE = 1 : infoToProcE = 0;
            emit sendInfoToProcE(infoToProcE);
        break;
        case 'D':
            ui->label_D->setText(QString(procName));
            ui->label_par_D->setText(parentName);
            ui->label_par_D_2->setText(newProc);
            //ui->label_t_D->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_D_2->setText(QString::number(ui->label_t_A_2->text().toDouble() + mSecToSec(endTime)));
            ui->label_D_resualt->setText(answer);
            m_vec.append('D');
            bool r2;
            answer == "1" ? r2 = 1 : r2 = 0;
            m_r2 = r2;
        break;
        case 'E':
            ui->label_E->setText(QString(procName));
            ui->label_par_E->setText(parentName);
            ui->label_par_E_2->setText(newProc);
            //ui->label_t_E->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_E_2->setText(QString::number(ui->label_t_C_2->text().toDouble() + mSecToSec(endTime)));
            ui->label_E_resualt->setText(answer);
            m_vec.append('E');
            bool r3;
            answer == "1" ? r3 = 1 : r3 = 0;
            m_r3 = r3;
        break;
        case 'F':
            ui->label_F->setText(QString(procName));
            //ui->label_par_F->setText(parentName);
            ui->label_par_F_2->setText(newProc);
            //ui->label_t_E->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_F_2->setText(QString::number(ui->label_t_F->text().toDouble() + mSecToSec(endTime)));
            ui->label_F_resualt->setText(answer);
            m_vec.append('F');
            answer == "1" ? r1 = 1 : r1 = 0;
            m_r1 = r1;
        break;
        case 'G':
            ui->label_G->setText(QString(procName));
            //ui->label_par_G->setText(parentName);
            ui->label_par_G_2->setText(newProc);
            //ui->label_t_G->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_G_2->setText(QString::number(ui->label_t_G->text().toDouble() + mSecToSec(endTime)));
            ui->label_G_resualt->setText(answer);
            m_vec.append('G');
            answer == "1" ? r2 = 1 : r2 = 0;
            m_r2 = r2;
        break;
        case 'H':
            ui->label_H->setText(QString(procName));
            //ui->label_par_H->setText(parentName);
            ui->label_par_H_2->setText(newProc);
            //ui->label_t_H->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_H_2->setText(QString::number(ui->label_t_H->text().toDouble() + mSecToSec(endTime)));
            ui->label_H_resualt->setText(answer);
            m_vec.append('H');
            answer == "1" ? r3 = 1 : r3 = 0;
            m_r3 = r3;
        break;
        case 'K':
            ui->label_K->setText(QString(procName));
            //ui->label_par_K->setText(parentName);
            ui->label_par_K_2->setText(newProc);
            //ui->label_t_K->setText(QString::number(mSecToSec(startTime)));
            ui->label_t_K_2->setText(QString::number(ui->label_t_K->text().toDouble() + mSecToSec(endTime)));
            ui->label_K_resualt->setText(answer);
            m_vec.append('K');
        break;
    }
    if(m_vec.size()==3){
        qDebug()<<m_vec[2];
        switch (m_vec[2]) {
            case 'B':
                ui->label_par_B_2->setText("F,G,H");
                ui->label_par_F->setText("B");
                ui->label_t_F->setText(QString::number(ui->label_t_B_2->text().toDouble()));
                ui->label_par_G->setText("B");
                ui->label_t_G->setText(QString::number(ui->label_t_B_2->text().toDouble()));
                ui->label_par_H->setText("B");
                ui->label_t_H->setText(QString::number(ui->label_t_B_2->text().toDouble()));
                ui->label_par_D_2->setText("-");
                ui->label_par_E_2->setText("-");
                emit sendInfoToProcF(m_r1, m_r2, m_r3);
                emit sendInfoToProcG(m_r1, m_r2, m_r3);
                emit sendInfoToProcH(m_r1, m_r2, m_r3);
            break;
            case 'D':
                ui->label_par_D_2->setText("F,G,H");
                ui->label_par_F->setText("D");
                ui->label_t_F->setText(QString::number(ui->label_t_D_2->text().toDouble()));
                ui->label_par_G->setText("D");
                ui->label_t_G->setText(QString::number(ui->label_t_D_2->text().toDouble()));
                ui->label_par_H->setText("D");
                ui->label_t_H->setText(QString::number(ui->label_t_D_2->text().toDouble()));
                ui->label_par_B_2->setText("-");
                ui->label_par_E_2->setText("-");
                emit sendInfoToProcF(m_r1, m_r2, m_r3);
                emit sendInfoToProcG(m_r1, m_r2, m_r3);
                emit sendInfoToProcH(m_r1, m_r2, m_r3);
            break;
            case 'E':
                ui->label_par_E_2->setText("F,G,H");
                ui->label_par_F->setText("E");
                ui->label_t_F->setText(QString::number(ui->label_t_E_2->text().toDouble()));
                ui->label_par_G->setText("E");
                ui->label_t_G->setText(QString::number(ui->label_t_E_2->text().toDouble()));
                ui->label_par_H->setText("E");
                ui->label_t_H->setText(QString::number(ui->label_t_E_2->text().toDouble()));
                ui->label_par_D_2->setText("-");
                ui->label_par_B_2->setText("-");
                emit sendInfoToProcF(m_r1, m_r2, m_r3);
                emit sendInfoToProcG(m_r1, m_r2, m_r3);
                emit sendInfoToProcH(m_r1, m_r2, m_r3);
            break;
        }
    }

    if(m_vec.size()==6){
        qDebug()<<m_vec[5];
        switch (m_vec[5]) {
            case 'F':
                ui->label_par_F_2->setText("K");
                ui->label_par_K->setText("F");
                ui->label_t_K->setText(QString::number(ui->label_t_F_2->text().toDouble()));
                ui->label_par_G_2->setText("-");
                ui->label_par_H_2->setText("-");
                emit sendInfoToProcK(m_r1, m_r2, m_r3);
            break;
            case 'G':
                ui->label_par_G_2->setText("K");
                ui->label_par_K->setText("G");
                ui->label_t_K->setText(QString::number(ui->label_t_G_2->text().toDouble()));
                ui->label_par_F_2->setText("-");
                ui->label_par_H_2->setText("-");
                emit sendInfoToProcK(m_r1, m_r2, m_r3);
            break;
            case 'H':
                ui->label_par_H_2->setText("K");
                ui->label_par_K->setText("H");
                ui->label_t_K->setText(QString::number(ui->label_t_H_2->text().toDouble()));
                ui->label_par_G_2->setText("-");
                ui->label_par_F_2->setText("-");
                emit sendInfoToProcK(m_r1, m_r2, m_r3);
            break;
        }
    }
}

void MainWindow::on_pushButton_Start_clicked()
{
    emit sendInfoToProcA(m_r1, m_r2, m_r3);
}
