#include "proce.h"

ProcE::ProcE(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcE::~ProcE()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcE::Start()
{
    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(5, i*100);
        m_thread.msleep(220);
    }
    bool boolAnswer = !m_r1;
    emit sendInfoE('E', "C", "???", 0, timer->elapsed(), QString::number(boolAnswer));
    emit sendUpdateProgressBar(5, 100);
}

void ProcE::getBoolShit(bool r1)
{
    m_r1 = r1;
    Start();
}
