#include "message.h"
#include <QDebug>
Message::Message(QWidget *parent) :
    QWidget(parent)
{
    process = new QProcess;
    process->start("bash ./shell_script/smsinfo/smsinfo.sh");
    qDebug() << "start process";
    process->waitForFinished();
    GetFileInfo("./message");
    qtw = new QTableWidget(message_num,4);  //新建一message_num行4列的表格
    QStringList headerLabels;
    headerLabels << "Name" << "Type" << "Date" << "Content";
    qtw->setHorizontalHeaderLabels(headerLabels);
    //设置表格行标题的对齐方式
    //qtw->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
//    设置行表题
//    QStringList Labels;
//    rowLabels << "Name" << "Type" << "Date" << "Content";
//    qtw->setVerticalHeaderLabels(rowLabels);
    //设置每一行的高度
    for(int i = 0; i < message_num; i++)
        qtw->setRowHeight(i, 22);

//        qtw->setColumnWidth(0,50);
//        qtw->setColumnWidth(1,40);
//        qtw->setColumnWidth(2,70);
//        qtw->setColumnWidth(3,80);

    //自动调整最后一列的宽度使它和表格的右边界对齐
    //qtw->horizontalHeader()->setStretchLastSection(true);

    //设置表格的选择方式
    qtw->setSelectionBehavior(QAbstractItemView::SelectItems);
    //设置编辑方式
    backup = new QPushButton(tr("备份"));
    connect(backup,SIGNAL(clicked()),this,SLOT(back()));
    qtw->setEditTriggers(QAbstractItemView::DoubleClicked);
    maketable();
    QVBoxLayout *qh = new QVBoxLayout;
    qh->addWidget(qtw);
    qh->addWidget(backup);
    setLayout(qh);
//    this->setFixedSize(300,440);
}
void Message::back()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("短信存放路径"));
      if(path.length() == 0) {
              QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
      } else {
              QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
      }
    backup_pro = new QProcess;
    QString backup_path = "cp -r ./message/ "+path;
    backup_pro->start(backup_path);//
    backup_pro->waitForFinished(); //wait for this process finished
    int ec = backup_pro->exitCode();
    if(!ec)//脚本执行完成后
    {
        QMessageBox::information(NULL, "success", "备份成功!");
        backup->setText(tr("已备份"));
        backup->setDisabled(true);
        backup_pro->close();//关闭外部程序
        delete backup_pro;
        backup_pro;
    }

}
void Message::maketable()
{
    int count = 0;
    for(int i=0;i<message_num;i++,count++)
    {
        filename = fileInfo->at(count).fileName();
         if(filename == "."||filename == "..")
         {
             i--;
             continue;
         }

        int index1;
        index1 = filename.indexOf("_");
        name = filename.mid(0,index1);
        int index2;
        index2 = filename.indexOf("#");
        type= filename.mid(index1+1,index2-index1-1);
        int index3;
        index3 = filename.indexOf("\n");
        date= filename.mid(index2+1,index3-index2-1);

        item0 = new QTableWidgetItem;
        item1 = new QTableWidgetItem;
        item2 = new QTableWidgetItem;
        item3 = new QTableWidgetItem;

        QString file_name_path = "./message/"+filename;
        QFile f(file_name_path);
        if (!f.open(QIODevice::ReadOnly|QIODevice::Text)) {
            //QMessageBox::critical(NULL, "提示", "no file");
            qDebug() << "no this file";
        }
        QTextStream in(&f);
        in.setCodec("System");
        in>>content;
        f.close();
        if(type=="0")
        {
            type = "发送";
        }
        if(type=="1")
        {
            type = "接收";
        }
        if(type=="2")
        {
            type = "垃圾";
        }
        item0->setText(name);
        item1->setText(type);
        item2->setText(date);
        item3->setText(content);
        item0->setTextAlignment(Qt::AlignCenter);
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        qtw->setItem(i, 0, item0);
        qtw->setItem(i, 1, item1);
        qtw->setItem(i, 2, item2);
        qtw->setItem(i, 3, item3);
    }
}
void Message::GetFileInfo(QString Dir)
{
    if (Dir.isEmpty())
    {
       qDebug()<<"file path not exist";
    }
    dir=QDir(Dir);
    QStringList filter;
    fileInfo=new QList<QFileInfo>(dir.entryInfoList(filter));
    message_num = (fileInfo->count()-2);
}
Message::~Message()
{
    delete process;
}
