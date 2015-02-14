#include "tittle_widget.h"
#include <QLayout>
#include "QDesktopWidget"
#include "QApplication"
Tittle_Widget::Tittle_Widget(QWidget *parent) :
    QWidget(parent)
{
    id = 0;
QDesktopWidget  *d=QApplication::desktop();
  //  this->setStyleSheet("background:#27ae61");
    current_skin = 4;
    skin_list<<"background-color:#fffafa"<<"background-color:#dc143c"<<"background-color:#ff8c00"<<"background-color:#ffd700"<<"background-color:#3cb371"<<"background-color:#483d8b"<<"background-color:#800000"<<"background-color:#4b0082"<<"background-color:#000000";

    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText, QColor(255, 255, 255));

    top_label = new QLabel();
    top_label->setGeometry(0,0,d->width(),110);
//    top_label->setStyleSheet("background-color:#3cb371");
 //   top_label->setStyleSheet("background-color:rgba(60,179,113,100%);");
    top_label->setStyleSheet(DEFAULT_SKIN);

       top_label->setParent(this);
//    top_label_pre = new QLabel(this);
//    top_label_pre->setGeometry(0,0,900,110);
//    top_label_pre->setStyleSheet("background-color:rgba(255,255,255,5%);");
    version = new QLabel(" Cool Manager 2.0");  //version info
    version->setPalette(text_palette);
    version->setFont(QFont("黑体",10,99,true));

    /*set button for close and minisized the main_widget*/
    btclose = new QPushButton();
    QPixmap close_pic(":/picture/button_pic/close");
    btclose->setIcon(close_pic);
    btclose->setIconSize(close_pic.size());
    btclose->setFixedSize(close_pic.width()+2,close_pic.height()+2);
    btclose->setFlat(true);

    btmin = new QPushButton();
    QPixmap min_pic(":/picture/button_pic/min");
    btmin->setIcon(min_pic);
    btmin->setIconSize(min_pic.size());
    btmin->setFixedSize(min_pic.width()+2,min_pic.height()+2);
    btmin->setFlat(true);

    btmax = new QPushButton();
    QPixmap max_pic(":/picture/button_pic/max.png");
    btmax->setIcon(max_pic);
    btmax->setIconSize(max_pic.size());
    btmax->setFixedSize(max_pic.width(),max_pic.height());
    btmax->setFlat(true);

    btskin = new QPushButton();
    QPixmap skin_pic(":/picture/button_pic/skin");
    btskin->setIcon(skin_pic);
    btskin->setIconSize(skin_pic.size());
    btskin->setFixedSize(skin_pic.width()+2,skin_pic.height()+2);
    btskin->setFlat(true);

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(version,0,Qt::AlignVCenter);
    main_layout->addStretch();
    main_layout->addWidget(btskin,0,Qt::AlignTop);
//    main_layout->addWidget(btmax,0,Qt::AlignTop);
    main_layout->addWidget(btmin,0,Qt::AlignTop);
    main_layout->addWidget(btclose,0,Qt::AlignTop);

    version->setContentsMargins(15,0,0,0);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0,0,5,0);

    connect(btclose,SIGNAL(clicked()),this,SIGNAL(show_close()));
    connect(btmin, SIGNAL(clicked()),this,SIGNAL(show_min()));
    connect(btskin,SIGNAL(clicked()),this,SLOT(change_skin()));

/*use signalMapper to deal with several buttons' signals .It is these buttons to decide to the stacked_widget's turnPage*/
    QStringList string_list;
//    string_list<<":/picture/tools/one"<<":/picture/tools/two"<<":/picture/tools/three";
    string_list<<"首页 >"<<"本机应用 >"<<"应用商店>"<<"文件管理 >";

    QHBoxLayout *button_layout = new QHBoxLayout();

    QSignalMapper *signal_mapper = new QSignalMapper(this);
    for(int i=0; i<string_list.size(); i++)
    {
        Tool_Button_Pro *tool_button = new Tool_Button_Pro(string_list.at(i));

        btnlist.append(tool_button);
        connect(tool_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(tool_button, QString::number(i, 10));

        button_layout->addWidget(tool_button, 0, Qt::AlignBottom);
    }
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(turnPage(QString)));


    QHBoxLayout *logo_layout = new QHBoxLayout();
    product_name = new QLabel("Shine The Night");  //this label doesn't matter now
    product_name->setPalette(text_palette);
    product_name->setFont(QFont(URW_C_FONT,16,QFont::Bold,true));
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setOffset(8,8);
    product_name->setGraphicsEffect(effect);

    //实例 QGraphicsOpacityEffect
    QGraphicsOpacityEffect *o_effect = new QGraphicsOpacityEffect();
    //设定透明值
    o_effect->setOpacity(0.5);

    logo = new QLabel();
    QPixmap logo_pic(":/picture/button_pic/start");
    logo->setPixmap(logo_pic.scaled(70,70));
    logo->setGraphicsEffect(o_effect);

    logo_layout->addWidget(logo);
    logo_layout->addWidget(product_name);
    logo_layout->addStretch();
    logo_layout->setSpacing(0);
    logo_layout->setContentsMargins(0,0,5,0);

    button_layout->addStretch();
    button_layout->addLayout(logo_layout);
    button_layout->setSpacing(8);
    button_layout->setContentsMargins(15, 0, 15, 0);

    QVBoxLayout *all_layout = new QVBoxLayout();

    all_layout->addLayout(main_layout);
    all_layout->addLayout(button_layout);

    this->setbtntxt();
    setLayout(all_layout);
    setFixedHeight(110);

     is_move = false;

}
Tittle_Widget::~Tittle_Widget()
{

}

void Tittle_Widget::turnPage(QString current_page)
{
    bool ok;
    int current_index = current_page.toInt(&ok, 10);

    for(int i=0; i<btnlist.count(); i++)
    {
        Tool_Button_Pro *tool_button = btnlist.at(i);
        if(current_index == i)
        {
            tool_button->setMousePress(true);
            tool_button->setEnabled(false);
        }
        else
        {
            tool_button->setMousePress(false);
            tool_button->setEnabled(true);
        }
    }

    emit turnPage(current_index);
    qDebug() << current_page;
    //emit turnPage();
}

void Tittle_Widget::change_skin()
{
    if(current_skin < skin_list.size()-1)
    {
        current_skin++;
    }
    else{
        current_skin = 0;
    }
    top_label->setStyleSheet(skin_list.at(current_skin));
 //   top_label->setStyleSheet("background-color:#000000");
    int current = current_skin;
    emit change_skin(current);
    qDebug() << current_skin+"skin";
}

void Tittle_Widget::setbtntxt()
{
//    btnlist.at(0)->setText("one");
//    btnlist.at(1)->setText("two");
//    btnlist.at(2)->setText("three");
}
void Tittle_Widget::mouseDoubleClickEvent(QMouseEvent *)
{
    id++;
    if(id%2 == 1){
    emit showMax();
        qDebug() << "show max";
    }
    else{
        emit showNor();
        qDebug() << "show normal";
    }
}
