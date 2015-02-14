#ifndef THREE_WIDGET_H
#define THREE_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QProcess>
#include <QProgressBar>
#include <QThread>
#include <QTimer>
#include <QStackedLayout>
#include "thread.h"
class Thread;
class Three_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Three_Widget(QWidget *parent = 0);

public slots:
    void game0();
    void game1();
    void game2();
    void game3();
    void game4();
    void software0();
    void software1();
    void software2();
    void software3();
    void software4();
    void game0showstop();
    void game1showstop();
    void game2showstop();
    void game3showstop();
    void game4showstop();
    void software0showstop();
    void software1showstop();
    void software2showstop();
    void software3showstop();
    void software4showstop();
    void game0change(int value);
    void game1change(int value);
    void game2change(int value);
    void game3change(int value);
    void game4change(int value);
    void software0change(int value);
    void software1change(int value);
    void software2change(int value);
    void software3change(int value);
    void software4change(int value);
    void changemode();
    void thread(QString threadname);
private:
    QLabel *game;
    QLabel *software;
    QLabel *game0_imga;
    QLabel *game0_name;
    QLabel *game0_introduce;
    QPushButton *game0_button;
    QPushButton *stop0_button;
    QPushButton *game0_installbutton;
    int game1_count;
    QLabel *game1_imga;
    QLabel *game1_name;
    QLabel *game1_num;
    QLabel *game1_size;
    QLabel *game1_introduce;
    QPushButton *game1_button;
    QPushButton *stop1_button;
    QPushButton *game1_installbutton;
    int game2_count;
    QLabel *game2_imga;
    QLabel *game2_name;
    QLabel *game2_num;
    QLabel *game2_size;
    QLabel *game2_introduce;
    QPushButton *game2_button;
    QPushButton *stop2_button;
    QPushButton *game2_installbutton;
    int game3_count;
    QLabel *game3_imga;
    QLabel *game3_name;
    QLabel *game3_num;
    QLabel *game3_size;
    QLabel *game3_introduce;
    QPushButton *game3_button;
    QPushButton *stop3_button;
    QPushButton *game3_installbutton;
    int game4_count;
    QLabel *game4_imga;
    QLabel *game4_name;
    QLabel *game4_num;
    QLabel *game4_size;
    QLabel *game4_introduce;
    QPushButton *game4_button;
    QPushButton *stop4_button;
    QPushButton *game4_installbutton;
    QLabel *software0_imga;
    QLabel *software0_name;
    QLabel *software0_introduce;
    QPushButton *software0_button;
    QPushButton *button_stop0;
    QPushButton *software0_installbutton;
    int software1_count;
    QLabel *software1_imga;
    QLabel *software1_name;
    QLabel *software1_num;
    QLabel *software1_size;
    QLabel *software1_introduce;
    QPushButton *software1_button;
    QPushButton *button_stop1;
    QPushButton *software1_installbutton;
    int software2_count;
    QLabel *software2_imga;
    QLabel *software2_name;
    QLabel *software2_num;
    QLabel *software2_size;
    QLabel *software2_introduce;
    QPushButton *software2_button;
    QPushButton *button_stop2;
    QPushButton *software2_installbutton;
    int software3_count;
    QLabel *software3_imga;
    QLabel *software3_name;
    QLabel *software3_num;
    QLabel *software3_size;
    QLabel *software3_introduce;
    QPushButton *software3_button;
    QPushButton *button_stop3;
    QPushButton *software3_installbutton;
    int software4_count;
    QLabel *software4_imga;
    QLabel *software4_name;
    QLabel *software4_num;
    QLabel *software4_size;
    QLabel *software4_introduce;
    QPushButton *software4_button;
    QPushButton *button_stop4;
    QPushButton *software4_installbutton;
    QProcess *pro;
    QProgressBar * game0_pb;
    QProgressBar * game1_pb;
    QProgressBar * game2_pb;
    QProgressBar * game3_pb;
    QProgressBar * game4_pb;
    QProgressBar * software0_pb;
    QProgressBar * software1_pb;
    QProgressBar * software2_pb;
    QProgressBar * software3_pb;
    QProgressBar * software4_pb;
    int game0value;
    int game1value;
    int game2value;
    int game3value;
    int game4value;
    int software0value;
    int software1value;
    int software2value;
    int software3value;
    int software4value;
    QStackedLayout *qs0;
    QStackedLayout *qs1;
    QStackedLayout *qs2;
    QStackedLayout *qs3;
    QStackedLayout *qs4;
    QStackedLayout *qs_0;
    QStackedLayout *qs_1;
    QStackedLayout *qs_2;
    QStackedLayout *qs_3;
    QStackedLayout *qs_4;
    QStackedLayout *qsbar;
    QString flag;
    Thread *game0_thread;
    Thread *game1_thread;
    Thread *game2_thread;
    Thread *game3_thread;
    Thread *game4_thread;
    Thread *software0_thread;
    Thread *software1_thread;
    Thread *software2_thread;
    Thread *software3_thread;
    Thread *software4_thread;
};

#endif // THREE_WIDGET_H
