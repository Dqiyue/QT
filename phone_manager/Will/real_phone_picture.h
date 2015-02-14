#ifndef REAL_PHONE_PICTURE_H
#define REAL_PHONE_PICTURE_H

#include <QWidget>
#include <QString>
#include<QPushButton>
#include<QSlider>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QProcess>
#include <QMouseEvent>
#include <QPaintEvent>
#include "show_image.h"
class Real_Phone_Picture : public QWidget
{
    Q_OBJECT
public:
    explicit Real_Phone_Picture(QString,QString);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent*);
private slots:
    void turn2next();
    void turn2prev();
    void scalethepix(int);
    void changelabel(int);
    void close_window();
    void img_spin();
private:
    Show_Image *showImage;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QPushButton *spinbutton;
    QPoint m_DragPosition;
    QSlider *slider;
    QLabel *label;
    QProcess *pro;

};

#endif // REAL_PHONE_PICTURE_H
