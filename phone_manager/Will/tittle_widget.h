#ifndef TITTLE_WIDGET_H
#define TITTLE_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include "tool_button_pro.h"
#include "Common.h"
#include <QSignalMapper>
#include <QDebug>
#include <QGraphicsOpacityEffect>


class Tittle_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Tittle_Widget(QWidget *parent = 0);
    ~Tittle_Widget();

signals:
    void show_close();
    void show_min();
  //  void show_max();
    void showMax();
    void showNor();
    void change_skin(int current);
    void turnPage(int current_page);

private:
    void setbtntxt();

private:
    QPoint press_point;//鼠标按下去的点
    bool is_move;
    QPushButton *btclose;
    QPushButton *btmin;
    QPushButton *btskin;
    QPushButton *btmax;
    QLabel *top_label;
    QLabel *top_label_pre;

    void mouseDoubleClickEvent(QMouseEvent *);
    QLabel *version;
    QLabel *logo;
    QLabel *product_name;
    QList<Tool_Button_Pro*> btnlist;
    QStringList skin_list;
    int current_skin;
    int id;
public slots:
    void turnPage(QString current_page);
    void change_skin();
};

#endif // TITTLE_WIDGET_H
