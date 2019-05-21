#include "prock.h"
#include <QDebug>

ProcK::ProcK(QObject *parent) : QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
    timer = new QElapsedTimer();
}

ProcK::~ProcK()
{
    m_thread.quit();
    m_thread.wait();
}

void ProcK::Start()
{
    timer->start();
    for (double i = 0; i < 1; i+=0.1) {
        emit sendUpdateProgressBar(9, i*100);
        m_thread.msleep(400);
    }
    bool boolAnswer = (m_r1 & m_r2) & (m_r3 | m_r2);
    emit sendInfoK('K', "", "???", 0, timer->elapsed(), QString::number(boolAnswer));
    emit sendUpdateProgressBar(9, 100);
}

void ProcK::getBoolShit(bool r1, bool r2, bool r3)
{
    m_r1 = r1;
    m_r2 = r2;
    m_r3 = r3;
    Start();
}
