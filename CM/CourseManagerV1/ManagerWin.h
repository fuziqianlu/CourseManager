#ifndef MANAGERWIN_H
#define MANAGERWIN_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QCheckBox>
#include "ui_ManagerWin.h"
#include "RegisterWin.h"

class ManagerWin : public QMainWindow
{
	Q_OBJECT

public:
	ManagerWin(QWidget *parent = 0);
	~ManagerWin();

private:
	Ui::ManagerWin ui;

public:
    void setUserName(QString username, int role);
    void setDefaultPerInfo(int role);
    void setDefaultApply();
    void setDefaultStu();
    void setDefaultTea();
    void setDefaultAdm();
    void setDefaultCourse();
    void addApplyList(const QString& courseid,
                     const QString& teaid,
                     const QString& coursename,
                     const QString& dept,
                     const QString& desc
                     );
    void addStuList(const QString& id,
                     const QString& name,
                     const QString& grade,
                     const QString& clas,
                     const QString& phone,
                     const QString& email
                    );
    void addTeaList(const QString& id,
                     const QString& name,
                     const QString& prof,
                     const QString& phone,
                     const QString& email,
                    const QString& dept
                    );
    void addAdmList(const QString& id,
                     const QString& name,
                     const QString& phone,
                     const QString& email,
                    const QString& dept
                    );
    void addCourseList(const QString& courseid,
                       const QString& coursename,
                       const QString& dept,
                       const QString& desc
                        );

private slots:
	int onDeleteApplication();
	int onPassApplication();
	int onDeleteStudent();
	int onDeleteTeacher();
	int onDeleteCourse();
	int onRegisterStudent();
	int onRegisterTeacher();
	int onAddManager();
	int onDeleteManager();

    void on_pushButton_3_clicked();
    void on_pushButton_11_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_tabWidget_3_tabBarClicked(int index);
    void on_pushButton_25_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_24_clicked();
};

#endif // MANAGERWIN_H
