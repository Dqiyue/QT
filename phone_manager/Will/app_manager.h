#ifndef APP_MANAGER_H
#define APP_MANAGER_H
#include <QMainWindow>
#include <QLabel>
#include <QProcess>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QString>
#include <QList>
#include "tool_button.h"
#include <QHBoxLayout>
#include "QScrollArea"
class App_Manager : public QWidget
{
    Q_OBJECT

public:
    explicit App_Manager(QWidget *parent = 0);
    ~App_Manager();
    void process_excution();
    void arrange_appicon();
    void read_installed_apps();
    void delete_app(int);
    void clearLayout(QLayout*, bool);
    void start();
private:
    QLabel *label;
    QLabel *back_label;//widget的上一层组件
    QProcess *parse_app_process;//解析app进程
    QProcess *do_minimal_shell; //执行简单shell的进程
    QProcess *deleteappinfo; //
    QWidget *widget;//窗口部件
    QPushButton button;//for app installed
    QSignalMapper *signal_mapper; //关联包名和图片名
    int app_num;//app的数目
    QString app_mixed_info[100];//解析应用信息
    QPushButton *uninstall_button[100];//删除按钮
    QGridLayout *gridLayout;//网格包布局
    QString app_icon_path[100];//app icon的名字
    QString app_name[100]; //应用的包民
    QScrollArea *scrollArea;//滑动窗口区域
    int id;

private slots:
    void readOutput();
    void processError(QProcess::ProcessError);
    void uninstall(QString);
    void do_others(int,QProcess::ExitStatus);
};
#endif // APP_MANAGER_H
