#ifndef SIMPLE_BUTTON_H
#define SIMPLE_BUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include "Common.h"

class Simple_Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Simple_Button(QWidget *parent = 0);
    ~Simple_Button();
    void setMousePress(bool mouse_press);

public:
    bool mouse_over; //鼠标是否移过
    bool mouse_press; //鼠标是否按下


protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void painterInfo(int top_color, int middle_color, int bottom_color);

signals:


public slots:

};

#endif // SIMPLE_BUTTON_H
