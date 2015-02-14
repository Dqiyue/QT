#include "app_manager.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"
#include "QToolButton"
#include "QWidget"
#include "QPalette"
#include "QPushButton"
#include "QGridLayout"
#include "QScrollArea"
#include "QThread"
#include <QPalette>
#include <usb_detact_connect.h>
App_Manager::App_Manager(QWidget *parent) :
    QWidget(parent)
{
    //最底层的组建,用于放各类组件
    //widget = new QWidget(this);
    /*--------------------需要修改为窗口形式---------------------------*/
    //this->setWindowTitle("app installed");
    /****************************************************************/
    id = 0;
    //label大小设置
    back_label=new QLabel(this);
    back_label->resize(900,450);
    back_label->setParent(this);
   // back_label->setText("hello");
  //  back_label->setStyleSheet("border:1px solid black");
//    QHBoxLayout *test = new QHBoxLayout;
//    test->addWidget(back_label);
//    this->setLayout(test);
    //设置窗体大小和位置
    //this->setCentralWidget(widget);
    this->setFixedSize(900,450);
    this->move(300,200);
    //设置滚动条区域vertical方向的需要时打开，水平方向的关闭
       scrollArea = new QScrollArea;
       scrollArea->setParent(this);
       scrollArea->setFixedSize(900,450);
      scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
      scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //创建解析app进程 执行小shell的进程
//    parse_app_process=new QProcess;
    do_minimal_shell=new QProcess;
    deleteappinfo =  new QProcess;
    start();
    //调用mainwindow的构造函数就执行该进程
//    process_excution();
    /*just for test*/
    //注册解析app进程信号和槽
//    connect(parse_app_process,SIGNAL(readyRead()),this,SLOT(readOutput()));
//    connect(parse_app_process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(do_others(int,QProcess::ExitStatus)));
//    connect(parse_app_process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(processError(QProcess::ProcessError)));
}

App_Manager::~App_Manager()
{
      delete parse_app_process;
      delete do_minimal_shell;
      delete deleteappinfo;
}
//解析脚本的执行
void App_Manager::process_excution(){
    //QString info= "bash usricontable.sh";
    qDebug() << "pull app info";
    QString info= "bash ./shell_script/app_info/judge.sh";
    parse_app_process->start(info);
}
//解析脚本时执行的槽函数
void App_Manager::readOutput(){
    QString output;
    output +=parse_app_process->readAll();
    qDebug() <<output;
    qDebug()<< "解析app完成";
}
//shell脚本执行出错的错误处理
//所有开发完成后尽量去掉
void App_Manager::processError(QProcess::ProcessError error){
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
//排列app图标
void App_Manager::arrange_appicon(){
    int size=app_num; //app的书目
    //网格包布局3*x，用于存放app信息
    gridLayout = new QGridLayout;
    //使用signalmapper，处理多按钮时间
    signal_mapper = new QSignalMapper(this);
    //排列布局
    for(int i=0;i<size;i++){
        QString part_path="./logo/";
    //图片路径，
        part_path.append(app_icon_path[i]);
        QPixmap pixmap(part_path);
       //app名字添加到label组件中
        QLabel *app_icon_name=new QLabel(""+app_icon_path[i]+"");
        QLabel *app_icon=new QLabel(this);
        //水平布局横向添加app图标，app名字，卸载按钮
        QHBoxLayout *app_layout=new QHBoxLayout;
        QVBoxLayout *temp = new QVBoxLayout;
        //设置app图标样式
        app_icon->setFixedSize(70,70);
        app_icon_name->setFixedSize(110,28);
        app_icon_name->setScaledContents(true);
        app_icon->setScaledContents(true);
        app_icon->setPixmap(pixmap);
        //app_icon_name->setStyleSheet("border:1px solid black");
        //设置卸载按钮样式
        QPalette button_text_palette;
        button_text_palette.setColor(QPalette::ButtonText,QColor(220,20,60));
        uninstall_button[i] = new QPushButton("卸载");//string_list
        uninstall_button[i]->setFont(QFont("URW Chancery L",13,50,false));//setFont("URW Chancery L");
        uninstall_button[i]->setStyleSheet("border:1px groove gray;border-radius:10px;padding:1px 1px;");
        uninstall_button[i]->setFixedSize(65,35);
        uninstall_button[i]->setFlat(true);
        uninstall_button[i]->setPalette(button_text_palette);
        //将按钮连接到map这样的机制上，通过setmap设置其转发机制，每个按钮对应一个id
        connect(uninstall_button[i],SIGNAL(clicked()),signal_mapper,SLOT(map()));
        signal_mapper->setMapping(uninstall_button[i],QString::number(i,10));
        //？
        //signal_mapper->setMapping(uninstall_button[i],uninstall_button[i]);
        //添加app样式
        temp->addWidget(app_icon_name);
        temp->addWidget(uninstall_button[i]);
        app_layout->addWidget(app_icon);
        app_layout->addLayout(temp);
        app_layout->setSpacing(0);
        //网格包添加每个小的样式
        gridLayout->addLayout(app_layout,i/3,i%3);
        gridLayout->setSpacing(0);
    }
    //将网格包样式添加到背景标签上
    back_label->setLayout(gridLayout);
    scrollArea->setWidget(back_label);
    qDebug() << "布局成功";
    //处理多按钮时间的最终处理的槽函数
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(uninstall(QString)));
    //connect(signal_mapper, SIGNAL(mapped(QWidget*)),this, SLOT(uninstall(QWidget*)));
}
//卸载应用
void App_Manager::uninstall(QString index){
    bool ok;
    QString prefix="./logo/";
    //获得点击按钮信号的id
    int i=index.toInt(&ok,10);
    //执行卸载命令
    //缺少卸载出错处理
    QString info= "adb uninstall "+app_name[i]+"";
    qDebug() << "------------------------";
    qDebug() << app_name[i];
    do_minimal_shell->start(info);
    //获得应用图片路径
    prefix.append(app_icon_path[i]);
    //删除应用图片
    deleteappinfo->start("rm -f "+prefix+"");
    //点击按钮变成已卸载
    /*uninstall_button[i]->clearMask();
     uninstall_button[i]->setEnabled(false);
     uninstall_button[i]->setText("已卸载");
     qDebug() << "clear mask";*/
    //删除卸载对应的应用
    delete_app(i);
    }

//读取应用信息
void App_Manager::read_installed_apps(){
    app_num=0;
    QFile file("uninstalled_maps.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        app_mixed_info[app_num++]=line.data();
        app_name[app_num-1]=line.data();
        //调试信息
        qDebug() << line.data();
    }
    //将提取的字符串解析成应用名和应用图标两个部分
    for(int i=0;i<app_num;i++){
        int index1=app_mixed_info[i].lastIndexOf('#');
        int index=app_mixed_info[i].lastIndexOf(':');
        app_name[i]=app_mixed_info[i].mid(0,index);
        app_icon_path[i]=app_mixed_info[i].mid(index+1,index1-index-1);
        qDebug() << app_name[i];
        qDebug() <<app_icon_path[i];
    }
    qDebug() << "read file";
}
//只有等shell执行完才允许解析应用，排列应用
void App_Manager::do_others(int,QProcess::ExitStatus exitstatus){
    if(exitstatus == QProcess::NormalExit){
        delete parse_app_process;
        //读取安装应用
        read_installed_apps();
        //排列图标
        arrange_appicon();
    }
    else{
        //调试信息
        qDebug() << "shell start error";
    }
}
void App_Manager::delete_app(int i){
    for(int j=i;j<app_num;j++){
        app_name[j]=app_name[j+1];//删除对应的包名
        app_icon_path[j]=app_icon_path[j+1];//删除对应的图标名
    }
    //总应用数减一
    app_num--;
    //清除布局组件
    clearLayout(gridLayout,true);
    //删除布局
    delete gridLayout;
    //重新排列图标
    arrange_appicon();
}
//清除布局上的所有组件
void App_Manager::clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    qDebug() << "clear layout";
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                delete widget;
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}
void App_Manager::start(){
    parse_app_process=new QProcess;
    process_excution();
    qDebug() << "press two";
    if(id ++ > 0){
    clearLayout(gridLayout,true);
    delete gridLayout;
    qDebug() << "delete layout";
    }
    connect(parse_app_process,SIGNAL(readyRead()),this,SLOT(readOutput()));
     connect(parse_app_process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(do_others(int,QProcess::ExitStatus)));
     connect(parse_app_process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(processError(QProcess::ProcessError)));
}
