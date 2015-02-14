#ifndef TOOL_BUTTON_H
#define TOOL_BUTTON_H


#include <QToolButton>
#include <QMouseEvent>
#include <QPainter>

class Tool_Button : public QToolButton
{

public:
    explicit Tool_Button(QString pic_name, QWidget *parent = 0);
    ~Tool_Button();

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

signals:

public slots:

};

#endif // TOOL_BUTTON_H
