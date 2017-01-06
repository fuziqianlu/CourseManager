/********************************************************************************
** Form generated from reading UI file 'TeacherWin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWIN_H
#define UI_TEACHERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherWin
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_13;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_15;
    QLabel *label_16;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *teacherCourses;
    QWidget *tab_5;
    QTableWidget *teacherCourses_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableWidget_2;
    QWidget *tab_7;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget_4;
    QWidget *tab_8;
    QPlainTextEdit *plainTextEdit;
    QTableWidget *tableWidget_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_8;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_5;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_6;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_9;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_17;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_8;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_18;
    QLineEdit *lineEdit_9;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_24;
    QLineEdit *lineEdit_12;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_23;
    QLineEdit *lineEdit_11;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_19;
    QLineEdit *lineEdit_8;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_20;
    QLineEdit *lineEdit_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TeacherWin)
    {
        if (TeacherWin->objectName().isEmpty())
            TeacherWin->setObjectName(QStringLiteral("TeacherWin"));
        TeacherWin->resize(779, 572);
        centralWidget = new QWidget(TeacherWin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalSpacer_13 = new QSpacerItem(478, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_13);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_19->addWidget(label_13);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_19->addWidget(label_14);

        horizontalSpacer_10 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_10);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_19->addWidget(label_15);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_19->addWidget(label_16);


        horizontalLayout_17->addLayout(horizontalLayout_19);


        verticalLayout->addLayout(horizontalLayout_17);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setTabPosition(QTabWidget::West);
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        teacherCourses = new QTableWidget(tab_4);
        if (teacherCourses->columnCount() < 6)
            teacherCourses->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        teacherCourses->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        teacherCourses->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        teacherCourses->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        teacherCourses->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        teacherCourses->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        teacherCourses->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        teacherCourses->setObjectName(QStringLiteral("teacherCourses"));

        verticalLayout_3->addWidget(teacherCourses);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        teacherCourses_2 = new QTableWidget(tab_5);
        if (teacherCourses_2->columnCount() < 7)
            teacherCourses_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        teacherCourses_2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        teacherCourses_2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        teacherCourses_2->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        teacherCourses_2->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        teacherCourses_2->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        teacherCourses_2->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        teacherCourses_2->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        if (teacherCourses_2->rowCount() < 13)
            teacherCourses_2->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(6, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(7, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(8, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(9, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(10, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(11, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        teacherCourses_2->setVerticalHeaderItem(12, __qtablewidgetitem25);
        teacherCourses_2->setObjectName(QStringLiteral("teacherCourses_2"));
        teacherCourses_2->setGeometry(QRect(10, 10, 694, 400));
        tabWidget_2->addTab(tab_5, QString());

        verticalLayout_2->addWidget(tabWidget_2);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget_3 = new QTabWidget(tab_3);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setTabPosition(QTabWidget::West);
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        verticalLayout_7 = new QVBoxLayout(tab_6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        tableWidget_2 = new QTableWidget(tab_6);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem32);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        verticalLayout_7->addWidget(tableWidget_2);

        tabWidget_3->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tableWidget = new QTableWidget(tab_7);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem37);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(9, 49, 691, 341));
        layoutWidget = new QWidget(tab_7);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 390, 671, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(588, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        layoutWidget1 = new QWidget(tab_7);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 10, 487, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_4 = new QLineEdit(layoutWidget1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        tabWidget_3->addTab(tab_7, QString());

        verticalLayout_4->addWidget(tabWidget_3);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tabWidget_4 = new QTabWidget(tab_2);
        tabWidget_4->setObjectName(QStringLiteral("tabWidget_4"));
        tabWidget_4->setTabPosition(QTabWidget::West);
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        plainTextEdit = new QPlainTextEdit(tab_8);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(9, 93, 694, 124));
        tableWidget_3 = new QTableWidget(tab_8);
        if (tableWidget_3->columnCount() < 4)
            tableWidget_3->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem41);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(9, 254, 694, 124));
        layoutWidget2 = new QWidget(tab_8);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 406, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_2 = new QLineEdit(layoutWidget2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);

        layoutWidget3 = new QWidget(tab_8);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 70, 586, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        horizontalSpacer_8 = new QSpacerItem(518, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        layoutWidget4 = new QWidget(tab_8);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(100, 220, 598, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        pushButton_4 = new QPushButton(layoutWidget4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_6->addWidget(pushButton_4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        pushButton_5 = new QPushButton(layoutWidget4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_6->addWidget(pushButton_5);

        layoutWidget5 = new QWidget(tab_8);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(280, 380, 421, 25));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_9 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);

        pushButton_6 = new QPushButton(layoutWidget5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_10->addWidget(pushButton_6);

        layoutWidget6 = new QWidget(tab_8);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 40, 495, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget6);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_5 = new QLineEdit(layoutWidget6);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_4->addWidget(lineEdit_5);

        horizontalSpacer_5 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        tabWidget_4->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        layoutWidget7 = new QWidget(tab_9);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(130, 20, 177, 22));
        horizontalLayout_23 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget7);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_23->addWidget(label_17);

        lineEdit_7 = new QLineEdit(layoutWidget7);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout_23->addWidget(lineEdit_7);

        pushButton_8 = new QPushButton(tab_9);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(170, 270, 75, 23));
        layoutWidget_2 = new QWidget(tab_9);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 100, 177, 22));
        horizontalLayout_21 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_21->addWidget(label_18);

        lineEdit_9 = new QLineEdit(layoutWidget_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        horizontalLayout_21->addWidget(lineEdit_9);

        layoutWidget_3 = new QWidget(tab_9);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(130, 200, 177, 22));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(layoutWidget_3);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_11->addWidget(label_24);

        lineEdit_12 = new QLineEdit(layoutWidget_3);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        horizontalLayout_11->addWidget(lineEdit_12);

        layoutWidget_4 = new QWidget(tab_9);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(130, 170, 177, 22));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_12->addWidget(label_23);

        lineEdit_11 = new QLineEdit(layoutWidget_4);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        horizontalLayout_12->addWidget(lineEdit_11);

        layoutWidget_5 = new QWidget(tab_9);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(130, 60, 177, 22));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_22->addWidget(label_19);

        lineEdit_8 = new QLineEdit(layoutWidget_5);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_22->addWidget(lineEdit_8);

        layoutWidget_6 = new QWidget(tab_9);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(130, 140, 177, 22));
        horizontalLayout_20 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget_6);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_20->addWidget(label_20);

        lineEdit_10 = new QLineEdit(layoutWidget_6);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        horizontalLayout_20->addWidget(lineEdit_10);

        tabWidget_4->addTab(tab_9, QString());

        verticalLayout_5->addWidget(tabWidget_4);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        TeacherWin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TeacherWin);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 779, 23));
        TeacherWin->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TeacherWin);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TeacherWin->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TeacherWin);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TeacherWin->setStatusBar(statusBar);

        retranslateUi(TeacherWin);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);
        tabWidget_3->setCurrentIndex(1);
        tabWidget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TeacherWin);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherWin)
    {
        TeacherWin->setWindowTitle(QApplication::translate("TeacherWin", "TeacherWin", 0));
        label_13->setText(QApplication::translate("TeacherWin", "\345\247\223\345\220\215\357\274\232", 0));
        label_14->setText(QApplication::translate("TeacherWin", "***", 0));
        label_15->setText(QApplication::translate("TeacherWin", "\346\225\231\345\270\210\345\267\245\345\217\267\357\274\232", 0));
        label_16->setText(QApplication::translate("TeacherWin", "0000000000", 0));
        QTableWidgetItem *___qtablewidgetitem = teacherCourses->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = teacherCourses->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = teacherCourses->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TeacherWin", "\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = teacherCourses->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TeacherWin", "\345\274\200\345\247\213\350\212\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = teacherCourses->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TeacherWin", "\347\273\223\346\235\237\350\212\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = teacherCourses->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("TeacherWin", "\344\270\212\350\257\276\345\234\260\347\202\271", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("TeacherWin", " \345\210\227\350\241\250\346\230\276\347\244\272", 0));
        QTableWidgetItem *___qtablewidgetitem6 = teacherCourses_2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("TeacherWin", "\345\221\250\344\270\200", 0));
        QTableWidgetItem *___qtablewidgetitem7 = teacherCourses_2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("TeacherWin", "\345\221\250\344\272\214", 0));
        QTableWidgetItem *___qtablewidgetitem8 = teacherCourses_2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("TeacherWin", "\345\221\250\344\270\211", 0));
        QTableWidgetItem *___qtablewidgetitem9 = teacherCourses_2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("TeacherWin", "\345\221\250\345\233\233", 0));
        QTableWidgetItem *___qtablewidgetitem10 = teacherCourses_2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("TeacherWin", "\345\221\250\344\272\224", 0));
        QTableWidgetItem *___qtablewidgetitem11 = teacherCourses_2->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("TeacherWin", "\345\221\250\345\205\255", 0));
        QTableWidgetItem *___qtablewidgetitem12 = teacherCourses_2->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("TeacherWin", "\345\221\250\346\227\245", 0));
        QTableWidgetItem *___qtablewidgetitem13 = teacherCourses_2->verticalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("TeacherWin", "1", 0));
        QTableWidgetItem *___qtablewidgetitem14 = teacherCourses_2->verticalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("TeacherWin", "2", 0));
        QTableWidgetItem *___qtablewidgetitem15 = teacherCourses_2->verticalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("TeacherWin", "3", 0));
        QTableWidgetItem *___qtablewidgetitem16 = teacherCourses_2->verticalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("TeacherWin", "4", 0));
        QTableWidgetItem *___qtablewidgetitem17 = teacherCourses_2->verticalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("TeacherWin", "5", 0));
        QTableWidgetItem *___qtablewidgetitem18 = teacherCourses_2->verticalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("TeacherWin", "6", 0));
        QTableWidgetItem *___qtablewidgetitem19 = teacherCourses_2->verticalHeaderItem(6);
        ___qtablewidgetitem19->setText(QApplication::translate("TeacherWin", "7", 0));
        QTableWidgetItem *___qtablewidgetitem20 = teacherCourses_2->verticalHeaderItem(7);
        ___qtablewidgetitem20->setText(QApplication::translate("TeacherWin", "8", 0));
        QTableWidgetItem *___qtablewidgetitem21 = teacherCourses_2->verticalHeaderItem(8);
        ___qtablewidgetitem21->setText(QApplication::translate("TeacherWin", "9", 0));
        QTableWidgetItem *___qtablewidgetitem22 = teacherCourses_2->verticalHeaderItem(9);
        ___qtablewidgetitem22->setText(QApplication::translate("TeacherWin", "10", 0));
        QTableWidgetItem *___qtablewidgetitem23 = teacherCourses_2->verticalHeaderItem(10);
        ___qtablewidgetitem23->setText(QApplication::translate("TeacherWin", "11", 0));
        QTableWidgetItem *___qtablewidgetitem24 = teacherCourses_2->verticalHeaderItem(11);
        ___qtablewidgetitem24->setText(QApplication::translate("TeacherWin", "12", 0));
        QTableWidgetItem *___qtablewidgetitem25 = teacherCourses_2->verticalHeaderItem(12);
        ___qtablewidgetitem25->setText(QApplication::translate("TeacherWin", "13", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("TeacherWin", "\350\241\250\346\240\274\346\230\276\347\244\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TeacherWin", "\346\210\221\347\232\204\350\257\276\350\241\250", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem26->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem28->setText(QApplication::translate("TeacherWin", "\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem29->setText(QApplication::translate("TeacherWin", "\345\274\200\345\247\213\350\212\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem30->setText(QApplication::translate("TeacherWin", "\347\273\223\346\235\237\350\212\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem31->setText(QApplication::translate("TeacherWin", "\346\234\200\345\244\247\345\256\271\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem32->setText(QApplication::translate("TeacherWin", "\347\216\260\346\234\211\345\256\271\351\207\217", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("TeacherWin", "\351\200\211\350\257\276\346\203\205\345\206\265", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem33->setText(QApplication::translate("TeacherWin", "\345\255\246\347\224\237\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem34->setText(QApplication::translate("TeacherWin", "\345\255\246\347\224\237\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem35->setText(QApplication::translate("TeacherWin", "\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem36->setText(QApplication::translate("TeacherWin", "\345\271\264\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem37->setText(QApplication::translate("TeacherWin", "\346\210\220\347\273\251", 0));
        pushButton->setText(QApplication::translate("TeacherWin", "\346\210\220\347\273\251\345\275\225\345\205\245", 0));
        label->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\347\274\226\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\345\220\215\347\247\260\357\274\232", 0));
        pushButton_2->setText(QApplication::translate("TeacherWin", "\346\220\234\347\264\242", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("TeacherWin", "\345\220\215\345\215\225\347\256\241\347\220\206", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("TeacherWin", "\350\257\276\347\250\213\347\256\241\347\220\206", 0));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QApplication::translate("TeacherWin", "\344\270\223\344\270\232", 0));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\344\273\213\347\273\215", 0));
        label_3->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\347\274\226\345\217\267\357\274\232", 0));
        label_4->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\345\220\215\347\247\260\357\274\232", 0));
        label_9->setText(QApplication::translate("TeacherWin", "\350\257\276\347\250\213\344\273\213\347\273\215\357\274\232", 0));
        pushButton_4->setText(QApplication::translate("TeacherWin", "\346\217\220\345\207\272\347\224\263\350\257\267", 0));
        pushButton_5->setText(QApplication::translate("TeacherWin", "\346\270\205\347\251\272", 0));
        pushButton_6->setText(QApplication::translate("TeacherWin", "\345\210\240\351\231\244\350\257\276\347\250\213", 0));
        label_5->setText(QApplication::translate("TeacherWin", "\344\270\223\344\270\232\357\274\232", 0));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_8), QApplication::translate("TeacherWin", "\350\257\276\347\250\213\344\277\241\346\201\257", 0));
        label_17->setText(QApplication::translate("TeacherWin", "\345\267\245\345\217\267", 0));
        pushButton_8->setText(QApplication::translate("TeacherWin", " \346\211\247\350\241\214\344\277\256\346\224\271", 0));
        label_18->setText(QApplication::translate("TeacherWin", "\350\201\214\347\247\260\357\274\232", 0));
        label_24->setText(QApplication::translate("TeacherWin", "\351\202\256\347\256\261\357\274\232", 0));
        label_23->setText(QApplication::translate("TeacherWin", "\347\224\265\350\257\235\357\274\232", 0));
        label_19->setText(QApplication::translate("TeacherWin", "\345\247\223\345\220\215\357\274\232", 0));
        label_20->setText(QApplication::translate("TeacherWin", "\344\270\223\344\270\232\357\274\232", 0));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QApplication::translate("TeacherWin", "\344\270\252\344\272\272\344\277\241\346\201\257", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TeacherWin", "\344\270\252\344\272\272\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class TeacherWin: public Ui_TeacherWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWIN_H
