/********************************************************************************
** Form generated from reading UI file 'CellChoose.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLCHOOSE_H
#define UI_CELLCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CellChoose
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;

    void setupUi(QWidget *CellChoose)
    {
        if (CellChoose->objectName().isEmpty())
            CellChoose->setObjectName(QStringLiteral("CellChoose"));
        CellChoose->resize(297, 57);
        verticalLayout = new QVBoxLayout(CellChoose);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(CellChoose);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);


        retranslateUi(CellChoose);

        QMetaObject::connectSlotsByName(CellChoose);
    } // setupUi

    void retranslateUi(QWidget *CellChoose)
    {
        CellChoose->setWindowTitle(QApplication::translate("CellChoose", "CellChoose", 0));
        checkBox->setText(QApplication::translate("CellChoose", "\351\200\211\346\213\251\350\257\245\350\257\276", 0));
    } // retranslateUi

};

namespace Ui {
    class CellChoose: public Ui_CellChoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLCHOOSE_H
