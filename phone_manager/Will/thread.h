#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QProcess>
#include <QTimer>
class install;
class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QString controltype,int timer_value);
    void run();
    void thread_stop();
    void thread_restart(int);
    void timer_init();
signals:
    void emitSignal(QString);
    void timerSignal(int);
public slots:
    void changeValue();
private:
    int flag;
    int timevalue;
    QString control;
    QProcess *pro;
    QTimer *qtime;
    int game0Value;
    int game1Value;
    int game2Value;
    int game3Value;
    int game4Value;
    int software0Value;
    int software1Value;
    int software2Value;
    int software3Value;
    int software4Value;
    int maxvalue;
};

#endif // THREAD_H
