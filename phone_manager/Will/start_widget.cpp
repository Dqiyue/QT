#include "start_widget.h"

Start_Widget::Start_Widget(QWidget *parent) :
    Shdow_Pro(parent)
{
    this->setMaximumSize(900,600);
    this->setMinimumSize(900,600);

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(Qt::white));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    this->initup();



    my_layout = new QVBoxLayout();
// //   mainsplitter = new QSplitter();
// //   mainsplitter->setOrientation(Qt::Vertical);

////    mainsplitter->addWidget(up);
////    mainsplitter->addWidget(down);
////    my_layout->addWidget(down);
    my_layout->addWidget(up);
    my_layout->setSpacing(0);
    my_layout->setContentsMargins(0, 0, 0, 0);

    this->setWindowIcon(QIcon(":/new/prefix1/pro.ico"));
    setLayout(my_layout);
}




void Start_Widget::initup()
{
    up = new QWidget();

    main_layout = new QVBoxLayout();
//    layout = new QVBoxLayout();
    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(230, 230, 230));
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText,QColor(255,255,255));

    welcome_label = new QLabel("Welcome to use our Phone Manager");
    welcome_label->setFont(QFont(URW_P_FONT, 36,50,true));
    welcome_label->setPalette(text_palette);
//    welcome_label->setScaledContents(true);


    QLabel *top_lab = new QLabel(up);
    top_lab->setMaximumSize(900,600);
    top_lab->setMinimumSize(900,600);
    top_lab->setStyleSheet("background-color:#27ae61");
    logo = new QLabel();

    start_button = new QPushButton();
    QPixmap pixmap(":/picture/button_pic/start");
    logo->setPixmap(pixmap.scaled(120,120));
    start_button->setText("Start >");
    start_button->setFont(QFont("黑体",27,9,false));
    start_button->setStyleSheet("border-radius:8px");
    start_button->clearMask();
 //   start_button->setBackgroundRole(QPalette::ButtonText, QColor(230, 230, 230));
    start_button->setPalette(button_text_palette);
    start_button->setGeometry(0,0,200,150);
    start_button->setFlat(true);
    main_layout->addStretch();
    main_layout->addWidget(logo,0,Qt::AlignHCenter);
    main_layout->addSpacing(60);
    main_layout->addWidget(welcome_label,0,Qt::AlignHCenter);
    main_layout->addSpacing(60);
    main_layout->addWidget(start_button,0,Qt::AlignHCenter);
    main_layout->addStretch();
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0,0,0,0);


//    connect(start_button,SIGNAL(clicked()),this,SLOT(hide_and_seek()));
    connect(start_button,SIGNAL(clicked()),this,SLOT(main_start()));
//    logo->setScaledContents(true);

    up->setLayout(main_layout);
}

Start_Widget::~Start_Widget()
{

}


void Start_Widget::start_view()
{
    start_animation = new QPropertyAnimation(up,"geometry");
 //   txt_animation = new QPropertyAnimation()
    start_animation->setDuration(2000);
    start_animation->setStartValue(QRect(0,0,900,200));

//    start_animation->setKeyValueAt(0.25,QRect(0,0,900,600));
//  //    start_animation->setStartValue(QRect(0,0,900,450));
//    start_animation->setKeyValueAt(0.6,QRect(0,0,900,400));
//    start_animation->setKeyValueAt(0.7,QRect(0,0,900,600));
//    start_animation->setKeyValueAt(0.8,QRect(0,0,900,500));

    start_animation->setEndValue(QRect(0,0,900,600));
    start_animation->setEasingCurve(QEasingCurve::OutBack);
    start_animation->start();
}

void Start_Widget::show_widget()
{
    this->start_view();
    this->showNormal();
    this->raise();
    this->activateWindow();

}

void Start_Widget::main_start()
{
    start_button->setDisabled(true);
    here_we_go = new Main_Widget();
    here_we_go->show_widget();

    this->close();

}

void Start_Widget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(5, 5, this->width()-10, this->height()-10));
}

//void Start_Widget::hide_and_seek()
//{

//    this->end_view();
// //   here_we_go = new Main_Widget();
// //   here_we_go->show_widget();
// //   this->close();
//}
//void Start_Widget::end_view()
//{
//    start_animation = new QPropertyAnimation(up,"geometry");
// //   txt_animation = new QPropertyAnimation()
//    start_animation->setDuration(2000);
//    start_animation->setStartValue(QRect(0,0,900,600));

//  //    start_animation->setStartValue(QRect(0,0,900,450));
//    start_animation->setEndValue(QRect(0,0,900,110));
//    start_animation->setEasingCurve(QEasingCurve::OutBack);
//    start_animation->start();
//}
