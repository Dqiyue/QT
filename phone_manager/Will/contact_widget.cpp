#include "contact_widget.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"
#include "QToolButton"
#include "QWidget"
#include "QTableWidget"
#include "QFile"
#include "QHeaderView"
Contact_Widget::Contact_Widget(QWidget *parent) :
    QWidget(parent)
{
    lineNum = 0;
    this->setFixedSize(300,440);
    main_layout = new QVBoxLayout;
//    main_label = new QLabel();
//    main_layout = new QVBoxLayout();

//    main_label->setText("this is contact");
//    main_layout->addWidget(main_label,0,Qt::AlignCenter);
//    main_layout->setSpacing(0);
//    main_layout->setContentsMargins(5,5,5,5);
//    setLayout(main_layout);
    pullcontacts = new QProcess;
    pullContacts();
    lineNum = parseContacts();
    if(lineNum == -1){
        //QMessageBox::information(0,"无联系人","无联系人");
    }
    QTableWidget *tableWidget = new QTableWidget(lineNum,2); // 构造了一个QTableWidget的对象，并且设置为lineNUm行，2列
     tableWidget->setWindowTitle("QTableWidget & Item");
     tableWidget->setColumnWidth(0,100);
     tableWidget->setColumnWidth(1,160);
     tableWidget->resize(300, 440);  //设置表格
     QStringList header;
     QHeaderView* headerView = tableWidget->horizontalHeader();
     headerView->setStyleSheet("section:middle{text-align: center};");
     tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     header<<"姓名"<<"联系人";
     tableWidget->setHorizontalHeaderLabels(header);
     for(int i=0; i<lineNum ;i++){
          tableWidget->setItem(i,0,new QTableWidgetItem(""+line_name[i]+""));
          tableWidget->setItem(i,1,new QTableWidgetItem(""+line_phone[i]+""));
     }
     contact = new QPushButton(tr("备份"));
     connect(contact,SIGNAL(clicked()),this,SLOT(back()));
     tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     tableWidget->resizeColumnToContents (0);
     main_layout->addWidget(tableWidget);
     main_layout->addWidget(contact);
     main_layout->setSpacing(0);
     main_layout->setContentsMargins(5,5,5,5);
     this->setLayout(main_layout);
}

int Contact_Widget::parseContacts(){
    lineNum=0;
    QFile file("./我的联系人.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return -1;
    }
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        line_info[lineNum]=line.data();
        //调试信息
        QStringList list = line_info[lineNum].split("    ");
        line_name[lineNum] = list[0];
        line_phone[lineNum] = list[1];
        lineNum++;
    }
    return lineNum;
}
int Contact_Widget::pullContacts(){
    //需要加入删除
    QString info= "bash ./shell_script/pull_contacts/pull_contacts.sh";
    pullcontacts->start(info);
    pullcontacts->waitForFinished();
}
void Contact_Widget::back()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("联系人存放路径"));
      if(path.length() == 0) {
              QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
      } else {
              QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
      }
    contact_pro = new QProcess;
    QString backup_path = "cp -r ./我的联系人.txt "+path;
    contact_pro->start(backup_path);//
    contact_pro->waitForFinished(); //wait for this process finished
    int ec = contact_pro->exitCode();
    if(!ec)//脚本执行完成后
    {
        QMessageBox::information(NULL, "success", "备份成功!");
        contact->setText(tr("已备份"));
        contact->setDisabled(true);
        contact_pro->close();//关闭外部程序
        delete contact_pro;
        contact_pro;
    }

}
