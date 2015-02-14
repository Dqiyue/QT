#ifndef PHONE_PICTURE_H
#define PHONE_PICTURE_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

class Phone_Picture : public QWidget
{
    Q_OBJECT
public:
    explicit Phone_Picture(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *main_label;
    QVBoxLayout *main_layout;

};

#endif // PHONE_PICTURE_H




