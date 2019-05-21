#ifndef PROCD_H
#define PROCD_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcD : public QObject
{
    Q_OBJECT
public:
    explicit ProcD(QObject *parent = nullptr);
    ~ProcD();
    void Start();

signals:
    void sendInfoD(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);

public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCD_H
