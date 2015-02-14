#include "show_image.h"
#include <QtDebug>

Show_Image::Show_Image(QString imgname,QString imgpath)
{
    spin_flag = 0;
    current_img_name = imgname;
    int current_img = current_img_name.toInt();
    init_path(QDir(imgpath),current_img);
    setBackgroundRole(QPalette::Background);
    setAutoFillBackground(true);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(1);
    setAttribute(Qt::WA_TranslucentBackground);
}
void Show_Image::spin_change()
{
    spin_flag +=90 ;
    update();
}
void Show_Image::mouseDoubleClickEvent(QMouseEvent *mouseEvent)
{
    if( mouseEvent->buttons() == Qt::LeftButton) //判断是否左键双击
    {
        emit img_clicked();
    }
}
void Show_Image::init_path(QDir newdir,int i)
{
    filepath=QDir(newdir);
    QStringList filters;
    filters << "*.png" << "*.bmp" << "*.gif" << "*.jpg"<<"*.cache";
    filepath.setNameFilters(filters);//设置文件名称过滤器，只为filters格式（后缀为.jpg等图片格式）
    filepath.setFilter( QDir::Files | QDir::Hidden | QDir::NoSymLinks );//设置类型过滤器，只为文件格式
    filepath.setSorting( QDir::Size | QDir::Reversed );
    list = filepath.entryList();
    if (!list.empty())
    {
        emit get2beg(false);
        emit get2end(false);
    }
    else
    {
        emit get2beg(true);
        emit get2end(true);
    }

    QStringList::const_iterator itmp = list.begin();
    iterator = itmp;
    for(int j=0;j<i;j++)
    {
        iterator++;
    }
    pixmap = QPixmap(filepath.absoluteFilePath((*(iterator))));
    update();
}
void Show_Image::show_next(void)
{
        if (iterator+1 == list.end())
            iterator = list.begin();
        ++iterator;
        pixmap = QPixmap(filepath.absoluteFilePath((*iterator)));
        wscale = 1.0;
        hscale = 1.0;
        emit turn2default(100);
        update();
}
void Show_Image::show_prev(void)
{
        if (iterator == list.begin())
            iterator =list.end();
        --iterator;
        pixmap = QPixmap(filepath.absoluteFilePath((*iterator)));
        wscale = 1.0;
        hscale = 1.0;
        emit turn2default(100);
        update();
}
void Show_Image::arise_scale(int rate)
{
    wscale = static_cast<double>(rate)/100.0;
    hscale = wscale;
    update();
}
void Show_Image::paintEvent(QPaintEvent * /* event */)
{
    double pixwidth = static_cast<double>(pixmap.width());
    double pixheight = static_cast<double>(pixmap.height());
    double showwidth = static_cast<double>(width());
    double showheight = static_cast<double>(height());

    double Wscalerate = pixwidth / showwidth;
    double Hscalerate = pixheight / showheight;
    double compare = (Wscalerate > Hscalerate ? Wscalerate : Hscalerate);

    QRect rect(
          showwidth/2.0 - pixwidth/compare/2.0,
          showheight/2.0- pixheight/compare/2.0,
          pixwidth/compare,
          pixheight/compare);
    QRect midrect(
          (showwidth/2.0-pixwidth/2.0),
          (showheight/2.0-pixheight/2.0),
          pixwidth,
          pixheight);
    QPainter painter(this);

    painter.save();
    if(spin_flag)
    {
        painter.translate(showwidth/2.0, (showheight/2.0)); //让图片的中心作为旋转的中心
        painter.rotate(spin_flag); //顺时针旋转90度
    }
    else
    {
        painter.translate(showwidth/2.0, (showheight/2.0));
    }
    painter.scale(wscale, hscale);
    painter.translate(-(showwidth/2), -(showheight/2.0));//使原点复原

    if (compare < 1.0)
        painter.drawPixmap(midrect, pixmap);
    else
        painter.drawPixmap(rect, pixmap);
    painter.restore();
}
QSize Show_Image::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Show_Image::sizeHint() const
{
    return QSize(640, 480);
}
