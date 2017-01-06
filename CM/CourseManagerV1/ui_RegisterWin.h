/********************************************************************************
** Form generated from reading UI file 'RegisterWin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIN_H
#define UI_REGISTERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWin
{
public:
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_13;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *RegisterWin)
    {
        if (RegisterWin->objectName().isEmpty())
            RegisterWin->setObjectName(QStringLiteral("RegisterWin"));
        RegisterWin->resize(548, 432);
        label_6 = new QLabel(RegisterWin);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 50, 54, 12));
        lineEdit_5 = new QLineEdit(RegisterWin);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(220, 50, 141, 20));
        label_7 = new QLabel(RegisterWin);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 280, 131, 16));
        label_8 = new QLabel(RegisterWin);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(160, 140, 54, 12));
        lineEdit_6 = new QLineEdit(RegisterWin);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(220, 280, 141, 20));
        lineEdit_7 = new QLineEdit(RegisterWin);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(222, 140, 141, 20));
        widget = new QWidget(RegisterWin);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 310, 522, 25));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_12 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_7->addWidget(pushButton);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_7->addWidget(pushButton_2);

        horizontalSpacer_13 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        lineEdit_4 = new QLineEdit(RegisterWin);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(220, 170, 141, 20));
        label_3 = new QLabel(RegisterWin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 180, 36, 16));
        label = new QLabel(RegisterWin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 80, 132, 16));
        lineEdit = new QLineEdit(RegisterWin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 80, 141, 20));
        label_2 = new QLabel(RegisterWin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 110, 36, 16));
        lineEdit_2 = new QLineEdit(RegisterWin);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 110, 141, 20));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        widget1 = new QWidget(RegisterWin);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(220, 210, 167, 18));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget1);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(widget1);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout->addWidget(radioButton_3);

        label_4 = new QLabel(RegisterWin);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 210, 60, 16));
        label_5 = new QLabel(RegisterWin);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 250, 141, 16));
        lineEdit_3 = new QLineEdit(RegisterWin);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(220, 250, 141, 20));

        retranslateUi(RegisterWin);

        QMetaObject::connectSlotsByName(RegisterWin);
    } // setupUi

    void retranslateUi(QDialog *RegisterWin)
    {
        RegisterWin->setWindowTitle(QApplication::translate("RegisterWin", "RegisterWin", 0));
        label_6->setText(QApplication::translate("RegisterWin", "*\345\247\223\345\220\215\357\274\232", 0));
        label_7->setText(QApplication::translate("RegisterWin", "\344\270\223\344\270\232/\357\274\210\345\255\246\347\224\237\344\270\272\345\271\264\347\272\247\357\274\211\357\274\232", 0));
        label_8->setText(QApplication::translate("RegisterWin", "*\351\202\256\347\256\261\357\274\232", 0));
        pushButton->setText(QApplication::translate("RegisterWin", "\346\263\250\345\206\214", 0));
        pushButton_2->setText(QApplication::translate("RegisterWin", "\345\217\226\346\266\210", 0));
        label_3->setText(QApplication::translate("RegisterWin", "*\347\224\265\350\257\235\357\274\232", 0));
        label->setText(QApplication::translate("RegisterWin", "*\345\255\246\345\217\267/\345\267\245\345\217\267/\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("RegisterWin", "*\345\257\206\347\240\201\357\274\232", 0));
        radioButton->setText(QApplication::translate("RegisterWin", "\345\255\246\347\224\237", 0));
        radioButton_2->setText(QApplication::translate("RegisterWin", "\346\225\231\345\270\210", 0));
        radioButton_3->setText(QApplication::translate("RegisterWin", "\347\256\241\347\220\206\345\221\230", 0));
        label_4->setText(QApplication::translate("RegisterWin", "*\351\200\211\346\213\251\350\272\253\344\273\275\357\274\232", 0));
        label_5->setText(QApplication::translate("RegisterWin", "\350\201\214\347\247\260/(\345\255\246\347\224\237\344\270\272\347\217\255\347\272\247\357\274\211\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterWin: public Ui_RegisterWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIN_H
