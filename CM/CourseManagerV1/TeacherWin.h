#ifndef TEACHERWIN_H
#define TEACHERWIN_H

#include <QtWidgets/QMainWindow>
#include "ui_TeacherWin.h"

class TeacherWin : public QMainWindow
{
	Q_OBJECT

public:
	TeacherWin(QWidget *parent = 0);
	~TeacherWin();

private:
	Ui::TeacherWin ui;

public:
    void setDefaultPerInfo(int role);
    void setDefaultSchedule();
    void setDefaultApply();
    void setUserName(QString username, int role);
    int getScheduleCol(std::string date);
    int getTime(std::string time);
    void setDefaultAllSelection();
private slots:
    void on_tabWidget_tabBarClicked(int index);
    void on_tabWidget_3_tabBarClicked(int index);
    void on_pushButton_8_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_tabWidget_4_tabBarClicked(int index);
    void on_tabWidget_2_tabBarClicked(int index);
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_clicked();
};

#endif // TEACHERWIN_H
