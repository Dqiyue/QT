#include "phone_picture.h"

Phone_Picture::Phone_Picture(QWidget *parent) :
    QWidget(parent)
{
    //    this->setFixedSize(300,410);
        main_label = new QLabel();
        main_layout = new QVBoxLayout();

        main_label->setText("this is phone_picture");
        main_layout->addWidget(main_label,0,Qt::AlignCenter);
        main_layout->setSpacing(0);
        main_layout->setContentsMargins(5,5,5,5);
        setLayout(main_layout);
}


