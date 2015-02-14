#ifndef START_WIDGET_H
#define START_WIDGET_H

#include "shdow_pro.h"
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QSplitter>
#include "main_widget.h"
#include "Common.h"

class Start_Widget : public Shdow_Pro
{
    Q_OBJECT
public:
    explicit Start_Widget(QWidget *parent = 0);
    ~Start_Widget();

signals:




public slots:

private slots:
//    void hide_and_seek();
        void main_start();


protected:
     virtual void paintEvent(QPaintEvent *event);

public:
    void show_widget();
     void start_view();


private:

//    void end_view();
    void initup();


private:

    QLabel *logo;
    QSplitter *mainsplitter;
    QPushButton *start_button;
    QLabel *welcome_label;
    QVBoxLayout *main_layout;
    QPropertyAnimation *start_animation;
    QPropertyAnimation *txt_animation;
    QWidget *up;
//    QWidget *down;
    QVBoxLayout *my_layout;
    QVBoxLayout *layout;
    Main_Widget *here_we_go;


};

#endif // START_WIDGET_H
