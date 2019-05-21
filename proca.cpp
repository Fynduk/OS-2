#include "proca.h"

ProcA::ProcA(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcA::~ProcA()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcA::Start()
{
    QString answer = QString::number(m_r1) + "," + QString::number(m_r2) + "," + QString::number(m_r3);
    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(1, i*100);
        m_thread.msleep(350);
    }
    emit sendInfoA('A', "-", "B, C, D", 0, timer->elapsed(), answer);
    emit sendUpdateProgressBar(1, 100);
}

void ProcA::getBoolShit(bool r1, bool r2, bool r3)
{
    m_r1 = r1;
    m_r2 = r2;
    m_r3 = r3;
    Start();
}
