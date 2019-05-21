#include "procc.h"

ProcC::ProcC(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcC::~ProcC()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcC::Start()
{
    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(3, i*100);
        m_thread.msleep(250);
    }
    bool boolAnswer = (m_r1 & m_r2) | m_r3;
    emit sendInfoC('C', "A", "E", 0, timer->elapsed(), QString::number(boolAnswer));
    emit sendUpdateProgressBar(3, 100);
}

void ProcC::getBoolShit(bool r1, bool r2, bool r3)
{
    m_r1 = r1;
    m_r2 = r2;
    m_r3 = r3;
    Start();
}
