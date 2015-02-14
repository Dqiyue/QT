#include "showall.h"
#include <QBitmap>
ShowAll::ShowAll(QWidget *parent) :
    QWidget(parent)
{

    main_layout = new QVBoxLayout();
    list_Widget = new QWidget();
     grid = new QGridLayout;
    pull = new QPushButton("获取手机图片");
    pull->setFlat(true);
    top_layout = new QVBoxLayout();
    message = new QLabel("");
//    message->setFont(QFont(PURISA,12,40,false));
    top_layout->addWidget(pull);
    top_layout->addWidget(message,0,Qt::AlignHCenter);

    connect(pull,SIGNAL(clicked()),this,SLOT(pull_picture()));

    picture_num = 0;
    img_flag  = 0;

    init_picture_grid();

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(list_Widget);
    scrollArea->setFixedSize(300,360);

    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    list_Widget->setLayout(grid);
    main_layout->addLayout(top_layout);
    main_layout->addWidget(scrollArea);
    main_layout->addStretch();
    setLayout(main_layout);

}
void ShowAll::FindFile(const QString &strFilePath, const QString &strNameFilters0,const QString &strNameFilters1,const QString &strNameFilters2)
{
 if (strFilePath.isEmpty())
 {
    qDebug()<<"file path not exist";
 }

    picture_num = 0;
    QDir dir;
    QStringList filters;

    filters << strNameFilters0<<strNameFilters1<<strNameFilters2;
    dir.setPath(strFilePath);
    dir.setNameFilters(filters);
    QDirIterator iter(dir,QDirIterator::Subdirectories);

    while (iter.hasNext())
    {
        iter.next();
        info=iter.fileInfo();

        if (info.isFile())
        {
            img_name =iter.fileName();
            img_path = iter.filePath();
            int index;
            index=img_path.indexOf(img_name);
            img_path= img_path.mid(0,index);
            picture_num++;
        }
    }
}
void ShowAll::imgClicked()
{
    if(img_flag == 0)
    {
        showimage = new Real_Phone_Picture(img_name,img_path);
        showimage->show();
        showimage->move(490,200);
        showimage->resize(350,300);
        img_flag = 1;
    }
    else
    {
        showimage->close();
        showimage = new Real_Phone_Picture(img_name,img_path);
        showimage->show();
        showimage->move(490,200);
        showimage->resize(350,300);
        img_flag = 1;
    }
}
void ShowAll::judgeImag(QString imgname)
{
    img_name = imgname;
}

void ShowAll::all_picture_path(QString Dir,int picturecount)
{
    filepath=QDir(Dir);
    filters << "*.png" << "*.bmp" << "*.gif" << "*.jpg"<<"*.cache";
    filepath.setNameFilters(filters);//设置文件名称过滤器，只为filters格式（后缀为.jpg等图片格式）
    filepath.setFilter( QDir::Files | QDir::Hidden | QDir::NoSymLinks );//设置类型过滤器，只为文件格式
    filepath.setSorting( QDir::Size | QDir::Reversed );
    list = filepath.entryList();
    QStringList::const_iterator itmp = list.begin();
    iterator = itmp;

    for(int j=0;j<picturecount;j++)
    {
        pixmap = QPixmap(filepath.absoluteFilePath((*(iterator))));
        img = new My_Label;
        img->setScaledContents(true);
        img->setPixmap(pixmap);
        img->setFixedSize(60,80);
        img->setObjectName(""+QString::number(j,10));
        connect(img, SIGNAL(clicked()), this, SLOT(imgClicked()));
        connect(img, SIGNAL(judge(QString)), this, SLOT(judgeImag(QString)));
        grid->addWidget(img,j/3 ,j%3);
        iterator++;
    }
}
void ShowAll::paintEvent(QPaintEvent * /* event */)
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

    painter.translate(showwidth/2.0, (showheight/2.0));
    painter.scale(wscale, hscale);
    painter.translate(-(showwidth/2), -(showheight/2.0));

    if (compare < 1.0)
        painter.drawPixmap(midrect, pixmap);
    else
        painter.drawPixmap(rect, pixmap);
    painter.restore();
}

void ShowAll::init_picture_grid()
{
    QPixmap mypixmap;
    mypixmap.load(":/picture/phone_picture/no_picture.jpg");
    img = new My_Label();
    img->setScaledContents(true);
    img->setPixmap(mypixmap.scaled(120,120));
    img->resize(mypixmap.width(),mypixmap.height());
    grid->addWidget(img);
}


void ShowAll::push_picture()
{

}

void ShowAll::pull_picture()
{
    message->setText("正在获取手机图片中...");
    pro = new QProcess();//new a process to exec the script
    pro->start("bash ./shell_script/pull_picture/picture.sh");
    connect(pro,SIGNAL(finished(int)),this,SLOT(pro_fin(int)));

}

void ShowAll::pro_fin(int ec)
{
    int num = picture_num;
    update_picture_list();
    if(!ec){
         pro->close();//关闭外部程序
         message->setText("获取到手机"+QString::number(picture_num-num,10) +"张新图片.");
         emit update_picture_number();
    }
    else
    {
        pro->close();
        message->setText("出现内部错误，获取失败");
    }
}

void ShowAll::update_picture_list()
{
    clearLayout(grid);
    FindFile("./phone_picture","*.jpg","*.png","*.cache");
    all_picture_path(img_path,picture_num);

}

void ShowAll::clearLayout(QLayout* layout)
{
//    qDebug() << "clear layout";
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (QWidget* widget = item->widget())
                delete widget;

        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout);
        delete item;
    }
}
