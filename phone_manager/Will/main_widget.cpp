#include "main_widget.h"
#include "shdow_pro.h"
#include <QPixmap>
#include <QLayout>
#include <QDesktopWidget>
Main_Widget::Main_Widget(QWidget *parent)
    :Shdow_Pro(parent)
{
//    QDesktopWidget *d=QApplication::desktop();
//     this->setMaximumSize(d->width(),d->height());
//    this->setMinimumSize(900,600);
    id =0 ;
    this->setFixedSize(900,600);
    this->setWindowIcon(QIcon(":/new/prefix1/pro.ico"));
    this->setWindowOpacity(0.9);
    if(!QSystemTrayIcon::isSystemTrayAvailable())
    {
        return;
    }
    skin_list<<"background-color:#fffafa"<<"background-color:#dc143c"<<"background-color:#ff8c00"<<"background-color:#ffd700"<<"background-color:#3cb371"<<"background-color:#483d8b"<<"background-color:#800000"<<"background-color:#4b0082"<<"background-color:#000000";

    mytrayIcon = new QSystemTrayIcon(this);
    stacked_widget = new QStackedWidget();
//    install_widget = new Install();
    all = new ShowAll();
    menu = new Main_Menu();
//    app_manager = new App_Manager();
    tittle = new Tittle_Widget();
    content = new Content_Widget();
    foot = new Foot_Widget();
//    start = new Start_Widget();
    two_widget = new Two_Widget();
    three_widget = new Three_Widget();

    file_manager = new File_Manager();
    content_animation = new QPropertyAnimation(content,"geometry");
    start_animation = new QPropertyAnimation(foot,"geometry");

    feedback = new FeedBack();

    mytrayIcon->setIcon(QIcon(":/new/prefix1/pro.ico"));
    mytrayIcon->setToolTip("We will be the god to shine the night");
    mytrayIcon->showMessage("Tray","Tray Manager",QSystemTrayIcon::Information,10000);
    mytrayIcon->setContextMenu(menu);

    /***************put on starting point************************/
      app_manager = new App_Manager();
//    app_manager->process_excution();
//    detact_thread *detact = new detact_thread;
//    detact->start();


    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(Qt::white));
    stacked_widget->setPalette(palette);
    stacked_widget->setAutoFillBackground(true);

    stacked_widget->addWidget(content);
    stacked_widget->addWidget(app_manager);
    stacked_widget->addWidget(three_widget);
    stacked_widget->addWidget(file_manager);
 //   stacked_widget->addWidget(start);

    stacked_widget->setFixedSize(900,450);


    QHBoxLayout *center_layout = new QHBoxLayout();
    center_layout->addWidget(stacked_widget);
    center_layout->setSpacing(0);
    center_layout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(tittle);
    main_layout->addLayout(center_layout);
    main_layout->addWidget(foot);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);
 //   stacked_widget->setCurrentWidget(start);
//    tittle->setStyleSheet("background:transparent");
//    foot->setStyleSheet("background:transparent");






    connect(tittle,SIGNAL(show_close()),this,SLOT(close_widget()));
    connect(tittle,SIGNAL(show_min()),this,SLOT(showMinimized()));
    // connect(tittle,SIGNAL(show_max()),this,SLOT(showFullScreen()));
    connect(tittle,SIGNAL(showMax()),this,SLOT(showMaximized()));
    connect(tittle,SIGNAL(showNor()),this,SLOT(showNormal()));
    connect(tittle,SIGNAL(turnPage(int)),this,SLOT(turnPage(int)));
    connect(tittle,SIGNAL(change_skin(int)),this,SLOT(change_skin(int)));
    connect(mytrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
    connect(menu, SIGNAL(show_widget()), this, SLOT(show_widget()));
    connect(menu,SIGNAL(hide_widget()),this,SLOT(hide()));
    connect(menu,SIGNAL(show_min()),this,SLOT(showMinimized()));
    connect(menu,SIGNAL(close_widget()),this,SLOT(close_widget()));
//    connect(start,SIGNAL(main_start()),this,SLOT(real_start_view()));
    connect(foot,SIGNAL(show_app(bool)),this,SLOT(show_my_app(bool)));
//    connect(foot->my_app_btn,SIGNAL(clicked()),content->phone_music,SLOT(pause_the_music_play()));

//    connect(content,SIGNAL(refresh_screen()),this,SLOT(show_widget()));
//    connect(this,SIGNAL(f))


    mytrayIcon->show();

    setLayout(main_layout);
    this->is_running = true;







}

Main_Widget::~Main_Widget()
{
}

void Main_Widget::turnPage(int current_page)
{
    if(current_page == 0)
    {
        stacked_widget->setCurrentWidget(content);
    }
    else if(current_page == 1)
    {
        qDebug() << "kkkk";
        id++;
        if(id > 1){
            app_manager->start();
     }

        stacked_widget->setCurrentWidget(app_manager);
    }
    else if(current_page == 2)
    {
        qDebug() << "three";
        stacked_widget->setCurrentWidget(three_widget);
    }
    else if(current_page == 3)
    {
        stacked_widget->setCurrentWidget(file_manager);
    }
}

bool Main_Widget::isRunning()
{
    return is_running;
}


void Main_Widget::change_skin(int current)
{
    foot->back_label->setStyleSheet(skin_list.at(current));
}



void Main_Widget::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        //点击托盘图标之后松开
    case QSystemTrayIcon::Trigger:
        {
            show_widget();

            break;
        }
        //双击托盘图标
    case QSystemTrayIcon::DoubleClick:
        {
            //show_widget();
        showNormal();

            break;
        }
    default:
        break;
    }
}


void Main_Widget::paintEvent(QPaintEvent *event)
{
    Shdow_Pro::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
//    painter.drawRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH));
    painter.drawRoundedRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH),25,25,Qt::AbsoluteSize);


}



void Main_Widget::show_widget()
{
    this->start_view();
//    if(this->isRunning() == false)
//    {
//        this->start_view();
//    }
    this->showNormal();
    this->raise();
    this->activateWindow();
}


void Main_Widget::show_feedback()
{
    feedback = new FeedBack();
    feedback->show_widget();
}


  //点击最小化按钮隐藏界面
void QWidget::changeEvent(QEvent *e)
{
if((e->type()==QEvent::WindowStateChange)&&this->isMinimized())
{
 //    QTimer::singleShot(100, this, SLOT(hide()));
    this->hide();
}
}


void Main_Widget::start_view()
{
//    content_animation = new QPropertyAnimation(content,"geometry");
//    start_animation = new QPropertyAnimation(foot,"geometry");
//    txt_animation = new QPropertyAnimation();
//      content_animation->setDuration(3000);
//      content_animation->setStartValue(QRect(SHADOW_WIDTH,SHADOW_WIDTH,900-2*SHADOW_WIDTH,0));
  //    content_animation->setKeyValueAt(0.5,QRect(SHADOW_WIDTH,SHADOW_WIDTH,900-2*SHADOW_WIDTH,600-2*SHADOW_WIDTH));
//      content_animation->setEndValue(QRect(SHADOW_WIDTH,tittle->height()+SHADOW_WIDTH,900-2*SHADOW_WIDTH,410));
//      content_animation->setEasingCurve(QEasingCurve::OutBack);

 //      foot->setMaximumSize(900,600);
//      content_animation->start();

//      start_animation->setDuration(3000);
//      start_animation->setStartValue(QRect(0,535,900,70));
//      start_animation->setEndValue(QRect(0,0,900,600));
//      start_animation->setEasingCurve(QEasingCurve::OutBack);
//      start_animation->start();
}

void Main_Widget::real_start_view()
{
//    start_animation = new QPropertyAnimation(foot,"geometry");
 //   txt_animation = new QPropertyAnimation()


     content_animation->setDuration(3000);
     content_animation->setStartValue(QRect(0,600,900,0));
     content_animation->setEndValue(QRect(0,0,900,600));
     content_animation->setEasingCurve(QEasingCurve::OutBack);
     content_animation->start();

//    start_animation->setDuration(3000);
//    start_animation->setStartValue(QRect(0,0,900,600));
//    start_animation->setEndValue(QRect(0,535,900,70));
//    start_animation->setEasingCurve(QEasingCurve::OutBack);
//    start_animation->start();


    connect(content_animation,SIGNAL(finished()),this,SLOT(fitsize()));
}

void Main_Widget::close_widget()
{
    this->close();

}

void Main_Widget::fitsize()
{
 //    foot = new Start_Widget();
    this->turnPage(0);
}

void Main_Widget::btn_able()
{
    foot->my_app_btn->setDisabled(false);

    QPalette button_text_palette = palette();
     button_text_palette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
     foot->my_app_btn->setPalette(button_text_palette);
//    if(foot->btn_pressed){
//            foot->setFixedHeight(this->height()-2*SHADOW_WIDTH-2*tittle->height());

//    }

}

void Main_Widget::show_my_app(bool is_pressed)
{

     //   txt_animation = new QPropertyAnimation()

        QPalette button_text_palette = palette();
         button_text_palette.setColor(QPalette::ButtonText, QColor(0, 0, 0));
         start_animation->setDuration(3000);
         if(is_pressed == false){
                content->phone_music->pause_the_music_play();
                start_animation->setStartValue(QRect(SHADOW_WIDTH,SHADOW_WIDTH+tittle->height()+stacked_widget->height(),this->width(),this->height()-2*SHADOW_WIDTH-tittle->height()-stacked_widget->height()));
//                start_animation->setEndValue(QRect(SHADOW_WIDTH,SHADOW_WIDTH+tittle->height()*2,foot->width(),600-SHADOW_WIDTH*2-2*tittle->height()));
                start_animation->setEndValue(QRect(SHADOW_WIDTH,SHADOW_WIDTH+2*tittle->height(),this->width(),this->height()-SHADOW_WIDTH*2-2*tittle->height()));

         }
         else{
              start_animation->setStartValue(QRect(SHADOW_WIDTH,SHADOW_WIDTH+2*tittle->height(),this->width(),this->height()-SHADOW_WIDTH*2-2*tittle->height()));
//                start_animation->setStartValue(QRect(SHADOW_WIDTH,SHADOW_WIDTH+tittle->height()*2,foot->width(),600-SHADOW_WIDTH*2-2*tittle->height()));
                start_animation->setEndValue(QRect(SHADOW_WIDTH,SHADOW_WIDTH+tittle->height()+stacked_widget->height(),this->width(),this->height()-tittle->height()-stacked_widget->height()));

         }
         start_animation->setEasingCurve(QEasingCurve::OutBack);
         start_animation->start();
         foot->my_app_btn->setDisabled(true);
         foot->my_app_btn->setPalette(button_text_palette);
         connect(start_animation,SIGNAL(finished()),this,SLOT(btn_able()));

}


void Main_Widget::fresh()
{

}


