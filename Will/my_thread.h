#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>

class My_Thread : public QThread
{
    Q_OBJECT
public:
    explicit My_Thread(QObject *parent = 0);

signals:

public slots:

};

#endif // MY_THREAD_H
