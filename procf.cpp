#include "procf.h"

ProcF::ProcF(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcF::~ProcF()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcF::Start()
{
    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(6, i*100);
        m_thread.msleep(220);
    }
    bool boolAnswer = (m_r1 | m_r2) & m_r3;
    emit sendInfoF('F', "", "???", 0, timer->elapsed(), QString::number(boolAnswer));
    emit sendUpdateProgressBar(6, 100);
}

void ProcF::getBoolShit(bool r1, bool r2, bool r3)
{
    m_r1 = r1;
    m_r2 = r2;
    m_r3 = r3;
    Start();
}
