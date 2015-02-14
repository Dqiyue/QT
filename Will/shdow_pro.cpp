#include "shdow_pro.h"
#include "ui_shdow_pro.h"

shdow_pro::shdow_pro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shdow_pro)
{
    ui->setupUi(this);
}

shdow_pro::~shdow_pro()
{
    delete ui;
}
