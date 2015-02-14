#include "hintdialog.h"
#include "QPainter"
#include "QStackedWidget"
#include "QDebug"
#include "QMovie"
 int id=0;
hintDialog::hintDialog(QWidget *parent) :
    QDialog(parent)
{
    flag=1;
    //QPixmap back_color(":/default/green.jpg");
   // QPixmap close(":/picture/button_pic/close.png");
    QPixmap step1(":/picture/guide/step1.jpg");
    QPixmap step2(":/picture/guidestep2.jpg");
    QMovie *pix3=new QMovie(":/picture/guidewelcome.gif");
    label=new QLabel;//top
    label->setStyleSheet("background-color:#2e8b57");
    label1=new QWidget;
    label2=new QLabel;
    label2->setStyleSheet("background-color:#2e8b57");
    label1=new QWidget;
    content1 = new QLabel("content1");
    content1->setPixmap(step1);
    content1->setFixedSize(500,310);
    content1->setParent(label1);
    content2=new QLabel("content2");//内容二
    content2->setFixedSize(500,310);
    content2->setPixmap(step2);
    content3 = new QLabel;
    stack = new QStackedWidget(label1);
    QPixmap pix(":/picture/guide/close.png");
    close_btn=new QPushButton;
    pix.scaled(pix.width(),pix.height());
    close_btn->setIcon(pix);
    close_btn->setIconSize(QSize(pix.width(),pix.height()));
    close_btn->setFlat(true);
    close_btn->setFixedSize(30,30);

    back_btn=new QPushButton(">>");
    back_btn->setFlat(true);
    back_btn->setFixedSize(50,50);
    forward_btn=new QPushButton("<<");
    forward_btn->setFlat(true);
    forward_btn->setFixedSize(50,50);

    reconnect= new QPushButton("重新连接");
    reconnect->setFixedSize(70,40);
    reconnect->setFlat(true);
    QHBoxLayout *top_layout=new QHBoxLayout;
    QHBoxLayout *center_layout = new QHBoxLayout;
    QHBoxLayout *guide_layout = new QHBoxLayout;
    QVBoxLayout *main_layout=new QVBoxLayout;
    QHBoxLayout *footer_layout= new QHBoxLayout;
//top ---------------------------------------------

    //label->setGeometry(0,0,400,50);
    label->setFixedSize(500,50);
    label->setLayout(top_layout);
    //label->setPixmap(back_color);
    //label2->setPixmap(back_color);
    top_layout->addStretch();
    top_layout->addWidget(close_btn,0,Qt::AlignTop);
//center
    guide_layout->addWidget(forward_btn,0,Qt::AlignLeft);
    guide_layout->addWidget(back_btn,0,Qt::AlignRight);
    center_layout->addWidget(stack);
    center_layout->setMargin(0);
    center_layout->setSpacing(0);
    label1->setFixedSize(500,310);
    //label1->setScaledContents(true);
    content1->setLayout(guide_layout);
    label1->setLayout(center_layout);
//footer
    footer_layout->addWidget(reconnect);
    label2->setFixedSize(500,50);
    label2->setScaledContents(true);
    label2->setLayout(footer_layout);

    content3=new QLabel(this);
    content3->setScaledContents(true);
    content3->setMovie(pix3);
    pix3->start();
    content3->setFixedSize(500,300);
    stack->addWidget(content1);
    stack->addWidget(content2);
    stack->addWidget(content3);
//    stack->addWidget(content3);
    main_layout->addWidget(label);//top
    main_layout->addWidget(label1);//center
    main_layout->addWidget(label2);//bottom
    main_layout->setMargin(0);
    main_layout->setSpacing(0);
   // content1->setStyleSheet("border:1px dashed black;");
   // label1->setStyleSheet("border:1px solid black;");
   // label->setStyleSheet("border:1px solid black;");
   // label2->setStyleSheet("border:1px solid black;");
    //content2->setStyleSheet("border:1px dashed black;background-color:yellow");
    //content3->setStyleSheet("border:1px dashed black;background-color:yellow");
    this->setLayout(main_layout);
    this->setFixedSize(500,400);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //this->setStyleSheet("background-image:url(:/default/green.jpg)");
    stack->setCurrentIndex(0);
    connect(close_btn,SIGNAL(clicked()),this,SLOT(close()));
    connect(back_btn,SIGNAL(clicked()),this,SLOT(turnpage()));
    connect(reconnect,SIGNAL(clicked()),this,SLOT(turn_trying_page()));
    connect(forward_btn,SIGNAL(clicked()),this,SLOT(turnpage()));
}

hintDialog::~hintDialog()
{

}
void hintDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_DragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void hintDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
void hintDialog::turnpage(){
    id++;
    id=id%2;
    qDebug() << id;
    if(id == 0){
        stack->setCurrentIndex(0);
    }
    else{
        stack->setCurrentIndex(1);
    }
}

void hintDialog::turn_trying_page(){
    stack->setCurrentIndex(2);
    //not connected
    qDebug()<< flag;
    emit changeTimer();
}
void hintDialog::change_state(){
    if(flag == 0){//not connected
        QPixmap pixmap(":/picture/guide/step3.jpg");
        content3->clearMask();
        content3->setPixmap(pixmap);
    }
    if( flag == 1){//connecting
        QMovie *movie= new QMovie(":/picture/guide/welcome.gif");
        content3->setMovie(movie);
        movie->start();
    }
    if(flag == 2){//connected
        QPixmap pixmap(":/picture/guide/step4.jpg");
        content3->clearMask();
        content3->setPixmap(pixmap);
    }
}
