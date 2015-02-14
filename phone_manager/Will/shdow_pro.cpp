#include "shdow_pro.h"
#include "ui_shdow_pro.h"

Shdow_Pro::Shdow_Pro(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    mouse_press = false;
}

Shdow_Pro::~Shdow_Pro()
{
}

void Shdow_Pro::paintEvent(QPaintEvent *)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
//    path.addRect(10, 10, this->width()-20, this->height()-20);
    path.addRoundRect(10,10,this->width()-20,this->height()-20,25);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
//        path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
         path.addRoundRect(10-i,10-i,this->width()-(20-2*i),this->height()-(20-2*i),25-i);
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void Shdow_Pro::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
    }
    move_point = event->globalPos() - pos();
}

void Shdow_Pro::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press == true)
    {
        move(event->globalPos() - move_point);
    }
}

void Shdow_Pro::mouseReleaseEvent(QMouseEvent *)
{
    mouse_press = false;

}
