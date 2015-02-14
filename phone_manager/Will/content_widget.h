#ifndef CONTENT_WIDGET_H
#define CONTENT_WIDGET_H
#include "message.h"
#include <QWidget>
#include <QStackedWidget>
#include <QSplitter>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QProcess>
#include <QDebug>
#include "Common.h"
#include "tool_button.h"
#include <QSignalMapper>
#include "contact_widget.h"
#include "phone_music.h"
#include "phone_picture.h"
#include "phone_plus.h"
#include "my_thread.h"
#include "usb_detact_connect.h"
#include "phoneshow.h"
#include "right_home_widget.h"
#include "showall.h"
#include "app_manager.h"
//#include "player.h"

class Content_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Content_Widget(QWidget *parent = 0);


public:
        Phone_Music *phone_music;
        void clearLayout(QLayout *layout);




signals:
   //     void refresh_screen();

    void fresh();

public slots:

    void shot_screen();
    void catch_screen();
    void turnPage(QString current_page);
    void refresh_screen();
    void update_song_number(int song_number);
    void update_picture_number();
    void turnHome();
private slots:

    void pro_fin(int ec);
    void show_recovery();
private:
    void initleft();
    void initright();
    void initmid();
    void setbtntext();


private:
    QPushButton *home;
    QSplitter *main_splitter;
    QWidget *left;
    QWidget *mid;
    QStackedWidget *right;
    QLabel *left_label;
    QLabel *mid_label;
    QLabel *right_label;
    QVBoxLayout *left_layout;
    QVBoxLayout *mid_layout;
    QVBoxLayout *right_layout;
    QPushButton *right_app;
    QProcess *process;
    QProcess *pro1;
    QProcess *pro2;
    QProcess *pro3;
    QProcess *phone_battery_pro;
    QProcess *phone_rom_pro;
    QProcess *sdcard_rom_pro;
    QLabel *phone_battery;
    QLabel *phone_rom;
    QLabel *sdcard_rom;
    int phone_battery_num;
    int sdcard_rom_num;
    double phone_rom_num;
    QProgressBar *sdcard_rom_bar;
    QProgressBar *phone_rom_bar;
    QProgressBar *phone_battery_bar;
    QLabel *phone_info;
    QLabel *result;
    QPushButton *refresh;
    QPushButton *screenshot;
    QPushButton *screen_catch;
    QLabel *screen;
    QList<Tool_Button*> btnlist;
    QStackedWidget *stacked_widget;

    Contact_Widget *contact_widget;
    ShowAll *all;
    Phone_Picture *phone_picture;
    Phone_Plus *phone_plus;
    Phoneshow *phone_show;
    Right_Home_Widget *rightHome;
    Message *message;
//    Player *player;

};

#endif // CONTENT_WIDGET_H
