#include "three_widget.h"
#include<QDebug>
#include <thread.h>
#include <QPalette>
#include <QColor>
Three_Widget::Three_Widget(QWidget *parent) :
    QWidget(parent)
{
    QPalette button_text_palette;
    button_text_palette.setColor(QPalette::ButtonText,QColor(220,20,60));
    //初始化控件
    //游戏
    //game
    game = new QLabel;
    game0_imga = new QLabel;
    game0_name= new QLabel;
    game0_introduce = new QLabel;
    game0_pb = new QProgressBar;
    stop0_button      = new QPushButton;
    game0_button   = new QPushButton;
    game0_installbutton   = new QPushButton(tr("安装"));

    //game1
    game1_imga   =new QLabel;
    game1_name=new QLabel;
    game1_num =new QLabel;
    game1_size   =new QLabel;
    game1_introduce =new QLabel;
    game1_pb = new QProgressBar;
    stop1_button      = new QPushButton;
    game1_button= new QPushButton;
    game1_installbutton   = new QPushButton(tr("安装"));

    //game2
    game2_imga   =new QLabel;
    game2_name=new QLabel;
    game2_num =new QLabel;
    game2_size   =new QLabel;
    game2_introduce =new QLabel;
    game2_pb = new QProgressBar;
    stop2_button      = new QPushButton;
    game2_button= new QPushButton;
    game2_installbutton   = new QPushButton(tr("安装"));

    //game3
    game3_imga   =new QLabel;
    game3_name=new QLabel;
    game3_num =new QLabel;
    game3_size   =new QLabel;
    game3_introduce =new QLabel;
    game3_pb = new QProgressBar;
    stop3_button      = new QPushButton;
    game3_button= new QPushButton;
    game3_installbutton   = new QPushButton(tr("安装"));

    //game4
    game4_imga   =new QLabel;
    game4_name=new QLabel;
    game4_num =new QLabel;
    game4_size   =new QLabel;
    game4_introduce =new QLabel;
    game4_pb = new QProgressBar;
    stop4_button      = new QPushButton;
    game4_button= new QPushButton;
    game4_installbutton   = new QPushButton(tr("安装"));

    //软件
    //software
    software  = new QLabel;
    software0_imga = new QLabel;
    software0_name= new QLabel;
    software0_introduce = new QLabel;
    software0_pb = new QProgressBar;
    button_stop0      = new QPushButton;
    software0_button= new QPushButton;
    software0_installbutton   = new QPushButton(tr("安装"));

    //software1
    software1_imga =new QLabel;
    software1_name=new QLabel;
    software1_num  =new QLabel;
    software1_size   =new QLabel;
    software1_introduce=new QLabel;
    software1_pb = new QProgressBar;
    button_stop1      = new QPushButton;
    software1_button= new QPushButton;
    software1_installbutton   = new QPushButton(tr("安装"));

    //software2
    software2_imga =new QLabel;
    software2_name=new QLabel;
    software2_num  =new QLabel;
    software2_size   =new QLabel;
    software2_introduce=new QLabel;
    software2_pb = new QProgressBar;
    button_stop2      = new QPushButton;
    software2_button= new QPushButton;
    software2_installbutton   = new QPushButton(tr("安装"));

    //software3
    software3_imga =new QLabel;
    software3_name=new QLabel;
    software3_num  =new QLabel;
    software3_size   =new QLabel;
    software3_introduce=new QLabel;
    software3_pb = new QProgressBar;
    button_stop3      = new QPushButton;
    software3_button= new QPushButton;
    software3_installbutton   = new QPushButton(tr("安装"));

    //software4
    software4_imga =new QLabel;
    software4_name=new QLabel;
    software4_num  =new QLabel;
    software4_size   =new QLabel;
    software4_introduce=new QLabel;
    software4_pb = new QProgressBar;
    button_stop4      = new QPushButton;
    software4_button= new QPushButton;
    software4_installbutton   = new QPushButton(tr("安装"));
    game0_installbutton->setPalette(button_text_palette);
    game1_installbutton->setPalette(button_text_palette);
    game2_installbutton->setPalette(button_text_palette);
    game3_installbutton->setPalette(button_text_palette);
    game4_installbutton->setPalette(button_text_palette);
    game0_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    game1_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    game2_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    game3_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    game4_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    software0_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    software1_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    software2_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    software3_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    software4_installbutton->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
    software0_installbutton->setPalette(button_text_palette);
    software1_installbutton->setPalette(button_text_palette);
    software2_installbutton->setPalette(button_text_palette);
    software3_installbutton->setPalette(button_text_palette);
    software4_installbutton->setPalette(button_text_palette);
    //控件值设置
    //游戏
    //game
    game->setText(tr("<h4><font color = gray>游戏</font></h4>"));
    game0_name->setText(tr("<h5><font color = gray>天下HD</font></h5>"));
    game0_introduce->setText(tr("<h5><font color = gray>网易最受期待的动作手游大作</font></h5>"));
    game0_introduce->setFixedWidth(280);
    QPixmap mypixmap;
    mypixmap.load(":/game/天下HD.png");
    game0_imga->setScaledContents(true);
    game0_imga->setPixmap(mypixmap);
    game0_imga->setFixedSize(350,160);
    game0_button->setFixedSize(60,30);
    game0_installbutton->setFixedSize(60,30);
    stop0_button->setFixedSize(60,30);
    game0_button->setDefault(true);
    game0_installbutton->setDefault(true);
    stop0_button->setDefault(true);
    QPixmap mygame0;
    mygame0.load(":/button/stop.png");
    mygame0.scaled(mygame0.width(),mygame0.height());
    stop0_button->setIcon(mygame0);
    stop0_button->setIconSize(QSize(mygame0.width(),mygame0.height()));
    game0_pb->setAlignment(Qt::AlignCenter);
    game0_pb->setRange(0,100);
    game0_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //game1
    game1_count = 0;
    game1_name->setText(tr("<h4><font color = gray>水果忍者</font></h4>"));
    game1_introduce->setText(tr("<h4><font color = gray>人人都爱切水果!国民级休闲手游</font></h4>"));
    game1_num->setText(""+QString::number(game1_count,10)+"");
    game1_size->setText(tr("次安装 28.5M"));
    QPixmap mypixmap2_1;
    mypixmap2_1.load(":/game/水果忍者.png");
    game1_imga->setScaledContents(true);
    game1_imga->setPixmap(mypixmap2_1);
    game1_imga->setFixedSize(50,50);
    game1_button->setFixedSize(60,30);
    game1_installbutton->setFixedSize(60,30);
    game1_button->setDefault(true);
    game1_installbutton->setDefault(true);
    stop1_button->setDefault(true);
    stop1_button->setIcon(mygame0);
    stop1_button->setIconSize(QSize(mygame0.width(),mygame0.height()));
    stop1_button->setFixedSize(60,30);
    game1_pb->setAlignment(Qt::AlignCenter);
    game1_pb->setRange(0,100);
    game1_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //game2
    game2_count = 0;
    game2_name->setText(tr("<h4><font color = gray>刀塔传奇</font></h4>"));
    game2_introduce->setText(tr("<h4><font color = gray>2014年度首款动作卡牌游戏</font></h4>"));
    game2_num->setText(""+QString::number(game2_count,10)+"");
    game2_size->setText(tr("次安装 98.6M"));
    QPixmap mypixmap2_2;
    mypixmap2_2.load(":/game/刀塔传奇.png");
    game2_imga->setScaledContents(true);
    game2_imga->setPixmap(mypixmap2_2);
    game2_imga->setFixedSize(50,50);
    game2_button->setFixedSize(60,30);
    game2_installbutton->setFixedSize(60,30);
    game2_button->setDefault(true);
    game2_installbutton->setDefault(true);
    stop2_button->setDefault(true);
    stop2_button->setIcon(mygame0);
    stop2_button->setIconSize(QSize(mygame0.width(),mygame0.height()));
    stop2_button->setFixedSize(60,30);
    game2_pb->setAlignment(Qt::AlignCenter);
    game2_pb->setRange(0,100);
    game2_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //game3
    game3_count = 0;
    game3_name->setText(tr("<h4><font color = gray>迷你西游</font></h4>"));
    game3_introduce->setText(tr("<h4><font color = gray>一款神话题材、清新Q版的手机网游</font></h4>"));
    game3_num->setText(""+QString::number(game3_count,10)+"");
    game3_size->setText(tr("次安装 91.5M"));
    QPixmap mypixmap2_3;
    mypixmap2_3.load(":/game/迷你西游.png");
    game3_imga->setScaledContents(true);
    game3_imga->setPixmap(mypixmap2_3);
    game3_imga->setFixedSize(50,50);
    game3_button->setFixedSize(60,30);
    game3_installbutton->setFixedSize(60,30);
    game3_button->setDefault(true);
    game3_installbutton->setDefault(true);
    stop3_button->setDefault(true);
    stop3_button->setIcon(mygame0);
    stop3_button->setIconSize(QSize(mygame0.width(),mygame0.height()));
    stop3_button->setFixedSize(60,30);
    game3_pb->setAlignment(Qt::AlignCenter);
    game3_pb->setRange(0,100);
    game3_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //game4
    game4_count = 0;
    game4_name->setText(tr("<h4><font color = gray>去吧皮丘</font></h4>"));
    game4_introduce->setText(tr("<h4><font color = gray>一款卡牌对战游戏</font></h4>"));
    game4_num->setText(""+QString::number(game4_count,10)+"");
    game4_size->setText(tr("次安装 63.2M"));
    QPixmap mypixmap2_4;
    mypixmap2_4.load(":/game/去吧皮卡丘.png");
    game4_imga->setScaledContents(true);
    game4_imga->setPixmap(mypixmap2_4);
    game4_imga->setFixedSize(50,50);
    game4_button->setFixedSize(60,30);
    game4_installbutton->setFixedSize(60,30);
    game4_button->setDefault(true);
    game4_installbutton->setDefault(true);
    stop4_button->setDefault(true);
    stop4_button->setIcon(mygame0);
    stop4_button->setIconSize(QSize(mygame0.width(),mygame0.height()));
    stop4_button->setFixedSize(60,30);
    game4_pb->setAlignment(Qt::AlignCenter);
    game4_pb->setRange(0,100);
    game4_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //软件
    //software
    software->setText(tr("<h4><font color = gray>软件</font></h4>"));
    software0_name->setText(tr("<h5><font color = gray>点心省电</font></h5>"));
    software0_introduce->setText(tr("<h5><font color = gray>省电只为延续您手机的精彩</font></h5>"));
    software0_introduce->setFixedWidth(280);
    QPixmap mypixmap1;
    mypixmap1.load(":/software/点心省电.png");
    software0_imga->setFixedSize(350,160);
    software0_imga->setScaledContents(true);
    software0_imga->setPixmap(mypixmap1);
    software0_button->setFixedSize(60,30);
    software0_installbutton->setFixedSize(60,30);
    software0_button->setDefault(true);
    software0_installbutton->setDefault(true);
    button_stop0->setDefault(true);
    button_stop0->setIcon(mygame0);
    button_stop0->setIconSize(QSize(mygame0.width(),mygame0.height()));
    button_stop0->setFixedSize(60,30);
    software0_pb->setAlignment(Qt::AlignCenter);
    software0_pb->setRange(0,100);
    software0_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //software1
    software1_count = 0 ;
    software1_name->setText(tr("<h4><font color = gray>手机百度</font></h4>"));
    software1_introduce->setText(tr("<h4><font color = gray>超快的手机搜索利器</font></h4>"));
    software1_num->setText(""+QString::number(software1_count,10)+"");
    software1_size->setText(tr("次安装 19.8M"));
    QPixmap mypixmap1_1;
    mypixmap1_1.load(":/software/手机百度.png");
    software1_imga->setScaledContents(true);
    software1_imga->setPixmap(mypixmap1_1);
    software1_imga->setFixedSize(50,50);
    software1_button->setFixedSize(60,30);
    software1_installbutton->setFixedSize(60,30);
    software1_button->setDefault(true);
    software1_installbutton->setDefault(true);
    button_stop1->setDefault(true);
    button_stop1->setIcon(mygame0);
    button_stop1->setIconSize(QSize(mygame0.width(),mygame0.height()));
    button_stop1->setFixedSize(60,30);
    software1_pb->setAlignment(Qt::AlignCenter);
    software1_pb->setRange(0,100);
    software1_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //software2
    software2_count = 0 ;
    software2_name->setText(tr("<h4><font color = gray>手机淘宝</font></h4>"));
    software2_introduce->setText(tr("<h4><font color = gray>百度专享精选商品，全网最低价!</font></h4>"));
    software2_num->setText(""+QString::number(software2_count,10)+"");
    software2_size->setText(tr("次安装 28.0M"));
    QPixmap mypixmap1_2;
    mypixmap1_2.load(":/software/淘宝.png");
    software2_imga->setScaledContents(true);
    software2_imga->setPixmap(mypixmap1_2);
    software2_imga->setFixedSize(50,50);
    software2_button->setFixedSize(60,30);
    software2_installbutton->setFixedSize(60,30);
    software2_button->setDefault(true);
    software2_installbutton->setDefault(true);
    button_stop2->setDefault(true);
    button_stop2->setIcon(mygame0);
    button_stop2->setIconSize(QSize(mygame0.width(),mygame0.height()));
    button_stop2->setFixedSize(60,30);
    software2_pb->setAlignment(Qt::AlignCenter);
    software2_pb->setRange(0,100);
    software2_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //software3
    software3_count = 0 ;
    software3_name->setText(tr("<h4><font color = gray>腾讯视频</font></h4>"));
    software3_introduce->setText(tr("<h4><font color = gray>网络视频播放客户端</font></h4>"));
    software3_num->setText(""+QString::number(software3_count,10)+"");
    software3_size->setText(tr("次安装 17.8M"));
    QPixmap mypixmap1_3;
    mypixmap1_3.load(":/software/腾讯视频.png");
    software3_imga->setScaledContents(true);
    software3_imga->setPixmap(mypixmap1_3);
    software3_imga->setFixedSize(50,50);
    software3_button->setFixedSize(60,30);
    software3_installbutton->setFixedSize(60,30);
    software3_button->setDefault(true);
    software3_installbutton->setDefault(true);
    button_stop3->setDefault(true);
    button_stop3->setIcon(mygame0);
    button_stop3->setIconSize(QSize(mygame0.width(),mygame0.height()));
    button_stop3->setFixedSize(60,30);
    software3_pb->setAlignment(Qt::AlignCenter);
    software3_pb->setRange(0,100);
    software3_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //software4
    software4_count = 0 ;
    software4_name->setText(tr("<h4><font color = gray>手机优酷</font></h4>"));
    software4_introduce->setText(tr("<h4><font color = gray>精彩视频360度全方位一手掌握!</font></h4>"));
    software4_num->setText(""+QString::number(software4_count,10)+"");
    software4_size->setText(tr("次安装 21.4M"));
    QPixmap mypixmap1_4;
    mypixmap1_4.load(":/software/优酷.png");
    software4_imga->setScaledContents(true);
    software4_imga->setPixmap(mypixmap1_4);
    software4_imga->setFixedSize(50,50);
    software4_button->setFixedSize(60,30);
    software4_installbutton->setFixedSize(60,30);
    software4_button->setDefault(true);
    software4_installbutton->setDefault(true);
    button_stop4->setDefault(true);
    button_stop4->setIcon(mygame0);
    button_stop4->setIconSize(QSize(mygame0.width(),mygame0.height()));
    button_stop4->setFixedSize(60,30);
    software4_pb->setAlignment(Qt::AlignCenter);
    software4_pb->setRange(0,100);
    software4_pb->setStyleSheet("QProgressBar::chunk { background-color: rgb(169,169,169) }");

    //控件布局
    //游戏
    //game
    QVBoxLayout *qv1 = new QVBoxLayout;
    qv1->addWidget(game0_name);
    qv1->addWidget(game0_introduce);
    qv1->addStretch();
    qs0 =  new QStackedLayout;
    qs0->addWidget(game0_installbutton);
    qs0->addWidget(game0_button);
    qs0->addWidget(stop0_button);
    qs0->setCurrentIndex(0);
    QHBoxLayout *qh1 = new QHBoxLayout;
    qh1->addLayout(qv1);
    qh1->addLayout(qs0);
    QVBoxLayout *qv2 = new QVBoxLayout;
    qv2->addWidget(game0_imga);
    qv2->addLayout(qh1);
    qv2->addStretch();

    //game1
    QHBoxLayout *qh1_1 = new QHBoxLayout;
    qh1_1->addWidget(game1_num);
    qh1_1->addWidget(game1_size);
//    qh1_1->addStretch();
    QVBoxLayout *qv1_1 = new QVBoxLayout;
    qv1_1->addWidget(game1_name);
    qv1_1->addLayout(qh1_1);
//    qv1_1->addStretch();
    qs1 =  new QStackedLayout;
    qs1->addWidget(game1_installbutton);
    qs1->addWidget(game1_button);
    qs1->addWidget(stop1_button);
    qs1->setCurrentIndex(0);
    QHBoxLayout *qh1_1_1 = new QHBoxLayout;
    qh1_1_1->addWidget(game1_imga);
    qh1_1_1->addLayout(qv1_1);
    qh1_1_1->addLayout(qs1);
//    qh1_1_1->addStretch();
    QVBoxLayout *qv2_1 = new QVBoxLayout;
    qv2_1->addLayout(qh1_1_1);
    qv2_1->addWidget(game1_introduce);
    qv2_1->addStretch();

    //game2
    QHBoxLayout *qh1_2 = new QHBoxLayout;
    qh1_2->addWidget(game2_num);
    qh1_2->addWidget(game2_size);
//    qh1_2->addStretch();
    QVBoxLayout *qv1_2 = new QVBoxLayout;
    qv1_2->addWidget(game2_name);
    qv1_2->addLayout(qh1_2);
//    qv1_2->addStretch();
    qs2 =  new QStackedLayout;
    qs2->addWidget(game2_installbutton);
    qs2->addWidget(game2_button);
    qs2->addWidget(stop2_button);
    qs2->setCurrentIndex(0);
    QHBoxLayout *qh1_1_2 = new QHBoxLayout;
    qh1_1_2->addWidget(game2_imga);
    qh1_1_2->addLayout(qv1_2);
    qh1_1_2->addLayout(qs2);
//    qh1_1_2->addStretch();
    QVBoxLayout *qv2_2 = new QVBoxLayout;
    qv2_2->addLayout(qh1_1_2);
    qv2_2->addWidget(game2_introduce);
    qv2_2->addStretch();

    //game3
    QHBoxLayout *qh1_3 = new QHBoxLayout;
    qh1_3->addWidget(game3_num);
    qh1_3->addWidget(game3_size);
//    qh1_3->addStretch();
    QVBoxLayout *qv1_3= new QVBoxLayout;
    qv1_3->addWidget(game3_name);
    qv1_3->addLayout(qh1_3);
//    qv1_3->addStretch();
    qs3 =  new QStackedLayout;
    qs3->addWidget(game3_installbutton);
    qs3->addWidget(game3_button);
    qs3->addWidget(stop3_button);
    qs3->setCurrentIndex(0);
    QHBoxLayout *qh1_1_3 = new QHBoxLayout;
    qh1_1_3->addWidget(game3_imga);
    qh1_1_3->addLayout(qv1_3);
    qh1_1_3->addLayout(qs3);
//    qh1_1_3->addStretch();
    QVBoxLayout *qv2_3 = new QVBoxLayout;
    qv2_3->addLayout(qh1_1_3);
    qv2_3->addWidget(game3_introduce);
    qv2_3->addStretch();

    //game4
    QHBoxLayout *qh1_4 = new QHBoxLayout;
    qh1_4->addWidget(game4_num);
    qh1_4->addWidget(game4_size);
//    qh1_4->addStretch();
    QVBoxLayout *qv1_4 = new QVBoxLayout;
    qv1_4->addWidget(game4_name);
    qv1_4->addLayout(qh1_4);
//    qv1_4->addStretch();
    qs4 =  new QStackedLayout;
    qs4->addWidget(game4_installbutton);
    qs4->addWidget(game4_button);
    qs4->addWidget(stop4_button);
    qs4->setCurrentIndex(0);
    QHBoxLayout *qh1_1_4 = new QHBoxLayout;
    qh1_1_4->addWidget(game4_imga);
    qh1_1_4->addLayout(qv1_4);
    qh1_1_4->addLayout(qs4);
//    qh1_1_4->addStretch();
    QVBoxLayout *qv2_4 = new QVBoxLayout;
    qv2_4->addLayout(qh1_1_4);
    qv2_4->addWidget(game4_introduce);
    qv2_4->addStretch();

    //软件
    //software
    QVBoxLayout *qv3= new QVBoxLayout;
    qv3->addWidget(software0_name);
    qv3->addWidget(software0_introduce);
    qs_0 =  new QStackedLayout;
    qs_0->addWidget(software0_installbutton);
    qs_0->addWidget(software0_button);
    qs_0->addWidget(button_stop0);
    qs_0->setCurrentIndex(0);
    QHBoxLayout *qh2 = new QHBoxLayout;
    qh2->addLayout(qv3);
    qh2->addLayout(qs_0);
    QVBoxLayout *qv4 = new QVBoxLayout;
    qv4->addWidget(software0_imga);
    qv4->addLayout(qh2);
    qv4->addStretch();

    //software1
    QHBoxLayout *qh2_1 = new QHBoxLayout;
    qh2_1->addWidget(software1_num);
    qh2_1->addWidget(software1_size);
//    qh2_1->addStretch();
    QVBoxLayout *qv3_1 = new QVBoxLayout;
    qv3_1->addWidget(software1_name);
    qv3_1->addLayout(qh2_1);
//    qv3_1->addStretch();
    qs_1 =  new QStackedLayout;
    qs_1->addWidget(software1_installbutton);
    qs_1->addWidget(software1_button);
    qs_1->addWidget(button_stop1);
    qs_1->setCurrentIndex(0);
    QHBoxLayout *qh2_1_1 = new QHBoxLayout;
    qh2_1_1->addWidget(software1_imga);
    qh2_1_1->addLayout(qv3_1);
    qh2_1_1->addLayout(qs_1);
//    qh2_1_1->addStretch();
    QVBoxLayout *qv4_1 = new QVBoxLayout;
    qv4_1->addLayout(qh2_1_1);
    qv4_1->addWidget(software1_introduce);
    qv4_1->addStretch();

    //software2
    QHBoxLayout *qh2_2 = new QHBoxLayout;
    qh2_2->addWidget(software2_num);
    qh2_2->addWidget(software2_size);
//    qh2_2->addStretch();
    QVBoxLayout *qv3_2 = new QVBoxLayout;
    qv3_2->addWidget(software2_name);
    qv3_2->addLayout(qh2_2);
//    qv3_2->addStretch();
    qs_2 =  new QStackedLayout;
    qs_2->addWidget(software2_installbutton);
    qs_2->addWidget(software2_button);
    qs_2->addWidget(button_stop2);
    qs_2->setCurrentIndex(0);
    QHBoxLayout *qh2_1_2 = new QHBoxLayout;
    qh2_1_2->addWidget(software2_imga);
    qh2_1_2->addLayout(qv3_2);
    qh2_1_2->addLayout(qs_2);
//    qh2_1_2->addStretch();
    QVBoxLayout *qv4_2 = new QVBoxLayout;
    qv4_2->addLayout(qh2_1_2);
    qv4_2->addWidget(software2_introduce);
    qv4_2->addStretch();

    //software3
    QHBoxLayout *qh2_3 = new QHBoxLayout;
    qh2_3->addWidget(software3_num);
    qh2_3->addWidget(software3_size);
    qh2_3->addStretch();
    QVBoxLayout *qv3_3 = new QVBoxLayout;
    qv3_3->addWidget(software3_name);
    qv3_3->addLayout(qh2_3);
    qv3_3->addStretch();
    qs_3 =  new QStackedLayout;
    qs_3->addWidget(software3_installbutton);
    qs_3->addWidget(software3_button);
    qs_3->addWidget(button_stop3);
    qs_3->setCurrentIndex(0);
    QHBoxLayout *qh2_1_3 = new QHBoxLayout;
    qh2_1_3->addWidget(software3_imga);
    qh2_1_3->addLayout(qv3_3);
    qh2_1_3->addLayout(qs_3);
    qh2_1_3->addStretch();
    QVBoxLayout *qv4_3 = new QVBoxLayout;
    qv4_3->addLayout(qh2_1_3);
    qv4_3->addWidget(software3_introduce);
    qv4_3->addStretch();

    //software4
    QHBoxLayout *qh2_4 = new QHBoxLayout;
    qh2_4->addWidget(software4_num);
    qh2_4->addWidget(software4_size);
//    qh2_4->addStretch();
    QVBoxLayout *qv3_4 = new QVBoxLayout;
    qv3_4->addWidget(software4_name);
    qv3_4->addLayout(qh2_4);
//    qv3_4->addStretch();
    qs_4 =  new QStackedLayout;
    qs_4->addWidget(software4_installbutton);
    qs_4->addWidget(software4_button);
    qs_4->addWidget(button_stop4);
    qs_4->setCurrentIndex(0);
    QHBoxLayout *qh2_1_4 = new QHBoxLayout;
    qh2_1_4->addWidget(software4_imga);
    qh2_1_4->addLayout(qv3_4);
    qh2_1_4->addLayout(qs_4);
//    qh2_1_4->addStretch();
    QVBoxLayout *qv4_4 = new QVBoxLayout;
    qv4_4->addLayout(qh2_1_4);
    qv4_4->addWidget(software4_introduce);
    qv4_4->addStretch();

    QGridLayout *qg1 = new QGridLayout;
    qg1->addLayout(qv2_1,0,0);
    qg1->addLayout(qv2_2,0,1);
    qg1->addLayout(qv2_3,1,0);
    qg1->addLayout(qv2_4,1,1);
    qg1->addLayout(qv4_1,2,0);
    qg1->addLayout(qv4_2,2,1);
    qg1->addLayout(qv4_3,3,0);
    qg1->addLayout(qv4_4,3,1);
    QVBoxLayout *v1 = new QVBoxLayout;
    v1->addLayout(qv2);
    v1->addLayout(qv4);
    QHBoxLayout *h = new QHBoxLayout;
    h->addLayout(v1);
    h->addLayout(qg1);
    h->setSpacing(10);
//    QGridLayout *gl = new QGridLayout;
//    gl->addLayout(qv2,0,0);
//    gl->addLayout(qg1,0,1);
//    gl->addLayout(qv4,1,0);
//    gl->addLayout(qg2,1,1);
//    QHBoxLayout *hb1 = new QHBoxLayout;
//    hb1->addLayout(qv2);
//    hb1->addLayout(qg1);
//    hb1->setSpacing(15);
//    QHBoxLayout *hb2 = new QHBoxLayout;
//    hb2->addLayout(qv4);
//    hb2->addLayout(qg2);
//    hb2->setSpacing(15);
//    QVBoxLayout *qg3 =  new QVBoxLayout;
//    qg3->addWidget(game,0,0);
//    qg3->addLayout(hb1);
//    qg3->addWidget(software,1,0);
//    qg3->addLayout(hb2);
    flag = "none";
   //按钮绑定事件监听
   //游戏
   connect(game0_installbutton,SIGNAL(clicked()),this,SLOT(game0()));
   connect(game1_installbutton,SIGNAL(clicked()),this,SLOT(game1()));
   connect(game2_installbutton,SIGNAL(clicked()),this,SLOT(game2()));
   connect(game3_installbutton,SIGNAL(clicked()),this,SLOT(game3()));
   connect(game4_installbutton,SIGNAL(clicked()),this,SLOT(game4()));
   connect(game0_button,SIGNAL(clicked()),this,SLOT(game0showstop()));
   connect(game1_button,SIGNAL(clicked()),this,SLOT(game1showstop()));
   connect(game2_button,SIGNAL(clicked()),this,SLOT(game2showstop()));
   connect(game3_button,SIGNAL(clicked()),this,SLOT(game3showstop()));
   connect(game4_button,SIGNAL(clicked()),this,SLOT(game4showstop()));
   connect(stop0_button,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(stop1_button,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(stop2_button,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(stop3_button,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(stop4_button,SIGNAL(clicked()),this,SLOT(changemode()));
   stop0_button->setObjectName("gamestop0");
   stop1_button->setObjectName("gamestop1");
   stop2_button->setObjectName("gamestop2");
   stop3_button->setObjectName("gamestop3");
   stop4_button->setObjectName("gamestop4");
   //软件
   connect(software0_installbutton,SIGNAL(clicked()),this,SLOT(software0()));
   connect(software1_installbutton,SIGNAL(clicked()),this,SLOT(software1()));
   connect(software2_installbutton,SIGNAL(clicked()),this,SLOT(software2()));
   connect(software3_installbutton,SIGNAL(clicked()),this,SLOT(software3()));
   connect(software4_installbutton,SIGNAL(clicked()),this,SLOT(software4()));
   connect(software0_button,SIGNAL(clicked()),this,SLOT(software0showstop()));
   connect(software1_button,SIGNAL(clicked()),this,SLOT(software1showstop()));
   connect(software2_button,SIGNAL(clicked()),this,SLOT(software2showstop()));
   connect(software3_button,SIGNAL(clicked()),this,SLOT(software3showstop()));
   connect(software4_button,SIGNAL(clicked()),this,SLOT(software4showstop()));
   connect(button_stop0,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(button_stop1,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(button_stop2,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(button_stop3,SIGNAL(clicked()),this,SLOT(changemode()));
   connect(button_stop4,SIGNAL(clicked()),this,SLOT(changemode()));
   button_stop0->setObjectName("softwarestop0");
   button_stop1->setObjectName("softwarestop1");
   button_stop2->setObjectName("softwarestop2");
   button_stop3->setObjectName("softwarestop3");
   button_stop4->setObjectName("softwarestop4");

   this->setStyleSheet("QPushButton{font: bold;font-size:15px;color:rgb(169,169,169);border:1px solid rgb(169,169,169);border-radius:5px;}");
   setLayout(h);
}
void Three_Widget::changemode()
{
        QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
        if(clickedButton != NULL)
        {
            if(clickedButton->objectName() == "gamestop0")
            {
                flag = "game0";
                qs0->setCurrentIndex(1);
                game0_thread = new Thread(flag,350);
                connect(game0_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(game0_thread,SIGNAL(timerSignal(int)),this,SLOT(game0change(int)));
                game0_thread->thread_restart(game0value);
                game0_thread->start();
            }
            if(clickedButton->objectName() == "gamestop1")
            {
                flag = "game1";
                qs1->setCurrentIndex(1);
                game1_thread = new Thread(flag,350);
                connect(game1_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(game1_thread,SIGNAL(timerSignal(int)),this,SLOT(game1change(int)));
                game1_thread->thread_restart(game1value);
                game1_thread->start();
            }
            if(clickedButton->objectName() == "gamestop2")
            {
                flag = "game2";
                qs2->setCurrentIndex(1);
                game2_thread = new Thread(flag,350);
                connect(game2_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(game2_thread,SIGNAL(timerSignal(int)),this,SLOT(game2change(int)));
                game2_thread->thread_restart(game2value);
                game2_thread->start();
            }
            if(clickedButton->objectName() == "gamestop3")
            {
                flag = "game3";
                qs3->setCurrentIndex(1);
                game3_thread = new Thread(flag,350);
                connect(game3_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(game3_thread,SIGNAL(timerSignal(int)),this,SLOT(game3change(int)));
                game3_thread->thread_restart(game3value);
                game3_thread->start();
            }
            if(clickedButton->objectName() == "gamestop4")
            {
                flag = "game4";
                qs4->setCurrentIndex(1);
                game4_thread = new Thread(flag,350);
                connect(game4_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(game4_thread,SIGNAL(timerSignal(int)),this,SLOT(game4change(int)));
                game4_thread->thread_restart(game4value);
                game4_thread->start();
            }
            if(clickedButton->objectName() == "softwarestop0")
            {
                flag = "software0";
                qs_0->setCurrentIndex(1);
                software0_thread = new Thread(flag,350);
                connect(software0_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(software0_thread,SIGNAL(timerSignal(int)),this,SLOT(software0change(int)));
                software0_thread->thread_restart(software0value);
                software0_thread->start();
            }
            if(clickedButton->objectName() == "softwarestop1")
            {
                flag = "software1";
                qs_1->setCurrentIndex(1);
                software1_thread = new Thread(flag,350);
                connect(software1_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(software1_thread,SIGNAL(timerSignal(int)),this,SLOT(software1change(int)));
                software1_thread->thread_restart(software1value);
                software1_thread->start();
            }
            if(clickedButton->objectName() == "softwarestop2")
            {
                flag = "software2";
                qs_2->setCurrentIndex(1);
                software2_thread = new Thread(flag,350);
                connect(software2_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(software2_thread,SIGNAL(timerSignal(int)),this,SLOT(software2change(int)));
                software2_thread->thread_restart(software2value);
                software2_thread->start();
            }
            if(clickedButton->objectName() == "softwarestop3")
            {
                flag = "software3";
                qs_3->setCurrentIndex(1);
                software3_thread = new Thread(flag,350);
                connect(software3_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(software3_thread,SIGNAL(timerSignal(int)),this,SLOT(software3change(int)));
                software3_thread->thread_restart(software3value);
                software3_thread->start();
            }
            if(clickedButton->objectName() == "softwarestop4")
            {
                flag = "software4";
                qs_4->setCurrentIndex(1);
                software4_thread = new Thread(flag,350);
                connect(software4_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
                connect(software4_thread,SIGNAL(timerSignal(int)),this,SLOT(software4change(int)));
                software4_thread->thread_restart(software4value);
                software4_thread->start();
            }
        }
}
void Three_Widget::game0change(int value)
{
    game0_pb->setValue(value);
    game0value = value;
}
void Three_Widget::game1change(int value)
{
     game1_pb->setValue(value);
     game1value = value;
}
void Three_Widget::game2change(int value)
{
     game2_pb->setValue(value);
     game2value = value;
}
void Three_Widget::game3change(int value)
{
     game3_pb->setValue(value);
     game3value = value;
}
void Three_Widget::game4change(int value)
{
     game4_pb->setValue(value);
     game4value = value;
}
void Three_Widget::software0change(int value)
{
     software0_pb->setValue(value);
     software0value = value;
}
void Three_Widget::software1change(int value)
{
     software1_pb->setValue(value);
     software1value = value;
}
void Three_Widget::software2change(int value)
{
     software2_pb->setValue(value);
     software2value = value;
}
void Three_Widget::software3change(int value)
{
     software3_pb->setValue(value);
     software3value = value;
}
void Three_Widget::software4change(int value)
{
     software4_pb->setValue(value);
     software4value = value;
}
void Three_Widget::thread(QString threadname)
{
        if(threadname == "game0")
        {
            game0_pb->setValue(100);
            QThread::sleep(1);
            game0_pb->close();
            qs0->setCurrentIndex(0);
            game0_installbutton->setText(tr("已安装"));
            game0_installbutton->setDisabled(true);
            game0_thread->quit();
        }
        if(threadname == "game1")
        {
            game1_pb->setValue(100);
            QThread::sleep(1);
            game1_pb->close();
            qs1->setCurrentIndex(0);
            game1_installbutton->setText(tr("已安装"));
            game1_installbutton->setDisabled(true);
            //安装次数加1
            game1_count++;
            game1_num->setText(""+QString::number(game1_count,10)+"");
            game1_thread->quit();
        }
        if(threadname == "game2")
        {
            game2_pb->setValue(100);
            QThread::sleep(1);
            game2_pb->close();
            qs2->setCurrentIndex(0);
            game2_installbutton->setText(tr("已安装"));
            game2_installbutton->setDisabled(true);
            //安装次数加1
            game2_count++;
            game2_num->setText(""+QString::number(game2_count,10)+"");
            game2_thread->quit();
        }
        if(threadname == "game3")
        {
            game3_pb->setValue(100);
            QThread::sleep(1);
            game3_pb->close();
            qs3->setCurrentIndex(0);
            game3_installbutton->setText(tr("已安装"));
            game3_installbutton->setDisabled(true);
            //安装次数加1
            game3_count++;
            game3_num->setText(""+QString::number(game3_count,10)+"");
            game3_thread->quit();
        }
        if(threadname == "game4")
        {
            game4_pb->setValue(100);
            QThread::sleep(1);
            game4_pb->close();
            qs4->setCurrentIndex(0);
            game4_installbutton->setText(tr("已安装"));
            game4_installbutton->setDisabled(true);
            //安装次数加1
            game4_count++;
            game4_num->setText(""+QString::number(game4_count,10)+"");
            game4_thread->quit();
        }
        if(threadname == "software0")
        {
            software0_pb->setValue(100);
            QThread::sleep(1);
            software0_pb->close();
            qs_0->setCurrentIndex(0);
            software0_installbutton->setText(tr("已安装"));
            software0_installbutton->setDisabled(true);
            software0_thread->quit();
        }
        if(threadname == "software1")
        {
            software1_pb->setValue(100);
            QThread::sleep(1);
            software1_pb->close();
            qs_1->setCurrentIndex(0);
            software1_installbutton->setText(tr("已安装"));
            software1_installbutton->setDisabled(true);
            //安装次数加1
            software1_count++;
            software1_num->setText(""+QString::number(software1_count,10)+"");
            software1_thread->quit();
        }
        if(threadname == "software2")
        {
            software2_pb->setValue(100);
            QThread::sleep(1);
            software2_pb->close();
            qs_2->setCurrentIndex(0);
            software2_installbutton->setText(tr("已安装"));
            software2_installbutton->setDisabled(true);
            //安装次数加1
            software2_count++;
            software2_num->setText(""+QString::number(software2_count,10)+"");
            software2_thread->quit();
        }
        if(threadname == "software3")
        {
            software3_pb->setValue(100);
            QThread::sleep(1);
            software3_pb->close();
            qs_3->setCurrentIndex(0);
            software3_installbutton->setText(tr("已安装"));
            software3_installbutton->setDisabled(true);
            //安装次数加1
            software3_count++;
            software3_num->setText(""+QString::number(software3_count,10)+"");
            software3_thread->quit();
        }
        if(threadname == "software4")
        {
            software4_pb->setValue(100);
            QThread::sleep(1);
            software4_pb->close();
            qs_4->setCurrentIndex(0);
            software4_installbutton->setText(tr("已安装"));
            software4_installbutton->setDisabled(true);
            //安装次数加1
            software4_count++;
            software4_num->setText(""+QString::number(software4_count,10)+"");
            software4_thread->quit();
        }
}
void Three_Widget::game0()
{
   qs0->setCurrentIndex(1);
   flag = "game0";

   qsbar = new QStackedLayout;
   qsbar->addWidget(game0_pb);

   game0_button->setLayout(qsbar);
   game0_thread = new Thread(flag,200);
   connect(game0_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(game0_thread,SIGNAL(timerSignal(int)),this,SLOT(game0change(int)));
   game0_thread->start();
}
void Three_Widget::game1()
{
   qs1->setCurrentIndex(1);
   flag = "game1";

   qsbar = new QStackedLayout;
   qsbar->addWidget(game1_pb);

   game1_button->setLayout(qsbar);

   game1_thread = new Thread(flag,200);
   connect(game1_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(game1_thread,SIGNAL(timerSignal(int)),this,SLOT(game1change(int)));
   game1_thread->start();
}
void Three_Widget::game2()
{
   qs2->setCurrentIndex(1);
   flag = "game2";

   qsbar = new QStackedLayout;
   qsbar->addWidget(game2_pb);

   game2_button->setLayout(qsbar);

   game2_thread = new Thread(flag,200);
   connect(game2_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(game2_thread,SIGNAL(timerSignal(int)),this,SLOT(game2change(int)));
   game2_thread->start();
}
void Three_Widget::game3()
{
   qs3->setCurrentIndex(1);
   flag = "game3";

   qsbar = new QStackedLayout;
   qsbar->addWidget(game3_pb);

   game3_button->setLayout(qsbar);

   game3_thread= new Thread(flag,200);
   connect(game3_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(game3_thread,SIGNAL(timerSignal(int)),this,SLOT(game3change(int)));
   game3_thread->start();
}
void Three_Widget::game4()
{
   qs4->setCurrentIndex(1);
   flag = "game4";

   qsbar = new QStackedLayout;
   qsbar->addWidget(game4_pb);

   game4_button->setLayout(qsbar);

   game4_thread = new Thread(flag,200);
   connect(game4_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(game4_thread,SIGNAL(timerSignal(int)),this,SLOT(game4change(int)));
   game4_thread->start();
}
void Three_Widget::software0()
{
   qs_0->setCurrentIndex(1);
   flag = "software0";

   qsbar = new QStackedLayout;
   qsbar->addWidget(software0_pb);

   software0_button->setLayout(qsbar);

   software0_thread = new Thread(flag,200);
   connect(software0_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(software0_thread,SIGNAL(timerSignal(int)),this,SLOT(software0change(int)));
   software0_thread->start();
}
void Three_Widget::software1()
{
   qs_1->setCurrentIndex(1);
   flag = "software1";

   qsbar = new QStackedLayout;
   qsbar->addWidget(software1_pb);

   software1_button->setLayout(qsbar);

   software1_thread = new Thread(flag,200);
   connect(software1_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(software1_thread,SIGNAL(timerSignal(int)),this,SLOT(software1change(int)));
   software1_thread->start();
}
void Three_Widget::software2()
{
   qs_2->setCurrentIndex(1);
   flag = "software2";

   qsbar = new QStackedLayout;
   qsbar->addWidget(software2_pb);

   software2_button->setLayout(qsbar);

   software2_thread = new Thread(flag,200);
   connect(software2_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(software2_thread,SIGNAL(timerSignal(int)),this,SLOT(software2change(int)));
   software2_thread->start();
}
void Three_Widget::software3()
{
   qs_3->setCurrentIndex(1);
   flag = "software3";

   qsbar = new QStackedLayout;
   qsbar->addWidget(software3_pb);

   software3_button->setLayout(qsbar);

   software3_thread = new Thread(flag,200);
   connect(software3_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(software3_thread,SIGNAL(timerSignal(int)),this,SLOT(software3change(int)));
   software3_thread->start();
}
void Three_Widget::software4()
{
   qs_4->setCurrentIndex(1);
   flag = "software4";

   qsbar = new QStackedLayout;
   qsbar->addWidget(software4_pb);

   software4_button->setLayout(qsbar);

   software4_thread = new Thread(flag,200);
   connect(software4_thread,SIGNAL(emitSignal(QString)),this,SLOT(thread(QString)));
   connect(software4_thread,SIGNAL(timerSignal(int)),this,SLOT(software4change(int)));
   software4_thread->start();
}
void Three_Widget::game0showstop()
{
        qs0->setCurrentIndex(2);
        game0_thread->thread_stop();
        game0_thread->quit();
}
void Three_Widget::game1showstop()
{
    qs1->setCurrentIndex(2);
    game1_thread->thread_stop();
    game1_thread->quit();
}
void Three_Widget::game2showstop()
{
    qs2->setCurrentIndex(2);
    game2_thread->thread_stop();
    game2_thread->quit();
}
void Three_Widget::game3showstop()
{
    qs3->setCurrentIndex(2);
    game3_thread->thread_stop();
    game3_thread->quit();
}
void Three_Widget::game4showstop()
{
    qs4->setCurrentIndex(2);
     game4_thread->thread_stop();
     game4_thread->quit();
}
void Three_Widget::software0showstop()
{
    qs_0->setCurrentIndex(2);
    software0_thread->thread_stop();
    software0_thread->quit();
}
void Three_Widget::software1showstop()
{
    qs_1->setCurrentIndex(2);
    software1_thread->thread_stop();
    software1_thread->quit();
}
void Three_Widget::software2showstop()
{
    qs_2->setCurrentIndex(2);
    software2_thread->thread_stop();
    software2_thread->quit();
}
void Three_Widget::software3showstop()
{
    qs_3->setCurrentIndex(2);
    software3_thread->thread_stop();
    software3_thread->quit();
}
void Three_Widget::software4showstop()
{
    qs_4->setCurrentIndex(2);
    software4_thread->thread_stop();
    software4_thread->quit();
}
