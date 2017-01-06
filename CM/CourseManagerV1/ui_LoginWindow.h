/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *userEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *PasswordLine;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QRadioButton *radioButton1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *btnOK;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(294, 247);
        verticalLayout_2 = new QVBoxLayout(LoginWindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LoginWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        userEdit = new QLineEdit(LoginWindow);
        userEdit->setObjectName(QStringLiteral("userEdit"));

        horizontalLayout_2->addWidget(userEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        PasswordLine = new QLineEdit(LoginWindow);
        PasswordLine->setObjectName(QStringLiteral("PasswordLine"));

        horizontalLayout->addWidget(PasswordLine);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        radioButton1 = new QRadioButton(LoginWindow);
        radioButton1->setObjectName(QStringLiteral("radioButton1"));
        radioButton1->setChecked(true);

        horizontalLayout_4->addWidget(radioButton1);

        radioButton_2 = new QRadioButton(LoginWindow);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_4->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(LoginWindow);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout_4->addWidget(radioButton_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        btnOK = new QPushButton(LoginWindow);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        verticalLayout_2->addWidget(btnOK);

        pushButton_2 = new QPushButton(LoginWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(273, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", 0));
        label->setText(QApplication::translate("LoginWindow", "\351\200\211\350\257\276\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_3->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("LoginWindow", "\350\257\267\351\200\211\346\213\251\350\272\253\344\273\275\357\274\232", 0));
        radioButton1->setText(QApplication::translate("LoginWindow", "\345\255\246\347\224\237", 0));
        radioButton_2->setText(QApplication::translate("LoginWindow", "\346\225\231\345\270\210", 0));
        radioButton_3->setText(QApplication::translate("LoginWindow", "\347\256\241\347\220\206\345\221\230", 0));
        btnOK->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", 0));
        pushButton_2->setText(QApplication::translate("LoginWindow", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
