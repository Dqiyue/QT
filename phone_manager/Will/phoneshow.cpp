#include "phoneshow.h"
#include "QDebug"
Phoneshow::Phoneshow(QWidget *parent) :
    QWidget(parent)
{
    img = new My_Label();
    testTimer = new QTimer();
    phoneshow();
    connect(testTimer,SIGNAL(timeout()), this, SLOT(phoneshow()) );
    connect(img, SIGNAL(show_clicked()), this, SLOT(showexit()));
    QVBoxLayout *qv = new QVBoxLayout;
    qv->addWidget(img,0,Qt::AlignCenter);
    qv->setMargin(0);
    this->setLayout(qv);
    this->setFixedSize(img->width(),img->height());
    this->setWindowFlags(Qt::FramelessWindowHint);

}

Phoneshow::~Phoneshow()
{
}
void Phoneshow::phoneshow()
{

   showimg();
   testTimer->start(200);
}
void Phoneshow::showexit()
{
    testTimer->stop();
//    pro->close();
    this->close();
    emit phone_exit();
}
void Phoneshow::showimg()
{
   //开启外部程序，调用获取手机信息的脚本
   pro = new QProcess;
   pro->start("bash ./shell_script/get_phone_screen/phoneshow.sh");
   pro->waitForFinished();//等待外部程序执行完成
   int ec = pro->exitCode();
   if(!ec)//脚本执行完成后
   {
//           img ->setGeometry(QRect(5, 5, 5, 5));//手机屏幕的图片放置在phone_img这个label上
           //调整屏幕图片的大小
           QPixmap pixmap("./screen_img/currentscreen/currentscreen.png");
//           QPixmap fitpixmap=pixmap.scaled(155, 269).scaled(155, 269,Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
           img ->setPixmap(pixmap);
           img->setFixedSize(300,500);
           img->setScaledContents(true);

//           img ->setStyleSheet("QLabel{border-image:url(:/phone/default.png) 0 0 0 0;border-radius:1px;padding:0px 10px;}");
      }
       pro->close();//关闭外部程序
       delete pro;
       pro = 0;
   }
void Phoneshow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_DragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void Phoneshow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
