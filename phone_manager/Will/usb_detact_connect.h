#ifndef USB_DETACT_CONNECT
#define USB_DETACT_CONNECT
#include <QThread>
#include "QDebug"
#include "QProcess"
#include "QTimer"
#include "hintdialog.h"
class detact_thread: public QThread{
    Q_OBJECT
    public:
        detact_thread();
        hintDialog dialog;
    protected:
        void run();
    private slots:
        void time_over();
        void readOutput();
    private:
        QProcess *process;
        QTimer *timer;
        int times;
    private slots:
        void changeTimer();

};
#endif // USB_DETACT_CONNECT

