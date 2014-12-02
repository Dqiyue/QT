#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label = new QLabel(this);
    label->setText("hello world");
    label->setGeometry(QRect(100,100,200,125));
}

MainWindow::~MainWindow()
{
    delete ui;
}
