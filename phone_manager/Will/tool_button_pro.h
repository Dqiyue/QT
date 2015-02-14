#ifndef TOOL_BUTTON_PRO_H
#define TOOL_BUTTON_PRO_H

#include <QToolButton>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include "Common.h"

class Tool_Button_Pro : public QToolButton
{
    Q_OBJECT
public:
    explicit Tool_Button_Pro(QString name, QWidget *parent = 0);
    ~Tool_Button_Pro();

    void setMousePress(bool mouse_press);



protected:

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void painterInfo(int top_color, int middle_color, int bottom_color);

public:

    bool mouse_over; //鼠标是否移过
    bool mouse_press; //鼠标是否按下

};

#endif // TOOL_BUTTON_PRO_H
