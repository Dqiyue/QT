#include "thread.h"
#include <QDebug>
Thread::Thread(QString controltype,int timer_value)
{
   control = controltype;
   maxvalue = 100;
   flag = 1;
   game0Value = 0;
   game1Value = 0;
   game2Value = 0;
   game3Value = 0;
   game4Value = 0;
   software0Value = 0;
   software1Value = 0;
   software2Value = 0;
   software3Value = 0;
   software4Value = 0;
   qtime= new QTimer;
   connect(qtime,SIGNAL(timeout()), this, SLOT(changeValue()));
   qtime->start(timer_value);
}
void Thread::run()
{
    if(control == "game0")
    {
        //开启外部程序
        pro = new QProcess;
        pro->start("adb install  ./apk/天下HD.apk");
        pro->waitForFinished();//等待外部程序执行完成
        int ec = pro->exitCode();
        if(!ec)//脚本执行完成后
        {
                if(flag > 0)
                emit emitSignal(control);
                pro->close();//关闭外部程序
                delete pro;
                pro = 0;
        }
    }
    else if(control == "game1")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/水果忍者.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;

         }
    }else if(control == "game2")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/刀塔传奇.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }else if(control == "game3")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/迷你西游.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }else if(control == "game4")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/去吧皮卡丘.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }else if(control == "software0")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/点心省电.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }else if(control == "software1")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/手机百度.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }else if(control == "software2")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/手机淘宝.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }else if(control == "software3")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/腾讯视频.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }else if(control == "software4")
    {
         //开启外部程序
         pro = new QProcess;
         pro->start("adb install  ./apk/手机优酷.apk");
         pro->waitForFinished();//等待外部程序执行完成
         int ec = pro->exitCode();
         if(!ec)//脚本执行完成后
         {
             if(flag > 0)
             emit emitSignal(control);
             pro->close();//关闭外部程序
             delete pro;
             pro = 0;
         }
    }
}
void Thread::changeValue()
{
    if(control == "game0")
    {
           game0Value++;
           if(game0Value <= maxvalue)
           emit timerSignal(game0Value);
    }
    if(control == "game1")
    {
           game1Value++;
           if(game1Value <= maxvalue)
           emit timerSignal(game1Value);
    }
    if(control == "game2")
   {
        game2Value++;
        if(game2Value <= maxvalue)
        emit timerSignal(game2Value);
   }
    if(control == "game3")
   {
        game3Value++;
        if(game3Value <= maxvalue)
        emit timerSignal(game3Value);
   }
    if(control== "game4")
   {
        game4Value++;
        if(game4Value <= maxvalue)
        emit timerSignal(game4Value);
   }
    if(control == "software0")
   {
        software0Value++;
        if(software0Value <= maxvalue)
        emit timerSignal(software0Value);
   }
    if(control == "software1")
   {
        software1Value++;
        if(software1Value <= maxvalue)
        emit timerSignal(software1Value);
   }
    if(control == "software2")
   {
        software2Value++;
        if(software2Value <= maxvalue)
        emit timerSignal(software2Value);
   }
    if(control == "software3")
   {
        software3Value++;
        if(software3Value <= maxvalue)
        emit timerSignal(software3Value);
   }
    if(control == "software4")
   {
        software4Value++;
        if(software4Value <= maxvalue)
        emit timerSignal(software4Value);
   }
}
void Thread::thread_restart(int value)
{
    if(control == "game0")
        game0Value = value;
    if(control == "game1")
        game1Value = value;
    if(control == "game2")
        game2Value = value;
    if(control == "game3")
        game3Value = value;
    if(control == "game4")
        game4Value = value;
    if(control == "software0")
        software0Value = value;
    if(control == "software1")
        software1Value = value;
    if(control == "software2")
        software2Value = value;
    if(control == "software3")
        software3Value = value;
    if(control == "software4")
        software4Value = value;
}
void Thread::thread_stop()
{
        flag = -1;
        pro->kill();
        qtime->stop();
        this->quit();
}
