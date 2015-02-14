#ifndef CONTACT_WIDGET_H
#define CONTACT_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QProcess>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
class Contact_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Contact_Widget(QWidget *parent = 0);
    int parseContacts();
    int pullContacts();

signals:

public slots:
    void back();
public:
      int lineNum;


private:
//    QLabel *main_label;
   QVBoxLayout *main_layout;
 QPushButton *contact;
    QString line_info[500];
    QString line_name[500];//name
    QString line_phone[500];//phone contact
    QProcess *pullcontacts;
    QProcess *contact_pro;


};

#endif // CONTACT_WIDGET_H
