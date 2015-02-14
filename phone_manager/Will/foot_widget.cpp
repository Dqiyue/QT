#include "foot_widget.h"
#include "QDesktopWidget"
#include "QApplication"
#include "QProcess"
#include "QString"
Foot_Widget::Foot_Widget(QWidget *parent) :
    QWidget(parent)
{
//    this->setFocus();

    QDesktopWidget *d=QApplication::desktop();
   // this->setFixedWidth(d->width());
    back_label = new QLabel();
    back_label->setGeometry(0,0,d->width(),400);
    back_label->setStyleSheet(DEFAULT_SKIN);
    back_label->setParent(this);
    btn_pressed = false;

    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    tittle_layout = new QHBoxLayout();
    app_layout = new QGridLayout();

    my_app_btn = new QPushButton("< 推荐应用 >");
    my_app_btn->setFont(QFont(SIMPLE_FONT,12,60,false));
    my_app_btn->setPalette(button_text_palette);
    my_app_btn->setFlat(true);

    wireless_button = new QPushButton("< 无线连接 >");
    wireless_button->setFont(QFont(SIMPLE_FONT,12,60,false));
    wireless_button->setPalette(button_text_palette);
    wireless_button->setFlat(true);
    wireless_button->setAutoFillBackground(true);
    wireless_button->setFixedHeight(20);
    wireless_button->setStyleSheet("border-radius:2px;");

    my_app_btn->setAutoFillBackground(true);
    my_app_btn->setStyleSheet("border-radius:2px;");
    my_app_btn->setFixedHeight(20);

    tittle_layout->addWidget(my_app_btn,0,Qt::AlignTop);
    tittle_layout->addSpacing(60);
    tittle_layout->addWidget(wireless_button,0,Qt::AlignTop);
    tittle_layout->addStretch();

    main_layout = new QVBoxLayout();
    main_layout->addLayout(tittle_layout);
//    main_layout->addWidget(my_app_btn,0,Qt::AlignTop|Qt::AlignLeft);
    main_layout->addLayout(app_layout);
    main_layout->addStretch();
    install_process = new QProcess;
connect(wireless_button,SIGNAL(clicked()),this,SLOT(start_wireless_server()));
connect(install_process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(processError(QProcess::ProcessError)));
    connect(my_app_btn,SIGNAL(clicked()),this,SLOT(show_app()));
    setLayout(main_layout);
}

void Foot_Widget::show_app()
{
    bool is_pressed;
    is_pressed = btn_pressed;
        if(btn_pressed == false){ 
            btn_pressed = true;
            initApp();
        }
        else{
            clearApp();
            btn_pressed = false;

        }
    emit show_app(is_pressed);
}


void Foot_Widget::initApp()
{
    QStringList app_name_list;
    QStringList app_list_info;
    app_number = 0;
    QString path;
    path = COMMON_APP_DIR;

    QDir dir(path);
    if(dir.exists()){
        foreach(QFileInfo fileInfo,dir.entryInfoList(QDir::Files)){
            if(fileInfo.isFile()){
                    app_number++;

                    app_name_list.append(fileInfo.fileName());
                    app_fileInfo_list.append(fileInfo);
                    if(fileInfo.baseName().length()>10){
                        app_list_info.append(fileInfo.baseName().mid(0,9)+"..");
                    }
                    else
                    {
                        app_list_info.append(fileInfo.baseName());
                    }
                        //qDebug() << fileInfo.baseName();
            }
        }
     }

    QPalette button_text_palette = palette();
    //button_text_palette.setColor(QPalette::ButtonText, QColor(178,34,34));

    QPalette button_text_palette_name = palette();
    //button_text_palette_name.setColor(QPalette::ButtonText, QColor(0,0,0));

    QSignalMapper *signal_mapper = new QSignalMapper(this);

    for(int i=0; i<app_name_list.size(); i++)
    {

        QPushButton *button = new QPushButton("安装");
        QLabel *label_pic = new QLabel();
        QPushButton *label_name = new QPushButton(app_list_info.at(i));
        QVBoxLayout *list_layout = new QVBoxLayout();
        button->setFlat(true);
     //   button->setPalette(button_text_palette);
//        button->setFont(QFont(URW_P_FONT,8,QFont::Bold,true));
        button->setToolTip("install this app to the phone");
        label_name->setFlat(true);
       // label_name->setDisabled(true);
        //label_name->setPalette(button_text_palette_name);
//        label_pic->setDisabled(true);
//        label_pic->setFlat(true);

        QPixmap pixmap(COMMON_APP_DIR+app_name_list.at(i));
        label_pic->setPixmap(pixmap.scaled(50,50));
        label_pic->setAlignment(Qt::AlignCenter);
//        label_name->setFont(QFont(URW_C_FONT,10,50,true));
        btnlist_uninstall.append(button);

        list_layout->addWidget(label_pic);
//        list_layout->addWidget(pixmap);
        list_layout->addWidget(label_name);
        list_layout->addWidget(button);


        connect(button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(button,QString::number(i,10));
        app_layout->addLayout(list_layout,i/9,i%9,1,1,Qt::AlignCenter);
    }
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(uninstall(QString)));
}

void Foot_Widget::clearApp()
{
//    btnlist_uninstall.clear();
//    app_fileInfo_list.clear();
//    clearLayout(app_layout);
//    clearLayout(main_layout);
}


void Foot_Widget::uninstall(QString current)
{

    bool ok;
    int index = current.toInt(&ok,10);
    btnlist_uninstall.at(index)->clearMask();
    btnlist_uninstall.at(index)->setText("已安装");
    btnlist_uninstall.at(index)->setEnabled(false);

//    QString filename;
//    filename = app_fileInfo_list.at(index).absoluteFilePath();
//    QFile file(filename);
//    file.remove();
//    file.close();
//    update_my_app();
    //install app
    QString  info;
    if(index == 0)
        info = "adb install ./recommend_apk/CoolManager.apk";
    if(index == 1)
        info = "adb install ./recommend_apk/手机淘宝.apk";
    if(index == 2)
         info = "adb install ./recommend_apk/水果忍者.apk";
    if(index  == 3 )
        info = "adb install ./recommend_apk/CoolManager.apk";
        install_process->start(info);
        install_process->waitForFinished();
}

void Foot_Widget::update_my_app()
{

//    clearApp();

//    initApp();

}


//void Foot_Widget::clearLayout(QLayout* layout)
//{
//    qDebug() << "clear layout";
//    while (QLayoutItem* item = layout->takeAt(0))
//    {
//        if (QWidget* widget = item->widget())
//                delete widget;

//        if (QLayout* childLayout = item->layout())
//            clearLayout(childLayout);
//        delete item;
//    }
//}


void Foot_Widget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(5, 5, this->width()-2*5, this->height()-2*5));
}
void Foot_Widget::start_wireless_server(){
    process = new QProcess;
    QString info= "bash ./shell_script/server/server.sh";
    //QString info= "bash ./server.sh";
   qDebug() << info;
    process->start(info);
    qDebug() << "start wireless";
    wireless_button->setEnabled(false);
}
void Foot_Widget::processError(QProcess::ProcessError error){
    switch(error)
    {
     case QProcess::FailedToStart:
       QMessageBox::information(0,"命令错误","命令错误");
       break;
     case QProcess::Crashed:
       QMessageBox::information(0,"Crashed","Crashed");
       break;
     case QProcess::Timedout:
       QMessageBox::information(0,"FailedToStart","FailedToStart");
       break;
     case QProcess::WriteError:
       QMessageBox::information(0,"Timedout","Timedout");
       break;
     case QProcess::ReadError:
       QMessageBox::information(0,"ReadError","ReadError");
       break;
     case QProcess::UnknownError:
       QMessageBox::information(0,"UnknownError","UnknownError");
       break;
     default:
       QMessageBox::information(0,"default","default");
       break;
    }
}
