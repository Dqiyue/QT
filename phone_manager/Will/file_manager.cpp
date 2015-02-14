#include "file_manager.h"

File_Manager::File_Manager(QWidget *parent) :
    QWidget(parent)
{

    QPalette text_palette = palette();
    text_palette.setColor(QPalette::ButtonText, QColor(255,140,0 ));
    QPalette palette_lab = palette();
    palette_lab.setColor(QPalette::WindowText, QColor(255,140,0 ));

    QPalette message_palette = palette();
    message_palette.setColor(QPalette::WindowText, QColor(220,20,60 ));
    is_selected = false;
    file_list_widget = new QWidget();
    scroll = new QScrollArea(this);
     scroll->setWidgetResizable(true);
    list_layout = new QVBoxLayout();

    dir_label = new QLabel("Phone:");
    dir_label->setFont(QFont(PURISA,16,60,false));
    dir_label->setPalette(palette_lab);
    dir_now = "/";

     main_label = new QLabel("Let's work together, to make the files become orderly^");
     main_label->setFont(QFont(PURISA,20,60,false));
     main_label->setPalette(palette_lab);
     main_layout = new  QVBoxLayout();

    show_file = new QPushButton("Explore phone");
    show_file->setFlat(true);
    show_file->setPalette(text_palette);
    show_file->setFont(QFont(PURISA,16,60,false));

    openfile = new QPushButton("Open local file");
    openfile->setFlat(true);
    openfile->setPalette(text_palette);
    openfile->setFont(QFont(PURISA,16,60,false));
    message = new QLabel("hello");
    message->setFont(QFont(PURISA,10,60,false));
    message->setPalette(message_palette);

    push = new QPushButton();
    push->setFlat(true);
    push->setPalette(text_palette);
    push->setFont(QFont(PURISA,16,60,false));
    push->setDisabled(true);

    goback = new QPushButton("<back");
    goback->setFlat(true);
    goback->setPalette(text_palette);
    goback->setFont(QFont(PURISA,16,60,false));
    goback->setDisabled(true);

    file_list_widget->setLayout(list_layout);
    main_btn_layout = new QHBoxLayout();
    push_layout = new QHBoxLayout();

    scroll->setWidget(file_list_widget);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setFixedWidth(900-2*SHADOW_WIDTH);
    scroll->setFrameStyle(QFrame::NoFrame);

    main_btn_layout->addWidget(show_file);
    main_btn_layout->addWidget(openfile);

    push_layout->addWidget(goback);
    push_layout->addWidget(push);
    push_layout->addWidget(message);

    main_layout->addWidget(main_label);
    main_layout->addLayout(main_btn_layout);
    main_layout->addWidget(dir_label,0,Qt::AlignLeft);
//    main_layout->addWidget(file_list_widget);
    main_layout->addWidget(scroll);
    main_layout->addLayout(push_layout);
//    main_layout->addWidget(pull);
    connect(goback,SIGNAL(clicked()),this,SLOT(get_back_to_last_dir()));
    connect(openfile,SIGNAL(clicked()),this,SLOT(open_file()));
    connect(show_file,SIGNAL(clicked()),this,SLOT(get_file()));
    connect(push,SIGNAL(clicked()),this,SLOT(pull_file()));


    setLayout(main_layout);
}


void File_Manager::open_file()
{
    fileinfo_list.clear();
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"));
    addToFilelist(fileNames);
}

void File_Manager::addToFilelist(const QStringList &fileNames)
{
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::ButtonText, QColor(205,92,92 ));
    QPalette palette_lab = palette();
    palette_lab.setColor(QPalette::WindowText, QColor(0,0,0 ));

    clearLayout(list_layout);
    QSignalMapper *signal_mapper_h = new QSignalMapper(this);
    file_selected = "";
    for(int i=0;i<fileNames.size();i++) {

        QFileInfo fileInfo(fileNames.at(i));
        if (fileInfo.exists()) {
            fileinfo_list.append(fileInfo);
                file_selected.append(fileInfo.fileName()+" ");
                is_selected = true;
            QHBoxLayout *layout = new QHBoxLayout();
            QLabel *label = new QLabel(fileInfo.fileName());
            QPushButton *del = new QPushButton("Not This ?");
            del->setPalette(text_palette);
            del->setFont(QFont(PURISA,12,50,false));
            del->setFlat(true);
            label->setPalette(palette_lab);
            label->setFont(QFont(PURISA,14,50,false));

            connect(del, SIGNAL(clicked()), signal_mapper_h, SLOT(map()));
            signal_mapper_h->setMapping(del, QString::number(i, 10));

            layout->addWidget(label);
            layout->addWidget(del);
            list_layout->addLayout(layout);

        }

    }
    connect(signal_mapper_h, SIGNAL(mapped(QString)), this, SLOT(del_file(QString)));
    if(fileNames.size()>0){
        push->setText("push");
        push->setDisabled(false);
        message->setText("copy "+file_selected+"to "+dir_now+" ?");
    }

}

void File_Manager::pull_file()
{


    pro_number = 0;
    failed = 0;
    success = 0;
    push->setDisabled(true);
    message->setText("pushing...");
    is_selected = false;
    file_selected = "";
    foreach (QFileInfo fileInfo, fileinfo_list) {
        pro_number++;
        QString s;
        s = "adb push "+fileInfo.absoluteFilePath()+" "+dir_now;
        qDebug()<<s;
        QProcess *process = new QProcess();
        process->start(s);
        connect(process,SIGNAL(finished(int)),this,SLOT(pro_fin(int)));

    }

//    qDebug() <<s;

    fileinfo_list.clear();

}

void File_Manager::pro_fin(int ec)
{
    qDebug()<<"hahahaahhaha";
    pro_number--;
    if(!ec){
        success++;

    }
    else{
        failed++;
    }
    if(pro_number==0){
        push->setText("");
        message->setText("push over, "+QString::number(success,10)+" success, "+QString::number(failed,10)+" failed, "+QString::number(success*100/(success+failed),10)+"% succeeded.");
    }
    pro2 = new QProcess();
    QString string = "adb shell ls -F "+dir_now;
    pro2->start(string);
    connect(pro2,SIGNAL(finished(int)),this,SLOT(get_pro_fin_three(int)));
}

void File_Manager::get_file()
{
//    fileinfo_list.clear();
    clearLayout(list_layout);
//    push->setDisabled(true);
//    push->setText("Maintain Efforts");
    if(is_selected == true){
        message->setText("copy "+file_selected+"to "+dir_now+" ?");
    }
    else{
         message->setText("opening...");
    }
    pro = new QProcess();
    pro->start("adb shell ls -F");
    dir_now = "/";

    connect(pro,SIGNAL(finished(int)),this,SLOT(get_pro_fin(int)));

}

void File_Manager::get_pro_fin(int ec)
{

    QByteArray pinfo = pro->readAllStandardOutput();
    QString string = pinfo;
      qDebug()<<"string length:"+QString::number(string.length(),10);
      qDebug()<<string.mid(0,12);
    if(string==""){
        qDebug()<<"its NULL";
        clearLayout(list_layout);
    }
    else if(string.mid(0,12)=="opendir fail"){
         dir_label->setText("phone:"+dir_now);
        qDebug()<<"yes";
        QLabel *bad_label= new QLabel(string);
        bad_label->setFont(QFont(PURISA,20,50,false));
        bad_label->setAlignment(Qt::AlignCenter);
        clearLayout(list_layout);
        list_layout->addWidget(bad_label);
    }
    else{
        update(string);
    }
    if(!ec)
    {
        pro->close();
//        message->setText("have a look ~");
//        push->setText("");
    }
    else{
        pro->close();
        message->setText("get file failed ~~");
//        push->setText("");
    }
}

void File_Manager::get_pro_fin_two(int ec)
{
    QByteArray pinfo = pro1->readAllStandardOutput();
    QString string = pinfo;
      qDebug()<<"string length:"+QString::number(string.length(),10);
            qDebug()<<string.mid(0,12);
    if(string==""){
        qDebug()<<"its NULL";
        clearLayout(list_layout);
    }
    else if(string.mid(0,12)=="opendir fail"){
         dir_label->setText("phone:"+dir_now);
         qDebug()<<"yes";
        QLabel *bad_label= new QLabel(string);
        bad_label->setFont(QFont(PURISA,20,50,false));
        bad_label->setAlignment(Qt::AlignCenter);
        clearLayout(list_layout);
        list_layout->addWidget(bad_label);
    }
    else{
        update(string);
    }
    if(!ec)
    {
        pro1->close();
//        message->setText("have a look ~");
//        push->setText("");
    }
    else{
        pro1->close();
        message->setText("get file failed ~~");
//        push->setText("");
    }
}

void File_Manager::get_pro_fin_three(int ec)
{
    QByteArray pinfo = pro2->readAllStandardOutput();
    QString string = pinfo;
      qDebug()<<"string length:"+QString::number(string.length(),10);
            qDebug()<<string.mid(0,12);
    if(string==""){
        qDebug()<<"its NULL";
        clearLayout(list_layout);
    }
    else if(string.mid(0,12)=="opendir fail"){
         dir_label->setText("phone:"+dir_now);
         qDebug()<<"yes";
        QLabel *bad_label= new QLabel(string);
        bad_label->setFont(QFont(PURISA,20,50,false));
        bad_label->setAlignment(Qt::AlignCenter);
        clearLayout(list_layout);
        list_layout->addWidget(bad_label);
    }
    else{
        update(string);
    }
    if(!ec)
    {
        pro2->close();
//        message->setText("have a look ~");
//        push->setText("");
    }
    else{
        pro2->close();
        message->setText("get file failed ~~");
//        push->setText("");
    }
}
void File_Manager::get_pro_fin_four(int ec)
{
    QByteArray pinfo = pro3->readAllStandardOutput();
    QString string = pinfo;
    qDebug()<<"string length:"+QString::number(string.length(),10);
          qDebug()<<string.mid(0,12);
    if(string==""){
        qDebug()<<"its NULL";
        clearLayout(list_layout);
    }
    else if(string.mid(0,12)=="opendir fail"){
         qDebug()<<"yes";
         dir_label->setText("phone:"+dir_now);
        QLabel *bad_label= new QLabel(string);
        bad_label->setFont(QFont(PURISA,20,50,false));
        bad_label->setAlignment(Qt::AlignCenter);
        clearLayout(list_layout);
        list_layout->addWidget(bad_label);
    }
    else{
        update(string);
    }
    if(!ec)
    {
        pro3->close();
//        message->setText("have a look ~");
//        push->setText("");
    }
    else{
        pro3->close();
        message->setText("get file failed ~~");
//        push->setText("");
    }
}

void File_Manager::update(QString dir)
{
    clearLayout(list_layout);

    dir_label->setText("phone:"+dir_now);
    if(is_selected == true){
        message->setText("copy "+file_selected+"to "+dir_now+" ?");
    }
    else{
         message->setText("have a look~");
    }

        QStringList filelist;
        filelist = dir.split("\n");
        QGridLayout *grid = new QGridLayout();
        QSignalMapper *signal_mapper = new QSignalMapper(this);
        QSignalMapper *signal_mapper_del = new QSignalMapper(this);
        QSignalMapper *signal_mapper_get = new QSignalMapper(this);
        for(int i=0; i<filelist.size(); i++)
        {
            if(filelist.at(i)==""){
                    qDebug()<<"remove NULL";
            }
            else{
                QString name;
                QString realname;
                name = filelist.at(i).mid(0,filelist.at(i).length()-1);
                if(name.at(1)==' ')
                    realname = name.mid(2,name.length()-1);
                else
                    realname = name.mid(3,name.length()-1);
                qDebug()<<"the real name :"+realname;
                QLabel *name_label = new QLabel(name.mid(2,name.length()-1));
                name_label->setAlignment(Qt::AlignHCenter);
                QVBoxLayout *vlayout = new QVBoxLayout();
                QHBoxLayout *hlayout = new QHBoxLayout();
                QPushButton *tool_button = new QPushButton();
                tool_button->setFlat(true);
                QPushButton *del = new QPushButton();
                del->setIcon(QIcon(":/picture/player/delete4"));
                del->setFlat(true);
                QPushButton *get = new QPushButton();
                get->setIcon(QIcon(":/picture/player/out3"));
                get->setFlat(true);
               //_____________________set icon____________________

                if(name.at(0)=='d'){
                    tool_button->setIcon(QIcon(":/picture/fileType/dir"));
                }
                else if(name.at(0)=='l'){
                    tool_button->setIcon(QIcon(":/picture/fileType/link"));
                    tool_button->setDisabled(true);
                }
                else if(name.at(0)=='-'||name.at(0)=='b'||name.at(0)=='c'||name.at(0)=='p'||name.at(0)=='s'){
                    tool_button->setIcon(QIcon(":/picture/fileType/file"));
                    tool_button->setDisabled(true);
                }
                tool_button->setIconSize(QSize(80,60));



                connect(del, SIGNAL(clicked()), signal_mapper_del, SLOT(map()));
                connect(get, SIGNAL(clicked()), signal_mapper_get, SLOT(map()));
                signal_mapper_del->setMapping(del,realname);
                signal_mapper_get->setMapping(get,realname);
                del->setToolTip("delete this file");
                get->setToolTip("copy this file to PC");

                connect(tool_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
                signal_mapper->setMapping(tool_button,realname);
                hlayout->addWidget(del);
                hlayout->addWidget(get);
                vlayout->addWidget(tool_button);
                vlayout->addWidget(name_label);
                vlayout->addLayout(hlayout);
                qDebug()<<"its ok";
                grid->addLayout(vlayout,i/3,i%3,1,1,Qt::AlignCenter);
            }
        }
        connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(cdDir(QString)));
        connect(signal_mapper_del, SIGNAL(mapped(QString)), this, SLOT(del_phone_file(QString)));
        connect(signal_mapper_get,SIGNAL(mapped(QString)),this,SLOT(copy_file_to_pc(QString)));
        list_layout->addLayout(grid);
        qDebug()<<"well its all ok";


}

void File_Manager::cdDir(QString dir)
{
     dir_now = dir_now+dir+"/";
    QString string = "adb shell ls -F "+dir_now ;
    qDebug()<<string;
    goback->setDisabled(false);
    pro = new QProcess();
    pro->start(string);
    connect(pro,SIGNAL(finished(int)),this,SLOT(get_pro_fin(int)));
}

void File_Manager::del_phone_file(QString name)
{
    pro1 = new QProcess();
    QString string = "adb shell rm "+dir_now+name;
    pro1->start(string);
    connect(pro1,SIGNAL(finished(int)),this,SLOT(resume_layout(int)));
}

void File_Manager::copy_file_to_pc(QString name)
{
    pro2 = new QProcess();
     QString aim_dir = QFileDialog::getExistingDirectory(this,tr("choose dir"));
     QString string = "adb pull "+dir_now+name+" "+aim_dir;
     pro2->start(string);
     connect(pro2,SIGNAL(finished(int)),this,SLOT(resume_layout_two(int)));
}

void File_Manager::resume_layout_two(int ec)
{
    if(!ec){
        message->setText("success!");
        pro2->close();
    }
    else{
        message->setText("failed!");
        pro2->close();
    }
    QString string = "adb shell ls -F "+dir_now ;
    pro2 = new QProcess();
    pro2->start(string);
    connect(pro2,SIGNAL(finished(int)),this,SLOT(get_pro_fin_three(int)));
}

void File_Manager::resume_layout(int ec)
{
    if(!ec){
        message->setText("success!");
        pro1->close();
    }
    else{
        message->setText("failed!");
        pro1->close();
    }
    QString string = "adb shell ls -F "+dir_now ;
    pro1 = new QProcess();
    pro1->start(string);
    connect(pro1,SIGNAL(finished(int)),this,SLOT(get_pro_fin_two(int)));
}

void File_Manager::get_back_to_last_dir()
{
    pro3 = new QProcess();
    QString last_dir;
    int t = 0;
    for(int i=dir_now.length()-2;i>0;i--){
        if(dir_now.at(i)=='/'){
            t = i;
            i=0;
        }
    }
    if(t==0){
        goback->setDisabled(true);
    }
    last_dir = dir_now.mid(0,t+1);
    qDebug()<<"last_dir+"+last_dir;
    dir_now = last_dir;
    QString string = "adb shell ls -F "+last_dir;
    pro3->start(string);
    connect(pro3,SIGNAL(finished(int)),this,SLOT(get_pro_fin_four(int)));
}

void File_Manager::del_file(QString index)
{
    bool ok;
    int current = index.toInt(&ok,10);

    QStringList stringlist;
    QStringList filename_list;
    int i = 0;
    foreach (QFileInfo fileInfo, fileinfo_list) {
        if(i!=current){
            stringlist <<fileInfo.fileName();
            filename_list<<fileInfo.absoluteFilePath();
        }
        if(i == current)
            qDebug()<<fileInfo.fileName()+" is this ??";
        i++;
    }
    fileinfo_list.clear();
    file_selected = "";
    foreach (const QString &string, filename_list) {
        QFileInfo info(string);
        fileinfo_list.append(info);
        file_selected.append(info.fileName()+" ");
        qDebug()<<info.fileName();
    }
    clearLayout(list_layout);

    if(filename_list.size() == 0){
        push->setDisabled(true);
        push->setText("");
        message->setText("hello");
        is_selected = false;
        file_selected = "";
    }


    QPalette text_palette = palette();
    text_palette.setColor(QPalette::ButtonText, QColor(205,92,92 ));
    QPalette palette_lab = palette();
    palette_lab.setColor(QPalette::WindowText, QColor(0,0,0 ));


    QSignalMapper *signal_mapper = new QSignalMapper(this);
    for(int i=0;i<stringlist.size();i++) {
            QHBoxLayout *layout = new QHBoxLayout();
            QLabel *label = new QLabel(stringlist.at(i));
            QPushButton *del = new QPushButton("Not This ?");
            del->setPalette(text_palette);
            del->setFont(QFont(PURISA,12,50,false));
            del->setFlat(true);
            label->setPalette(palette_lab);
            label->setFont(QFont(PURISA,14,50,false));

            connect(del, SIGNAL(clicked()), signal_mapper, SLOT(map()));
            signal_mapper->setMapping(del, QString::number(i, 10));

            layout->addWidget(label);
            layout->addWidget(del);
            list_layout->addLayout(layout);
        }

     message->setText("copy "+file_selected+"to "+dir_now+" ?");
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(del_file(QString)));


}

void File_Manager::clearLayout(QLayout* layout)
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


