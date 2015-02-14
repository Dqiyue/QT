#ifndef SHDOW_PRO_H
#define SHDOW_PRO_H

#include <QDialog>

namespace Ui {
class shdow_pro;
}

class shdow_pro : public QDialog
{
    Q_OBJECT

public:
    explicit shdow_pro(QWidget *parent = 0);
    ~shdow_pro();

private:
    Ui::shdow_pro *ui;
};

#endif // SHDOW_PRO_H
