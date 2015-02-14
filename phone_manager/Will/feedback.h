#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>

class FeedBack : public QWidget
{
    Q_OBJECT
public:
    explicit FeedBack(QWidget *parent = 0);

signals:

public slots:

public:
    void show_widget();

private:
    QLineEdit *edit;
    QVBoxLayout *main_layout;



};

#endif // FEEDBACK_H
