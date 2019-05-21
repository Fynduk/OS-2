#ifndef PROCC_H
#define PROCC_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>

class ProcC : public QObject
{
    Q_OBJECT
public:
    explicit ProcC(QObject *parent = nullptr);
    ~ProcC();
    void Start();

signals:
    void sendInfoC(char, QString, QString, double, double, QString);
    void sendUpdateProgressBar(int, int);

public slots:
    void getBoolShit(bool r1, bool r2, bool r3);

private:
    QThread m_thread;
    bool m_r1, m_r2, m_r3;
    QElapsedTimer *timer;
};

#endif // PROCC_H
