#ifndef EDUCATIONMANAGER_H
#define EDUCATIONMANAGER_H

#include <QtWidgets/QMainWindow>
#include "ui_educationmanager.h"
#include "CellEnter.h"
#include "CourseChoice.h"
#include <string>
#include <QtWidgets/QTreeWidget>


class educationManager : public QMainWindow
{
	Q_OBJECT

public:
	educationManager(QWidget *parent = 0);
	~educationManager();


private:
	Ui::educationManagerClass ui;

	private slots:
	int onEnterClicked(QTreeWidgetItem* item);

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void on_tabWidget_5_tabBarClicked(int index);

public:
    void setDefaultPerInfo(int role);
    void setDefaultAllCourse();
    void setDefaultSchedule();

    void addCourseList(const QString& courseid,
                       const QString& coursename,
                       const QString& teaname,
                       const QString& day,
                       const QString& start,
                       const QString& end,
                       const QString& pos,
                       const QString& capacity,
                       const QString& current);
    void setUserName(QString username, int role);
    int getScheduleCol(std::string date);
    int getTime(std::string time);
};

#endif // EDUCATIONMANAGER_H
