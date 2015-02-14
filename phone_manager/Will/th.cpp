#include "th.h"
#include"phoneshow.h"
Th::Th(QObject *parent) :
    QThread(parent)
{
}
void Th::run()
{
    Phoneshow phone;
    phone.showimg();
}
