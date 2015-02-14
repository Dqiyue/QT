#include "simple_button.h"

Simple_Button::Simple_Button(QWidget *parent) :
    QPushButton(parent)
{
    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(0,100,0));
    setPalette(button_text_palette);

//    setText(button_txt);
    setFlat(true);
    setFont(QFont(URW_P_FONT,10,QFont::Bold,true));

    mouse_over = false;
    mouse_press = false;
//    setFixedSize(300,50);

}

Simple_Button::~Simple_Button()
{
}

void Simple_Button::enterEvent(QEvent *)
{
    mouse_over = true;
}

void Simple_Button::leaveEvent(QEvent *)
{
    mouse_over = false;
}

void Simple_Button::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}

void Simple_Button::setMousePress(bool mouse_press)
{
    this->mouse_press = mouse_press;
    update();
}

void Simple_Button::paintEvent(QPaintEvent *event)
{
    if(mouse_over)
    {
        //绘制鼠标移到按钮上的按钮效果
        painterInfo(0, 100, 150);
    }
    else
    {
        if(mouse_press)
        {
            painterInfo(0, 100, 150);
        }
    }

    Simple_Button::paintEvent(event);
}

void Simple_Button::painterInfo(int top_color, int middle_color, int bottom_color)
{
    QPainter painter(this);
    QPen pen(Qt::NoBrush, 1);
    painter.setPen(pen);
    QLinearGradient linear(rect().topLeft(), rect().bottomLeft());
    linear.setColorAt(0, QColor(230, 230, 230, top_color));
    linear.setColorAt(0.5, QColor(100, 100, 100, middle_color));
    linear.setColorAt(1, QColor(0, 0, 0, bottom_color));
    painter.setBrush(linear);
    painter.drawRect(rect());
}

