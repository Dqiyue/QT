#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include "shdow_pro.h"
#include "tittle_widget.h"
#include "content_widget.h"
#include "foot_widget.h"
#include "main_menu.h"
#include <QStackedWidget>
#include <QDesktopWidget>
#include <QDebug>
#include "two_widget.h"
#include "three_widget.h"
#include "feedback.h"
#include <QSystemTrayIcon>
#include <QApplication>
#include <QPropertyAnimation>
#include "showall.h"
#include <QStackedLayout>
#include "file_manager.h"
#include "Common.h"
#include "app_manager.h"

//#include "install.h"




class Main_Widget : public Shdow_Pro
{
    Q_OBJECT
public:
    explicit Main_Widget(QWidget *parent = 0);
    ~Main_Widget();
    bool isRunning();

protected:
   virtual void paintEvent(QPaintEvent *event);

private slots:

    void turnPage(int current_page);
    void change_skin(int current);
    void iconIsActived(QSystemTrayIcon::ActivationReason reason);
    void close_widget();
    void btn_able();

    void real_start_view();
    void fitsize();

public slots:
    void show_widget();
    void show_feedback();
    void show_my_app(bool is_pressed);
    void fresh();


private:

      void start_view();



private:
      App_Manager *app_manager;
      File_Manager *file_manager;
    QMenu *myMenu;
    QSystemTrayIcon *mytrayIcon;
    QStackedWidget *stacked_widget;
    Two_Widget *two_widget;
    Three_Widget *three_widget;
    Tittle_Widget *tittle;
    Content_Widget *content;
    Foot_Widget *foot;
    QAction *restoreWinAction;
    QAction *quitAction;
    Main_Menu *menu;
    FeedBack *feedback;
    ShowAll *all;
    QPropertyAnimation *start_animation;
    QPropertyAnimation *content_animation;
        QStringList skin_list;
    int id;

    bool is_running;

};

#endif // MAIN_WIDGET_H
