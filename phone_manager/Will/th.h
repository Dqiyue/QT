#ifndef TH_H
#define TH_H

#include <QThread>

class Th : public QThread
{
    Q_OBJECT
public:
    explicit Th(QObject *parent = 0);
    void run();
signals:

public slots:

};

#endif // TH_H
