#include "content_widget.h"

Content_Widget::Content_Widget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedWidth(900);
     message = new Message;
     right = new QStackedWidget();
     stacked_widget = new QStackedWidget();
     contact_widget = new Contact_Widget();
     process = new QProcess();
     phone_info = new QLabel();
     result = new QLabel();
      screen = new QLabel();
     phone_music = new Phone_Music();
     all = new ShowAll();
     rightHome = new Right_Home_Widget();
     home = new QPushButton();
     phone_plus = new Phone_Plus();
     screenshot = new QPushButton("截图");
     screen_catch = new QPushButton("演示");
     refresh = new QPushButton("刷新");
 //    player = new Player;
    connect(all,SIGNAL(update_picture_number()),this,SLOT(update_picture_number()));
    connect(phone_music,SIGNAL(update_song_number(int)),this,SLOT(update_song_number(int)));
    main_splitter = new QSplitter();
    main_splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    main_splitter->setOrientation(Qt::Horizontal);
    main_splitter->setHandleWidth(1);
    home->setText("用户视图");
    home->setFont(QFont(PURISA,16,40,false));
    home->setFlat(true);
    home->setFixedSize(200,50);
//    home->setStyleSheet("border-radius:8px;");

    this->initleft();
    this->initmid();
    this->initright();

    main_splitter->addWidget(left);
    main_splitter->addWidget(mid);
    main_splitter->addWidget(right);

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(main_splitter);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);
    setLayout(main_layout);


}

void Content_Widget::initleft()
{
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText,QColor(130,130,130));

    left = new QWidget();
    left_label =new QLabel();
    left->setMinimumWidth(300);
    left->setMaximumWidth(300);
    left_label->setGeometry(0,0,300,410);
    left_label->setStyleSheet("background-color:#fff");
    left_label->setParent(left);


//    result->setFont(QFont(PURISA,10,60,false)); //set font
    result->setPalette(text_palette);//set palette


    process = new QProcess(this);//new a process to exec the script
    process->start("bash ./shell_script/get_phone_info/get_phone_info.sh");//run get_phone_info.sh
    process->waitForFinished(); //wait for this process finished
    QByteArray pinfo = process->readAllStandardOutput();//将脚本中获取的手机信息内容读出
    int ec = process->exitCode();
    if(!ec)//脚本执行完成后
    {
        phone_info->setText(pinfo);//将获取的手机信息填入label中
        process->close();//关闭外部程序
        delete process;
        process = 0;
    }

    if(phone_info->text() == "no\n")
    {

        detact_thread *detact = new detact_thread();
        detact->start();
        QPixmap screen_pixmap(":/picture/phone_pic/default");
        screen->setPixmap(screen_pixmap.scaled(120,120).scaled(120,120,Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        result->setText("您的手机未连接.\n 如有问题请点击帮助.");

        left_layout = new QVBoxLayout();
        left_layout->addWidget(screen,0,Qt::AlignCenter);
        left_layout->addWidget(result,0,Qt::AlignHCenter);

    }
    else
    {
         QPixmap screen_pixmap("./screen_img/currentscreen/currentscreen.png");
        screen->setPixmap(screen_pixmap.scaled(150, 250).scaled(150, 250,Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        screen->setStyleSheet("QLabel{border-image:url(:/picture/phone_picture/default.png)0 0 0 0;border-radius:1px;padding:26px 8px;}");
                phone_battery_pro = new QProcess(this);//new a process to exec the script
                phone_battery_pro->start("bash ./shell_script/get_phone_info/get_phone_battery.sh");//run get_phone_info.sh
                phone_battery_pro->waitForFinished(); //wait for this process finished
                QByteArray phonebattery = phone_battery_pro->readAllStandardOutput();//将脚本中获取的手机信息内容读出
                phonebattery.replace('\n', '0');
                int ec1 = phone_battery_pro->exitCode();
                if(!ec1)//脚本执行完成后
                {
                    phone_battery_num = phonebattery.toInt();
                    phone_battery_num /= 10;
                    phone_battery_pro->close();//关闭外部程序
                    delete phone_battery_pro;
                    phone_battery_pro = 0;
                }

                phone_rom_pro = new QProcess(this);//new a process to exec the script
                phone_rom_pro->start("bash ./shell_script/get_phone_info/get_sdcard0_rom.sh");//run get_phone_info.sh
                phone_rom_pro->waitForFinished(); //wait for this process finished
                QByteArray phonerom = phone_rom_pro->readAllStandardOutput();//将脚本中获取的手机信息内容读出
                 phonerom.replace('\n', '0');
                int ec2 = phone_rom_pro->exitCode();
                if(!ec2)//脚本执行完成后
                {
                    phone_rom_num = phonerom.toDouble();
                    phone_rom_pro->close();//关闭外部程序
                    delete phone_rom_pro;
                    phone_rom_pro = 0;
                }

                sdcard_rom_pro = new QProcess(this);//new a process to exec the script
                sdcard_rom_pro->start("bash ./shell_script/get_phone_info/get_sdcard1_rom.sh");//run get_phone_info.sh
                sdcard_rom_pro->waitForFinished(); //wait for this process finished
                QByteArray sdcardrom = sdcard_rom_pro->readAllStandardOutput();//将脚本中获取的手机信息内容读出
                 sdcardrom.replace('\n', '0');
                int ec3 = sdcard_rom_pro->exitCode();
                if(!ec3)//脚本执行完成后
                {
                    sdcard_rom_num = sdcardrom.toDouble();
                    sdcard_rom_pro->close();//关闭外部程序
                    delete sdcard_rom_pro;
                    sdcard_rom_pro = 0;
                }



        result->setText(phone_info->text());

        phone_rom_bar = new QProgressBar;
        phone_rom_bar->setRange(0,100);
        phone_rom_bar->setValue(0);
        phone_rom_bar->setFixedSize(120,13);
        phone_rom_bar->setStyleSheet("QProgressBar{  color : solid gray;  border: 1px solid gray;  border-radius: 5px;  background: transparent;  padding: 0px;  text-align : center ;  }  QProgressBar::chunk{  background: #7CCD7C;  }  ");
        phone_rom = new QLabel;
        QPixmap phone_pixmap;
        phone_pixmap.load(":/picture/phone_pic/phone_rom.png");
        phone_rom->setScaledContents(true);
        phone_rom->setPixmap(phone_pixmap);
        phone_rom->setFixedSize(phone_pixmap.width(),phone_pixmap.height());

        sdcard_rom_bar = new QProgressBar;
        sdcard_rom_bar->setRange(0,100);
        sdcard_rom_bar->setValue(0);
        sdcard_rom_bar->setFixedSize(120,13);
        sdcard_rom_bar->setStyleSheet("QProgressBar{  color : solid gray;  border: 1px solid gray;  border-radius: 5px;  background: transparent;  padding: 0px;  text-align : center ;  }  QProgressBar::chunk{  background: #7CCD7C;  }  ");
        sdcard_rom = new QLabel;
        phone_pixmap.load(":/picture/phone_pic/sdcard_rom.png");
        sdcard_rom->setScaledContents(true);
        sdcard_rom->setPixmap(phone_pixmap);
        sdcard_rom->setFixedSize(phone_pixmap.width(),phone_pixmap.height());

        phone_battery_bar = new QProgressBar;
        phone_battery_bar->setRange(0,100);
        phone_battery_bar->setValue(0);
        phone_battery_bar->setFixedSize(120,13);
        phone_battery_bar->setStyleSheet("QProgressBar{  color : solid gray;  border: 1px solid gray;  border-radius: 5px;  background: transparent;  padding: 0px;  text-align : center ;  }  QProgressBar::chunk{  background: #7CCD7C;  }  ");
        phone_battery = new QLabel;
        phone_pixmap.load(":/picture/phone_pic/phone_battery.png");
        phone_battery->setScaledContents(true);
        phone_battery->setPixmap(phone_pixmap);
        phone_battery->setFixedSize(phone_pixmap.width(),phone_pixmap.height());


         if(phone_battery_num)
        {
             phone_battery_bar->setValue(phone_battery_num);
         }
         if(phone_rom_num)
        {
             phone_rom_bar->setValue(phone_rom_num);
         }
         if(sdcard_rom_num)
        {
             sdcard_rom_bar->setValue(sdcard_rom_num);
         }

        QGridLayout *g = new QGridLayout;
        g->addWidget(phone_rom,0,0);
        g->addWidget(phone_rom_bar,0,1);
        g->addWidget(sdcard_rom,1,0);
        g->addWidget(sdcard_rom_bar,1,1);
        g->addWidget(phone_battery,2,0);
        g->addWidget(phone_battery_bar,2,1);


        left_layout = new QVBoxLayout();
        left_layout->addWidget(screen,0,Qt::AlignHCenter);
        left_layout->addWidget(result,0,Qt::AlignHCenter);
        left_layout->addLayout(g,Qt::AlignHCenter);
        left_layout->addStretch();
    }


    if(phone_info->text() == "no\n")
    {
        left_layout->setContentsMargins(0,60,0,60);

    }
    else
    {
        left_layout->setContentsMargins(0,10,0,0);

    }
    left->setLayout(left_layout);
}

void Content_Widget::initmid()
{

    QPalette button_text_palette = palette();
    button_text_palette.setColor(QPalette::ButtonText, QColor(70, 70, 70));
    QPalette button_text_palette_disable = palette();
    button_text_palette_disable.setColor(QPalette::ButtonText, QColor(130, 130, 130));


    screenshot->setFont(QFont(URW_G_FONT,12,9,false));
    screen_catch->setFont(QFont(URW_G_FONT,12,9,false));
    refresh->setFont(QFont(URW_G_FONT,12,9,false));

//    screenshot->setStyleSheet("border-radius:8px");
//    screen_catch->setStyleSheet("border-radius:8px");
//    refresh->setStyleSheet("border-radius:8px");

    screenshot->setGeometry(0,0,60,48);
    screen_catch->setGeometry(0,0,60,48);
    refresh->setGeometry(0,0,60,48);
    screenshot->clearMask();
    refresh->clearMask();
    screen_catch->clearMask();
    screenshot->setFlat(true);
    screen_catch->setFlat(true);
    refresh->setFlat(true);
    refresh->setPalette(button_text_palette);

    if(phone_info->text()=="no\n")
    {
        screen_catch->setPalette(button_text_palette_disable);
        screenshot->setPalette(button_text_palette_disable);

        screenshot->setDisabled(true);
        screen_catch->setDisabled(true);

    }

    else
    {
        screen_catch->setPalette(button_text_palette);
        screenshot->setPalette(button_text_palette);

        screenshot->setDisabled(false);
        screen_catch->setDisabled(false);
    }


    mid = new QWidget();

    mid->setMinimumWidth(310);
    mid->setMaximumWidth(310);
    mid_label = new QLabel();
    mid_label->setGeometry(0,0,300,410);
    mid_label->setStyleSheet("background-color:#fff");
    mid_label->setParent(mid);


    QStringList string_list;
    string_list<<":/picture/tools/contacts"<<":/picture/tools/phonepicture"<<":/picture/tools/phonemusic"<<":/picture/tools/message";

    QGridLayout *button_layout_pre = new QGridLayout();

    QSignalMapper *signal_mapper = new QSignalMapper(this);
    for(int i=0; i<string_list.size(); i++)
    {
        Tool_Button *tool_button = new Tool_Button(string_list.at(i));

        btnlist.append(tool_button);
        connect(tool_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(tool_button, QString::number(i, 10));

        button_layout_pre->addWidget(tool_button,i/2,i%2,1,1);
    }
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(turnPage(QString)));
    button_layout_pre->setContentsMargins(0,0,0,0);
  //  button_layout_pre->setColumnStretch(6,1);






    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(refresh);
    button_layout->addWidget(screen_catch);
    button_layout->addWidget(screenshot);
    button_layout->addStretch();
    button_layout->setSpacing(0);
    button_layout->setContentsMargins(0, 0, 0, 0);
    QVBoxLayout *mid_layout = new QVBoxLayout();
 //   mid_layout->addWidget(phone);
    mid_layout->addWidget(home,0,Qt::AlignHCenter);
    mid_layout->addLayout(button_layout_pre);
    mid_layout->addLayout(button_layout);
    mid_layout->setSpacing(0);
    mid_layout->setContentsMargins(0, 0, 0, 0);

    this->setbtntext();

    connect(home,SIGNAL(clicked()),this,SLOT(turnHome()));
    connect(refresh,SIGNAL(clicked()),this,SLOT(refresh_screen()));
    connect(screenshot,SIGNAL(clicked()),this,SLOT(shot_screen()));
    connect(screen_catch,SIGNAL(clicked()),this,SLOT(catch_screen()));

    mid->setLayout(mid_layout);

}

void Content_Widget::initright()
{
//    right = new QStackedWidget();
    right->setMaximumWidth(500);
    right->setMinimumWidth(290);
//    right_label = new QLabel(right);
//    right_label->setGeometry(0,0,300,600);
//    right_label->setStyleSheet("background-color:#fff");
//    right_app = new QPushButton("Here is");

//    right_app->setStyleSheet("background-color:#f00");
//    right_app->setFlat(true);
//    right_layout = new QVBoxLayout();
//    right_layout->addWidget(right_app);
//   right->setLayout(right_layout);
   right->addWidget(contact_widget);
   right->addWidget(all);
   right->addWidget(phone_music);
   right->addWidget(message);
   right->addWidget(rightHome);
   right->setCurrentIndex(4);
}

void Content_Widget::shot_screen()
{

    pro1 = new QProcess();
    pro1->start("./shell_script/screen_shot/screen_shot.sh");
    pro1->waitForFinished();
 //   QByteArray pinfo = pro1->readAllStandardOutput();//将脚本中获取的手机信息内容读出
    int ec = pro1->exitCode();
    if(!ec)//脚本执行完成后
    {

        QMessageBox::information(NULL, "success", "截图成功!");//弹出截图成功提示框
        pro1->close();//关闭外部程序
        delete pro1;
        pro1 = 0;
    }

}

void Content_Widget::refresh_screen()
{

    QPalette button_text_palette2 = palette();
    button_text_palette2.setColor(QPalette::ButtonText, QColor(70, 70, 70));
    pro2 = new QProcess();
    pro2->start("bash ./shell_script/get_phone_info/get_phone_info.sh");//run get_phone_info.sh
    pro2->waitForFinished(); //wait for this process finished
    QByteArray pinfo2 = pro2->readAllStandardOutput();//将脚本中获取的手机信息内容读出
    int ec2 = pro2->exitCode();
    if(!ec2)//脚本执行完成后
    {
        phone_info->setText(pinfo2);//将获取的手机信息填入label中
        pro2->close();//关闭外部程序
        delete pro2;
        pro2 = 0;
    }
    if(phone_info->text() == "no\n")
    {
        clearLayout(left_layout);
        QPalette button_text_palette_disable2 = palette();
        button_text_palette_disable2.setColor(QPalette::ButtonText, QColor(130, 130, 130));
        QPalette text_palette = palette();
        text_palette.setColor(QPalette::ButtonText, QColor(130, 130, 130));
        QPixmap screen_pixmap2(":/picture/phone_pic/default");
        screen = new QLabel();
        result = new QLabel();
        screen->setPixmap(screen_pixmap2.scaled(120,120).scaled(120,120,Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

        result->setText(" 您的手机未连接.\n 如有问题请点击帮助.");
        result->setFont(QFont("黑体",12,0,false)); //set font
        result->setPalette(text_palette);//set palette
        left_layout->addWidget(screen,0,Qt::AlignCenter);
        left_layout->addWidget(result,0,Qt::AlignHCenter);

        screenshot->setDisabled(true);
        screen_catch->setDisabled(true);
        screen_catch->setPalette(button_text_palette_disable2);
        screenshot->setPalette(button_text_palette_disable2);


    }
    else
    {
   //     screen->setGeometry(QRect(5, 5, 5, 5));//手机屏幕的图片放置在phone_img这个label上
//         QPixmap screen_pixmap2("./screen_img/currentscreen/currentscreen.png");

        clearLayout(left_layout);

         screenshot->setDisabled(false);
         screen_catch->setDisabled(false);
         screen_catch->setPalette(button_text_palette2);
         screenshot->setPalette(button_text_palette2);
         screen = new QLabel();
         result = new QLabel();
            emit fresh();
         QPixmap screen_pixmap("./screen_img/currentscreen/currentscreen.png");
        screen->setPixmap(screen_pixmap.scaled(150, 250).scaled(150, 250,Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        screen->setStyleSheet("QLabel{border-image:url(:/picture/phone_picture/default.png)0 0 0 0;border-radius:1px;padding:26px 8px;}");
//        result->setFont(QFont(PURISA,10,50,false));
        phone_battery_pro = new QProcess(this);//new a process to exec the script
                phone_battery_pro->start("bash ./shell_script/get_phone_info/get_phone_battery.sh");//run get_phone_info.sh
                phone_battery_pro->waitForFinished(); //wait for this process finished
                QByteArray phonebattery = phone_battery_pro->readAllStandardOutput();//将脚本中获取的手机信息内容读出
                phonebattery.replace('\n', '0');
                int ec1 = phone_battery_pro->exitCode();
                if(!ec1)//脚本执行完成后
                {
                    phone_battery_num = phonebattery.toInt();
                    phone_battery_num /= 10;
                    phone_battery_pro->close();//关闭外部程序
                    delete phone_battery_pro;
                    phone_battery_pro = 0;
                }

                phone_rom_pro = new QProcess(this);//new a process to exec the script
                phone_rom_pro->start("bash ./shell_script/get_phone_info/get_sdcard0_rom.sh");//run get_phone_info.sh
                phone_rom_pro->waitForFinished(); //wait for this process finished
                QByteArray phonerom = phone_rom_pro->readAllStandardOutput();//将脚本中获取的手机信息内容读出
                 phonerom.replace('\n', '0');
                int ec2 = phone_rom_pro->exitCode();
                if(!ec2)//脚本执行完成后
                {
                    phone_rom_num = phonerom.toDouble();
                    phone_rom_pro->close();//关闭外部程序
                    delete phone_rom_pro;
                    phone_rom_pro = 0;
                }

                sdcard_rom_pro = new QProcess(this);//new a process to exec the script
                sdcard_rom_pro->start("bash ./shell_script/get_phone_info/get_sdcard1_rom.sh");//run get_phone_info.sh
                sdcard_rom_pro->waitForFinished(); //wait for this process finished
                QByteArray sdcardrom = sdcard_rom_pro->readAllStandardOutput();//将脚本中获取的手机信息内容读出
                 sdcardrom.replace('\n', '0');
                int ec3 = sdcard_rom_pro->exitCode();
                if(!ec3)//脚本执行完成后
                {
                    sdcard_rom_num = sdcardrom.toDouble();
                    sdcard_rom_pro->close();//关闭外部程序
                    delete sdcard_rom_pro;
                    sdcard_rom_pro = 0;
                }



        result->setText(phone_info->text());

        phone_rom_bar = new QProgressBar;
        phone_rom_bar->setRange(0,100);
        phone_rom_bar->setValue(0);
        phone_rom_bar->setFixedSize(120,13);
        phone_rom_bar->setStyleSheet("QProgressBar{  color : solid gray;  border: 1px solid gray;  border-radius: 5px;  background: transparent;  padding: 0px;  text-align : center ;  }  QProgressBar::chunk{  background: #7CCD7C;  }  ");
        phone_rom = new QLabel;
        QPixmap phone_pixmap;
        phone_pixmap.load(":/picture/phone_pic/phone_rom.png");
        phone_rom->setScaledContents(true);
        phone_rom->setPixmap(phone_pixmap);
        phone_rom->setFixedSize(phone_pixmap.width(),phone_pixmap.height());

        sdcard_rom_bar = new QProgressBar;
        sdcard_rom_bar->setRange(0,100);
        sdcard_rom_bar->setValue(0);
        sdcard_rom_bar->setFixedSize(120,13);
        sdcard_rom_bar->setStyleSheet("QProgressBar{  color : solid gray;  border: 1px solid gray;  border-radius: 5px;  background: transparent;  padding: 0px;  text-align : center ;  }  QProgressBar::chunk{  background: #7CCD7C;  }  ");
        sdcard_rom = new QLabel;
        phone_pixmap.load(":/picture/phone_pic/sdcard_rom.png");
        sdcard_rom->setScaledContents(true);
        sdcard_rom->setPixmap(phone_pixmap);
        sdcard_rom->setFixedSize(phone_pixmap.width(),phone_pixmap.height());

        phone_battery_bar = new QProgressBar;
        phone_battery_bar->setRange(0,100);
        phone_battery_bar->setValue(0);
        phone_battery_bar->setFixedSize(120,13);
        phone_battery_bar->setStyleSheet("QProgressBar{  color : solid gray;  border: 1px solid gray;  border-radius: 5px;  background: transparent;  padding: 0px;  text-align : center ;  }  QProgressBar::chunk{  background: #7CCD7C;  }  ");
        phone_battery = new QLabel;
        phone_pixmap.load(":/picture/phone_pic/phone_battery.png");
        phone_battery->setScaledContents(true);
        phone_battery->setPixmap(phone_pixmap);
        phone_battery->setFixedSize(phone_pixmap.width(),phone_pixmap.height());


         if(phone_battery_num)
        {
             phone_battery_bar->setValue(phone_battery_num);
         }
         if(phone_rom_num)
        {
             phone_rom_bar->setValue(phone_rom_num);
         }
         if(sdcard_rom_num)
        {
             sdcard_rom_bar->setValue(sdcard_rom_num);
         }

        QGridLayout *g = new QGridLayout;
        g->addWidget(phone_rom,0,0);
        g->addWidget(phone_rom_bar,0,1);
        g->addWidget(sdcard_rom,1,0);
        g->addWidget(sdcard_rom_bar,1,1);
        g->addWidget(phone_battery,2,0);
        g->addWidget(phone_battery_bar,2,1);



        left_layout->addWidget(screen,0,Qt::AlignHCenter);
        left_layout->addWidget(result,0,Qt::AlignHCenter);
        left_layout->addLayout(g,Qt::AlignHCenter);
        left_layout->addStretch();
    }

    if(phone_info->text() == "no\n")
    {
        left_layout->setContentsMargins(0,60,0,60);

    }
    else
    {
        left_layout->setContentsMargins(0,10,0,0);

    }
}

void Content_Widget::catch_screen()
{
    screen_catch->setDisabled(true);
    phone_show = new Phoneshow();
    phone_show->show();
    phone_show->resize(200,400);
    phone_show->move(550,100);
    connect(phone_show,SIGNAL(phone_exit()),this,SLOT(show_recovery()));
}
void Content_Widget::show_recovery()
{
    screen_catch->setDisabled(false);
}

void Content_Widget::turnHome()
{
    for(int i=0;i<btnlist.count();i++)
    {
        Tool_Button *tool_button = btnlist.at(i);
         tool_button->setMousePress(false);
    }
    right->setCurrentIndex(4);
}

void Content_Widget::turnPage(QString current_page)
{
    bool ok;
    int current_index = current_page.toInt(&ok, 10);

    for(int i=0; i<btnlist.count(); i++)
    {
        Tool_Button *tool_button = btnlist.at(i);
        if(current_index == i)
        {
            tool_button->setMousePress(true);
            right->setCurrentIndex(i);
        }
        else
        {
            tool_button->setMousePress(false);
        }
    }


    qDebug() << current_page;
    //emit turnPage();
}

void Content_Widget::setbtntext()
{
    QString string;
    string = "联系人("+QString::number(contact_widget->lineNum+1,10)+")";
    btnlist.at(0)->setText(string);
    string = "图片("+QString::number(all->picture_num,10)+")";
    btnlist.at(1)->setText(string);


    string = "音乐("+QString::number(phone_music->song_number,10)+")";
    btnlist.at(2)->setText(string);
    string = "短信("+QString::number(message->message_num,10)+")";
    btnlist.at(3)->setText(string);
}

void Content_Widget::update_picture_number()
{
    QString string;
    string = "图片("+QString::number(all->picture_num,10)+")";
    btnlist.at(1)->setText(string);
}
void Content_Widget::update_song_number(int song_number)
{
    QString string;
    string = "音乐("+QString::number(song_number,10)+")";
    btnlist.at(2)->setText(string);
}

void Content_Widget::pro_fin(int ec)
{

}


void Content_Widget::clearLayout(QLayout* layout)
{
//    qDebug() << "clear layout";
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (QWidget* widget = item->widget())
                delete widget;

        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout);
        delete item;
    }
}
