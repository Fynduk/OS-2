#ifndef PROCF_H
#define PROCF_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcF : public QObject
{
    Q_OBJECT
public:
    explicit ProcF(QObject *parent = nullptr);
    ~ProcF();
    void Start();

signals:
    void sendInfoF(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);
public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCF_H
