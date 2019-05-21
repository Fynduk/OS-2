#include "procd.h"

ProcD::ProcD(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcD::~ProcD()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcD::Start()
{
    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(4, i*100);
        m_thread.msleep(400);
    }
    bool boolAnswer = (m_r1 & m_r2) & m_r3;
    emit sendInfoD('D', "A", "???", 0, timer->elapsed(), QString::number(boolAnswer));
    emit sendUpdateProgressBar(4, 100);
}

void ProcD::getBoolShit(bool r1, bool r2, bool r3)
{
    m_r1 = r1;
    m_r2 = r2;
    m_r3 = r3;
    Start();
}
