#ifndef MY_APP_WIDGET_H
#define MY_APP_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

class My_App_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit My_App_Widget(QWidget *parent = 0);

signals:

public slots:

public:
    QGridLayout *main_layout;
    QLabel *label;


};

#endif // MY_APP_WIDGET_H
