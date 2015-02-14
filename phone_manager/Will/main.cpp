#include "shdow_pro.h"
#include <QApplication>
//#include "main_widget.h"
#include <QSharedMemory>
#include "start_widget.h"
#include <QStackedWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //加载QSS样式表
    QFile qss(":/qss/Will");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    QSharedMemory shared_memory;
    shared_memory.setKey(QString("main_window"));

    if(shared_memory.attach())
    {
        return 0;
    }

    if(shared_memory.create(1))
    {
//        Stack_Widget stack;

    //    m.show_widget();
  //      stack.show_widget();
//        Main_Widget s;
        Start_Widget s;
//        main_widget_pro s;
        s.show_widget();


        return a.exec();
    }

}
