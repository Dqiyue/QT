#include "right_home_widget.h"

Right_Home_Widget::Right_Home_Widget(QWidget *parent) :
    QWidget(parent)
{
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::ButtonText, QColor(255,140,0 ));
    QPalette palette_lab = palette();
    palette_lab.setColor(QPalette::WindowText, QColor(255,140,0 ));
    help = new QPushButton("帮助");
    contact_us = new QPushButton("联系我们");
    main_label = new QLabel;
    main_layout = new QVBoxLayout();
   main_label->setText("关于软件");
    main_label->setFont(QFont(PURISA,20,60,false));
    main_label->setPalette(palette_lab);

    content_label = new QLabel();
    content_label->setFont(QFont(PURISA,12,40,false));


    //    setStyleSheet("background-color:#27ae67");
    //设置大小
    help->setFont(QFont(PURISA,16,40,false));
    help->setPalette(text_palette);
    help->setFlat(true);
    help->setFixedSize(150,60);
    connect(help,SIGNAL(clicked()),this,SLOT(show_help()));
    connect(contact_us,SIGNAL(clicked()),this,SLOT(contact_us_show()));
    contact_us->setFont(QFont(PURISA,16,40,false));
    contact_us->setPalette(text_palette);
    contact_us->setFlat(true);
    contact_us->setFixedSize(150,60);
    main_layout->addStretch();
    main_layout->addWidget(main_label,0,Qt::AlignHCenter);
    main_layout->addWidget(help,0,Qt::AlignHCenter);
    main_layout->addWidget(contact_us,0,Qt::AlignHCenter);
    main_layout->addWidget(content_label,0,Qt::AlignHCenter);
    main_layout->addStretch();
    setLayout(main_layout);
}


void Right_Home_Widget::show_help()
{
    detact_thread *detact = new detact_thread;
    detact->start();
}

void Right_Home_Widget::contact_us_show()
{
    content_label->setText("如果您有任何使用问题\n 或者任何建议,请联系.\n酷管家团队");
}
void Right_Home_Widget::start_timer(){
//    detact_thread *detact = new detact_thread;
}
