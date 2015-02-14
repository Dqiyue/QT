#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QScrollArea>
#include <QSignalMapper>
#include <QFileInfo>
#include <QDebug>
#include <QProcess>
#include "Common.h"

class File_Manager : public QWidget
{
    Q_OBJECT
public:
    explicit File_Manager(QWidget *parent = 0);

public:
    void addToFilelist(const QStringList &fileNames);
    void clearLayout(QLayout *layout);
    void update(QString dir);

signals:

public slots:
    void open_file();
    void get_file();
    void pull_file();
    void del_file(QString index);
    void get_pro_fin(int ec);
    void get_pro_fin_two(int ec);
    void get_pro_fin_three(int ec);
    void get_pro_fin_four(int ec);
    void pro_fin(int ec);
    void cdDir(QString dir);
    void del_phone_file(QString name);
    void copy_file_to_pc(QString name);
    void resume_layout(int ec);
    void resume_layout_two(int ec);
    void get_back_to_last_dir();

private:

    QLabel *main_label;
    QLabel *dir_label;
    QVBoxLayout *main_layout;
    QPushButton *show_file;
    QPushButton *openfile;
    QPushButton *push;
    QPushButton *goback;
    QHBoxLayout *main_btn_layout;
    QWidget *file_list_widget;
    QScrollArea *scroll;
    QLabel *message;
    QVBoxLayout *list_layout;
    QHBoxLayout *push_layout;
    QList<QFileInfo> fileinfo_list;
    QProcess *pro;
    QProcess *pro1;
    QProcess *pro2;
    QProcess *pro3;
    QString dir_now;
    QString dir_pro;
    QString file_selected;
    int pro_number;
    int failed;
    int success;
    bool is_selected;

};

#endif // FILE_MANAGER_H
