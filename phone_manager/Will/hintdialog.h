#ifndef HINTDIALOG_H
#define HINTDIALOG_H
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QStackedWidget>


class hintDialog : public QDialog
{
    Q_OBJECT

public:
    explicit hintDialog(QWidget *parent = 0);
    ~hintDialog();
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent*);
    int flag;
    void change_state();
signals:
    void changeTimer();

private:

    QPushButton *close_btn;
    QPoint m_DragPosition;
    QPushButton *back_btn;
    QPushButton *forward_btn;
    QPushButton *reconnect;
    QLabel *label;
    QWidget *label1;
    QLabel *label2;
    QLabel *content1;
    QLabel *content2;
    QLabel *content3;
    QStackedWidget *stack;
 private slots:
    void turnpage();
    void turn_trying_page();
};

#endif // HINTDIALOG_H
