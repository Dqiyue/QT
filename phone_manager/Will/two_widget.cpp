#include "two_widget.h"

Two_Widget::Two_Widget(QWidget *parent) :
    QWidget(parent)
{
    two_lab = new QLabel();
    two_lab->setText("this is the second page");
    main_layout = new QVBoxLayout();
    main_layout->addWidget(two_lab,0,Qt::AlignCenter);
    setLayout(main_layout);

}
