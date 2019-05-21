#ifndef PROCA_H
#define PROCA_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcA : public QObject
{
    Q_OBJECT
public:
    explicit ProcA(QObject *parent = nullptr);
    ~ProcA();
    void Start();

signals:
    void sendInfoA(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);

public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCA_H
