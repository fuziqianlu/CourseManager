/********************************************************************************
** Form generated from reading UI file 'CellEnter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLENTER_H
#define UI_CELLENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CellEnter
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *CellEnter)
    {
        if (CellEnter->objectName().isEmpty())
            CellEnter->setObjectName(QStringLiteral("CellEnter"));
        CellEnter->resize(295, 73);
        horizontalLayout = new QHBoxLayout(CellEnter);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(CellEnter);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(CellEnter);

        QMetaObject::connectSlotsByName(CellEnter);
    } // setupUi

    void retranslateUi(QWidget *CellEnter)
    {
        CellEnter->setWindowTitle(QApplication::translate("CellEnter", "CellEnter", 0));
        pushButton->setText(QApplication::translate("CellEnter", "\350\277\233\345\205\245\351\200\211\350\257\276", 0));
    } // retranslateUi

};

namespace Ui {
    class CellEnter: public Ui_CellEnter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLENTER_H
