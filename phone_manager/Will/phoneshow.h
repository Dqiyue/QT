#ifndef PHONESHOW_H
#define PHONESHOW_H

#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include<QVBoxLayout>
#include<QProcess>
#include<QPixmap>
#include <QThread>
#include <QMouseEvent>
#include <QPaintEvent>
#include<QTimer>
#include <QPoint>
#include "th.h"
#include "my_label.h"
class My_Label;

namespace Ui {
class Phoneshow;
}

class Phoneshow : public QWidget
{
    Q_OBJECT

public:
    explicit Phoneshow(QWidget *parent = 0);
    ~Phoneshow();
    void showimg();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void phoneshow();
    void showexit();
signals:
   void exitT(void);
   void phone_exit();
public:
    QLabel    *phoneimg;
      QPoint m_DragPosition;
    QProcess *pro;
    QTimer *testTimer;
    My_Label *img;
};

#endif // PHONESHOW_H
