#ifndef PROCH_H
#define PROCH_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcH : public QObject
{
    Q_OBJECT
public:
    explicit ProcH(QObject *parent = nullptr);
    ~ProcH();
    void Start();

signals:
    void sendInfoH(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);
public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCH_H
