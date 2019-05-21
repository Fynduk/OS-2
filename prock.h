#ifndef PROCK_H
#define PROCK_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcK : public QObject
{
    Q_OBJECT
public:
    explicit ProcK(QObject *parent = nullptr);
    ~ProcK();
    void Start();

signals:
    void sendInfoK(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);
public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCK_H
