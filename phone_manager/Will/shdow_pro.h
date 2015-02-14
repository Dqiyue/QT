#ifndef SHDOW_PRO_H
#define SHDOW_PRO_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>



class Shdow_Pro : public QDialog
{
    Q_OBJECT

public:
    explicit Shdow_Pro(QWidget *parent = 0);
    ~Shdow_Pro();


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);


private:
    QPoint move_point; //移动的距离
    bool mouse_press; //按下鼠标左键
};

#endif // SHDOW_PRO_H
