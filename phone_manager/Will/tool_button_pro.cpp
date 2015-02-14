#include "tool_button_pro.h"

Tool_Button_Pro::Tool_Button_Pro(QString name,QWidget *parent) :
    QToolButton(parent)
{
    //设置文本颜色
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::ButtonText, QColor(255,255 ,255));
    setPalette(text_palette);

//    //设置文本粗体
//    QFont &text_font = const_cast<QFont &>(font());
//    text_font.setWeight(QFont::Bold);

    setFont(QFont(PURISA,16,40,true));

    setToolButtonStyle(Qt::ToolButtonTextOnly);
    setText(name);


    setAutoRaise(true);
  //  setObjectName("transparentToolButton");

    mouse_over = false;
    mouse_press = false;

}

Tool_Button_Pro::~Tool_Button_Pro()
{

}

void Tool_Button_Pro::enterEvent(QEvent *)
{
    mouse_over = true;
}

void Tool_Button_Pro::leaveEvent(QEvent *)
{
    mouse_over = false;
}

void Tool_Button_Pro::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}

void Tool_Button_Pro::setMousePress(bool mouse_press)
{
    this->mouse_press = mouse_press;
    update();
}

void Tool_Button_Pro::paintEvent(QPaintEvent *event)
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

    QToolButton::paintEvent(event);
}

void Tool_Button_Pro::painterInfo(int top_color, int middle_color, int bottom_color)
{
    QPainter painter(this);
    QPen pen(Qt::NoBrush, 1);
    painter.setPen(pen);
    QLinearGradient linear(rect().topLeft(), rect().bottomLeft());
    linear.setColorAt(0, QColor(0, 0, 0, top_color));
    linear.setColorAt(0.5, QColor(150, 150, 150, middle_color));
    linear.setColorAt(1, QColor(255, 255, 255, bottom_color));
    painter.setBrush(linear);
//    painter.shear(0.5,0);
    painter.drawRoundedRect(rect(),8,8,Qt::AbsoluteSize);
}



