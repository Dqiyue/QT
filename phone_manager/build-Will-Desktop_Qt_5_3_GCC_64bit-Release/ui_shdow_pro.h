/********************************************************************************
** Form generated from reading UI file 'shdow_pro.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHDOW_PRO_H
#define UI_SHDOW_PRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_shdow_pro
{
public:

    void setupUi(QDialog *shdow_pro)
    {
        if (shdow_pro->objectName().isEmpty())
            shdow_pro->setObjectName(QStringLiteral("shdow_pro"));
        shdow_pro->resize(400, 300);

        retranslateUi(shdow_pro);

        QMetaObject::connectSlotsByName(shdow_pro);
    } // setupUi

    void retranslateUi(QDialog *shdow_pro)
    {
        shdow_pro->setWindowTitle(QApplication::translate("shdow_pro", "shdow_pro", 0));
    } // retranslateUi

};

namespace Ui {
    class shdow_pro: public Ui_shdow_pro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHDOW_PRO_H
