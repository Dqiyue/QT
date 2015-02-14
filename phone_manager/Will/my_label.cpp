#include "my_label.h"

My_Label::My_Label(QWidget *parent) :
    QLabel(parent)
{
}
void My_Label::mouseDoubleClickEvent(QMouseEvent *mouseEvent)
{
    if( mouseEvent->buttons() == Qt::LeftButton) //判断是否左键双击
    {
        emit show_clicked();
    }
}
void My_Label::mouseReleaseEvent(QMouseEvent * ev)
{
     judge_img();
     Q_UNUSED(ev)
     emit clicked();
}
void My_Label::judge_img()
{
    QString imgname = this->objectName();
    emit judge(imgname);
}
