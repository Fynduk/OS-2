#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <proca.h>
#include <procb.h>

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

private:
    Ui::MainWindow *ui;
    bool m_r1 = true;
    bool m_r2 = false;
    bool m_r3 = true;
    ProcA* procA = new ProcA(nullptr);
    ProcB* procB = new ProcB(nullptr);
//    ProcA* procC = new ProcC(nullptr);
//    ProcA* procD = new ProcD(nullptr);
//    ProcA* procA = new ProcA(nullptr);
//    ProcA* procA = new ProcA(nullptr);
//    ProcA* procA = new ProcA(nullptr);
//    ProcA* procA = new ProcA(nullptr);
//    ProcA* procA = new ProcA(nullptr);
};

#endif // MAINWINDOW_H
