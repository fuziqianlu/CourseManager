/********************************************************************************
** Form generated from reading UI file 'CourseChoice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSECHOICE_H
#define UI_COURSECHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseChoice
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CourseChoice)
    {
        if (CourseChoice->objectName().isEmpty())
            CourseChoice->setObjectName(QStringLiteral("CourseChoice"));
        CourseChoice->resize(766, 508);
        verticalLayout = new QVBoxLayout(CourseChoice);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget_3 = new QTreeWidget(CourseChoice);
        treeWidget_3->setObjectName(QStringLiteral("treeWidget_3"));
        treeWidget_3->setMaximumSize(QSize(741, 16777215));
        treeWidget_3->header()->setDefaultSectionSize(90);

        verticalLayout->addWidget(treeWidget_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(CourseChoice);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CourseChoice);

        QMetaObject::connectSlotsByName(CourseChoice);
    } // setupUi

    void retranslateUi(QWidget *CourseChoice)
    {
        CourseChoice->setWindowTitle(QApplication::translate("CourseChoice", "CourseChoice", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_3->headerItem();
        ___qtreewidgetitem->setText(9, QApplication::translate("CourseChoice", "\351\200\211\346\213\251\350\257\276\347\250\213", 0));
        ___qtreewidgetitem->setText(8, QApplication::translate("CourseChoice", "\346\234\200\345\244\247\345\256\271\351\207\217", 0));
        ___qtreewidgetitem->setText(7, QApplication::translate("CourseChoice", "\347\216\260\346\234\211\345\256\271\351\207\217", 0));
        ___qtreewidgetitem->setText(6, QApplication::translate("CourseChoice", "\344\270\212\350\257\276\345\234\260\347\202\271", 0));
        ___qtreewidgetitem->setText(5, QApplication::translate("CourseChoice", "\347\273\223\346\235\237\350\212\202\346\225\260", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("CourseChoice", "\345\274\200\345\247\213\350\212\202\346\225\260", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("CourseChoice", "\346\227\245\346\234\237", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("CourseChoice", "\346\225\231\345\270\210", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("CourseChoice", "\350\257\276\347\250\213\345\220\215\347\247\260", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("CourseChoice", "\350\257\276\347\250\213\347\274\226\345\217\267", 0));
        pushButton->setText(QApplication::translate("CourseChoice", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class CourseChoice: public Ui_CourseChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSECHOICE_H
