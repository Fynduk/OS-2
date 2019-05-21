#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <proca.h>
#include <procb.h>
#include <procc.h>
#include <procd.h>
#include <proce.h>
#include <procf.h>
#include <procg.h>
#include <proch.h>
#include <prock.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double mSecToSec(double);

private slots:
    void on_lineEdit_editingFinished();
    void on_lineEdit_2_editingFinished();
    void on_lineEdit_3_editingFinished();
    void setProgressBar(int, int);
    void setInfoAboutProc(char, QString, QString, double, double, QString);
    void on_pushButton_Start_clicked();

signals:
    void sendInfoToProcA(bool, bool, bool);
    void sendInfoToProcB(bool, bool, bool);
    void sendInfoToProcC(bool, bool, bool);
    void sendInfoToProcD(bool, bool, bool);
    void sendInfoToProcE(bool);
    void sendInfoToProcF(bool, bool, bool);
    void sendInfoToProcG(bool, bool, bool);
    void sendInfoToProcH(bool, bool, bool);
    void sendInfoToProcK(bool, bool, bool);

private:
    Ui::MainWindow *ui;
    bool m_r1 = true;
    bool m_r2 = false;
    bool m_r3 = true;

    QVector<char> m_vec;
    ProcA* procA = new ProcA(nullptr);
    ProcB* procB = new ProcB(nullptr);
    ProcC* procC = new ProcC(nullptr);
    ProcD* procD = new ProcD(nullptr);
    ProcE* procE = new ProcE(nullptr);
    ProcF* procF = new ProcF(nullptr);
    ProcG* procG = new ProcG(nullptr);
    ProcH* procH = new ProcH(nullptr);
    ProcK* procK = new ProcK(nullptr);
};

#endif // MAINWINDOW_H
