#ifndef TWO_WIDGET_H
#define TWO_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

class Two_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Two_Widget(QWidget *parent = 0);

 private:
    QLabel *two_lab;
    QVBoxLayout *main_layout;

signals:

public slots:

};

#endif // TWO_WIDGET_H
