#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QLabel>
#include <QMouseEvent>
class My_Label : public QLabel
{
    Q_OBJECT
public:
    explicit My_Label(QWidget *parent = 0);
    void judge_img();
signals:

public slots:

protected:
    virtual void mouseReleaseEvent(QMouseEvent * ev);
  virtual void mouseDoubleClickEvent(QMouseEvent *mouseEvent);
signals:
    void clicked();
    void show_clicked();
    void judge(QString);

};

#endif // MY_LABEL_H




