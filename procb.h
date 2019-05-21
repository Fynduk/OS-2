#ifndef PROCB_H
#define PROCB_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcB : public QObject
{
    Q_OBJECT
public:
    explicit ProcB(QObject *parent = nullptr);
    ~ProcB();
    void Start();

signals:
    void sendInfoB(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);
public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCB_H
