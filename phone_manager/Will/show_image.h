#ifndef SHOW_IMAGE_H
#define SHOW_IMAGE_H

#include <QWidget>
#include <QStringList>
#include <QDir>
#include <QPixmap>
#include <QtGui>
#include<QProcess>

class Show_Image : public QWidget
{
    Q_OBJECT
public:
    explicit Show_Image(QString,QString);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
signals:
    void get2end(bool);
    void get2beg(bool);
    void turn2default(int);
    void img_clicked();
protected:
    void paintEvent(QPaintEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *mouseEvent);
public slots:
    void init_path(QDir,int);
    void show_next(void);
    void show_prev(void);
    void arise_scale(int);
    void spin_change();
private:
    QStringList::const_iterator iterator;
    QStringList list;
    QDir filepath;
    QPixmap pixmap;
    QString current_img_name;
    int spin_flag;
    //QProcess *pro;
    double wscale;
    double hscale;

};

#endif // SHOW_IMAGE_H
