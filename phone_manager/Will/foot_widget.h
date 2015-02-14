#ifndef FOOT_WIDGET_H
#define FOOT_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
//#include "start_widget.h"
#include <QStackedWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QDir>
#include <QPainter>
#include "tittle_widget.h"
#include "Common.h"
#include "QProcess"
#include "QMessageBox"
#define COMMON_APP_DIR "./recommend/"

class Foot_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Foot_Widget(QWidget *parent = 0);

private slots:
    void show_app();

public slots:
    void uninstall(QString file);

public:
    void clearLayout(QLayout *layout);
    void initApp();
    void clearApp();
    void update_my_app();

public:
   QLabel *back_label;
   QPushButton *my_app_btn;
   QPushButton *wireless_button;
   bool btn_pressed;
   int app_number;


protected:
   virtual void paintEvent(QPaintEvent *event);

private:
    QHBoxLayout *tittle_layout;
    QVBoxLayout *main_layout;
    QLabel *foot_lab;
    QGridLayout *app_layout;
    QList<QPushButton*> btnlist_uninstall;
    QList<QLabel*> lab_list;
    QList<QFileInfo> app_fileInfo_list;
    QProcess *process;
    QProcess *install_process;
signals:
    void show_app(bool is_pressed);

public slots:
    void start_wireless_server();
    void processError(QProcess::ProcessError);
};

#endif // FOOT_WIDGET_H
