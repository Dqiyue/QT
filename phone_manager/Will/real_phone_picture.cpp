#include "real_phone_picture.h"

Real_Phone_Picture::Real_Phone_Picture(QString imgname,QString imgpath)
{
    showImage = new Show_Image(imgname,imgpath);
    showImage->setFixedSize(330,300);
    //creat new widgets
    prevButton = new QPushButton;
    nextButton = new QPushButton;
    spinbutton = new QPushButton;
    slider = new QSlider(Qt::Vertical, this);
    label = new QLabel;
    //设置按钮风格
    spinbutton->clearMask();
    spinbutton->setBackgroundRole( QPalette::Base);
    QPixmap spinpixmap;
    spinpixmap.load(":/picture/phone_picture/spin.png");
    spinbutton->setFixedSize(spinpixmap.width()-1, spinpixmap.height()-1);
    spinbutton->setMask(spinpixmap.createHeuristicMask());
    spinbutton->setIcon(spinpixmap);
    spinbutton->setIconSize(QSize(spinpixmap.width()-1,spinpixmap.height()-1));

    prevButton->setGeometry(10,10,200,200); //按钮的位置及大小
    prevButton->clearMask();
    prevButton->setBackgroundRole( QPalette::Base);
    QPixmap mypixmap;
    mypixmap.load(":/picture/phone_picture/left.png");
    prevButton->setFixedSize( mypixmap.width(), mypixmap.height());
    prevButton->setMask(mypixmap.createHeuristicMask());
    prevButton->setIcon(mypixmap);
    prevButton->setIconSize(QSize(mypixmap.width(),mypixmap.height()));
    nextButton->setGeometry(10,10,200,200); //按钮的位置及大小
    nextButton->clearMask();
    nextButton->setBackgroundRole( QPalette::Base);
    QPixmap mypixmap1;
    mypixmap1.load(":/picture/phone_picture/right.png");
    nextButton->setFixedSize( mypixmap1.width(), mypixmap1.height());
    nextButton->setMask(mypixmap1.createHeuristicMask());
    nextButton->setIcon(mypixmap1);
    nextButton->setIconSize(QSize(mypixmap1.width(),mypixmap1.height()));
    slider->setStyleSheet("QSlider::groove:vertical {  border: 2px solid #7CCD7C;  background: #C0C0C0;  width: 9px;  border-radius: 1px;  padding-left:-5px;  padding-right:-5px;  padding-top:-3px;  padding-bottom:-3px;}   QSlider::handle:vertical{background:lightgreen;width:10px;border-radius:20px;margin:-10px 0px -10px 0px;}");
//    slider->setTickPosition(QSlider::TicksRight);
    //set the slot and signal
    connect(slider, SIGNAL(valueChanged(int)),this, SLOT(changelabel(int)));
    connect(prevButton, SIGNAL(clicked()),this, SLOT(turn2prev()));
    connect(nextButton, SIGNAL(clicked()),this, SLOT(turn2next()));
    connect(showImage, SIGNAL(get2beg(bool)),prevButton, SLOT(setDisabled(bool)));
    connect(showImage, SIGNAL(get2end(bool)),nextButton, SLOT(setDisabled(bool)));
    connect(slider, SIGNAL(valueChanged(int)),this, SLOT(scalethepix(int)));
    connect(showImage, SIGNAL(turn2default(int)),slider, SLOT(setValue(int)));
    connect(showImage, SIGNAL(img_clicked()),this, SLOT(close_window()));
    connect(spinbutton, SIGNAL(clicked()),this, SLOT(img_spin()));
    //set layout
    QVBoxLayout *qhl = new QVBoxLayout;
    qhl->addWidget(slider);
    qhl->addWidget(label);
    label->setBuddy(slider);
    qhl->addWidget(spinbutton);
//    qhl->addStretch();
    QHBoxLayout *qh = new QHBoxLayout;
    qh->addWidget(prevButton);
    qh->addWidget(showImage);
    qh->addLayout(qhl);
    qh->addWidget(nextButton);
    qh->addStretch();

//    qhl->addStretch();
//    QGridLayout *g = new QGridLayout;
//    g->addLayout(qh,0,0);
//    g->addLayout(qhl ,0,1);
//    QVBoxLayout *labelLayout = new QVBoxLayout;
//    labelLayout->addLayout(qh,Qt::AlignCenter);
//    labelLayout->addLayout(qhl,Qt::AlignHCenter);
    setLayout(qh);
    //set the Tab order
    setTabOrder(nextButton, prevButton);
    nextButton->setDefault(true);
    //set the short cut
    //PgUp for prevButton
    prevButton->setShortcut(QKeySequence(Qt::Key_Left));
    //PgDn for nextButton
    nextButton->setShortcut(QKeySequence(Qt::Key_Right));
    slider->setRange(0, 500);
    slider->setValue(100);
    prevButton->setEnabled(true);
    nextButton->setEnabled(true);
    //set window name
    setWindowFlags(Qt::FramelessWindowHint);
    this->setBackgroundRole(QPalette::Dark);
    this->setAutoFillBackground(true);
//    QPalette palette;
//    palette.setColor(QPalette::Background, QColor(169,169,169));
    //palette.setBrush(QPalette::Background, QBrush(QPixmap(":/background.png")));
//    this->setPalette(palette);
    setWindowOpacity(1);
    setAttribute(Qt::WA_TranslucentBackground);
}
void Real_Phone_Picture::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_DragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void Real_Phone_Picture::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
void Real_Phone_Picture::img_spin()
{
    showImage->spin_change();
}
void Real_Phone_Picture::close_window()
{
    this->close();
}
void Real_Phone_Picture::turn2prev()
{
    showImage->show_prev();
}

void Real_Phone_Picture::turn2next()
{
    showImage->show_next();
}

void Real_Phone_Picture::scalethepix(int rate)
{
    showImage->arise_scale(rate);
}
void Real_Phone_Picture::changelabel(int val)
{
    QString tmp;
    tmp.setNum(val);
    tmp += "%";
    label->setText(tmp);
}
