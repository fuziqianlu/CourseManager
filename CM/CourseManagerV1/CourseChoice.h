#ifndef COURSECHOICE_H
#define COURSECHOICE_H

#include <QtWidgets/QWidget>
#include "ui_CourseChoice.h"
#include "CellChoose.h"
#include <QtWidgets/QMessageBox>

class CourseChoice : public QWidget
{
	Q_OBJECT

public:
    CourseChoice(const QString& courseid = "",
                 const QString &coursename = "",
                 const QString &teaname = "",
                 const QString &day = "",
                 const QString &start = "",
                 const QString &end = "",
                 const QString &pos = "",
                 const QString &capacity = "",
                 const QString &current = "",
                 std::string id = "",
                 QWidget *parent = 0);
	~CourseChoice();
    void addCourseChoice(const QString& courseid, const QString &coursename, const QString &teaname, const QString &day, const QString &start, const QString &end, const QString &pos, const QString &capacity, const QString &current, bool status);

private:
	Ui::CourseChoice ui;
//    bool choice;
//    int rowid;

	private slots:
	int onCourseIsChoosed(QTreeWidgetItem* rowid);
	int onCourseIsDiscarded(QTreeWidgetItem* rowid);
	int onBtnClose();

};

#endif // COURSECHOICE_H
