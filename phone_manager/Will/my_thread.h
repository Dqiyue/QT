#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>
#include <QProcess>

class My_Thread : public QThread
{
    Q_OBJECT
public:
    explicit My_Thread(QObject *parent = 0);

signals:

public slots:

public:
   // QString real_input;

public:
   //  QString script_run(QString input);
 //   void set_input(QString input);
};

#endif // MY_THREAD_H
