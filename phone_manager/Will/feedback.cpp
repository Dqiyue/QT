#include "feedback.h"

FeedBack::FeedBack(QWidget *parent) :
    QWidget(parent)
{
    edit = new QLineEdit();
    main_layout = new QVBoxLayout();
    main_layout->addWidget(edit,0,Qt::AlignCenter);
    this->setLayout(main_layout);
}


void FeedBack::show_widget()
{
    this->showNormal();
    this->raise();
    this->activateWindow();
}
