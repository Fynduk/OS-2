#include "proch.h"

ProcH::ProcH(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcH::~ProcH()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcH::Start()
{
    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(8, i*100);
        m_thread.msleep(150);
    }
    bool boolAnswer = (m_r1 | m_r2) & m_r3;
    emit sendInfoH('H', "", "???", 0, timer->elapsed(), QString::number(boolAnswer));
    emit sendUpdateProgressBar(8, 100);
}

void ProcH::getBoolShit(bool r1, bool r2, bool r3)
{
    m_r1 = r1;
    m_r2 = r2;
    m_r3 = r3;
    Start();
}
