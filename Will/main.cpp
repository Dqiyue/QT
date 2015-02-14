#include "shdow_pro.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shdow_pro w;
    w.show();

    return a.exec();
}
