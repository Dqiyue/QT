#ifndef PHONE_PLUS_H
#define PHONE_PLUS_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

class Phone_Plus : public QWidget
{
    Q_OBJECT
public:
    explicit Phone_Plus(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *main_label;
    QVBoxLayout *main_layout;

};

#endif // PHONE_PLUS_H