#ifndef SHOWALL_H
#define SHOWALL_H

#include <QWidget>
#include <QProcess>
#include <QPixmap>
#include <QString>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QDir>
#include <QPainter>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include<QSlider>
#include <QDirIterator>
#include "Common.h"
#include "my_label.h"
#include "real_phone_picture.h"

class ShowAll : public QWidget
{
    Q_OBJECT
public:
    explicit ShowAll(QWidget *parent = 0);
    void all_picture_path(QString,int);
    void init_picture_grid();
    void update_picture_list();
     void FindFile(const QString &strFilePath, const QString &strNameFilters0,const QString &strNameFilters1,const QString &strNameFilters2);
    void clearLayout(QLayout *layout);

public:
         int picture_num;

signals:
         void update_picture_number();
 protected:
     void paintEvent(QPaintEvent *event);
 public slots:
//     void load_more();
     void imgClicked();
     void judgeImag(QString);
     void push_picture();
     void pull_picture();
     void pro_fin(int ec);

 private:


     QPushButton *push;
     QPushButton *pull;
     QString img_name;
     QString img_path;
     QVBoxLayout *main_layout;
     QWidget *list_Widget;
     int Current_num;

     int Column_num;
     int img_flag;
     int max_num;
     int img_size;
     QVBoxLayout *top_layout;
     QLabel *message;
     QProcess *pro;
     QGridLayout *grid;
     QVBoxLayout *v ;
     QStringList::const_iterator iterator;
     QStringList list;
     QDir filepath;
     QStringList filters;
     QPixmap pixmap;
     My_Label *img;
     QLabel *back_label;
     QScrollArea *scrollArea;//滑动窗口区域
     QPushButton *loadmore;
     QPushButton *imgbutton;
     Real_Phone_Picture *showimage;
     QFileInfo info;
     double wscale;
     double hscale;

};

#endif // SHOWALL_H
