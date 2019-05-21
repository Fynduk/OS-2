#ifndef PROCE_H
#define PROCE_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcE : public QObject
{
    Q_OBJECT
public:
    explicit ProcE(QObject *parent = nullptr);
    ~ProcE();
    void Start();

signals:
    void sendInfoE(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);
public slots:
    void getBoolShit(bool r1);

private:
    QThread m_thread;
    bool m_r1;
    QElapsedTimer *timer;
};

#endif // PROCE_H
