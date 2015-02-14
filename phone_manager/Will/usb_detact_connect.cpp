#include "usb_detact_connect.h"
#include "hintdialog.h"
#include "QDebug"
#include "app_manager.h"
QString string = "bash ./shell_script/phone_link/phonelink.sh";
detact_thread::detact_thread(){
    times=0;
    qDebug() << "structor";
    process=new QProcess;
    timer=new QTimer;
    timer->setInterval(2000);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(time_over()));
    connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
    connect(&dialog,SIGNAL(changeTimer()),this,SLOT(changeTimer()));
}
void detact_thread::run(){
    qDebug() << "exec";
}
void detact_thread::time_over(){
    process->start(string);
    times++;
    qDebug() << times;
    qDebug() << "thread over";
}
void detact_thread::readOutput(){
    QString output;
    output +=process->readAll();
    output=output.mid(0,1);
    qDebug() << output;
    //如果当前手机adb连接不成功，输出未连接停止定时器，尝试重新连接后打开定时器
    if(output == "1" && times > 1){
        qDebug() << "not connected";
        timer->stop();
        dialog.show();
        dialog.flag=0;//多于五次，并且连接不成功标志值设为0
        dialog.change_state();
    }
   if(output == "0"){
        dialog.flag=2;
        dialog.change_state();
        qDebug() << "has connected";
    }
}
//改变定时器状态
void detact_thread::changeTimer(){
    qDebug() << "start";
    dialog.flag=1;
    dialog.change_state();
    timer->start();
    qDebug() << times;
    times=0;
}
