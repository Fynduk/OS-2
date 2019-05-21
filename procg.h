#ifndef PROCG_H
#define PROCG_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcG : public QObject
{
    Q_OBJECT
public:
    explicit ProcG(QObject *parent = nullptr);
    ~ProcG();
    void Start();

signals:
    void sendInfoG(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);
public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCG_H
