#ifndef RIGHT_HOME_WIDGET_H
#define RIGHT_HOME_WIDGET_H
#include <usb_detact_connect.h>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include "Common.h"

class Right_Home_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Right_Home_Widget(QWidget *parent = 0);

signals:

public slots:
    void contact_us_show();
    void show_help();
    void start_timer();

private:
    QLabel *main_label;
    QVBoxLayout *main_layout;
    QPushButton *help;
    QPushButton *contact_us;
    QLabel *content_label;

};

#endif // RIGHT_HOME_WIDGET_H
