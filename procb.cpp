#include "procb.h"

ProcB::ProcB(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcB::~ProcB()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcB::Start()
{

    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(2, i*100);
        m_thread.msleep(500);
    }
    bool boolAnswer = m_r1 | m_r2 & m_r3;
    QString answer = QString::number(boolAnswer);
    emit sendInfoB('B', "A", "???", 0, timer->elapsed(), answer);
    emit sendUpdateProgressBar(2, 100);
}

void ProcB::getBoolShit(bool r1, bool r2, bool r3)
{
    m_r1 = r1;
    m_r2 = r2;
    m_r3 = r3;
    Start();
}
