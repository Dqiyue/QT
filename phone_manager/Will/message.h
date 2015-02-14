#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QProcess>
#include <QTableWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>
#include <QFile>
#include <QDir>
#include <QStringList>
#include <QDirIterator>
#include <QFileInfo>
#include <QList>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QTextStream>
#include <QProcess>
#include <QPushButton>
#include <QFileDialog>
namespace Ui {
class Message;
}

class Message : public QWidget
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = 0);
    ~Message();
    void GetFileInfo(QString filepath);
    void maketable();
        int message_num;
  public slots:
    void back();
private:
    QPushButton *backup;
    QProcess *process;
    QProcess *backup_pro;
    QTableWidget *qtw;
    QFileInfo info;
    QString filename;
    QString name ;
    QString type;
    QString date;
    QString content;
    QDir dir;
    QTableWidgetItem *item0, *item1,*item2,*item3;
   QList<QFileInfo> *fileInfo;
};

#endif // MESSAGE_H
