#ifndef CELLCHOOSE_H
#define CELLCHOOSE_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QTreeWidget>
#include "ui_CellChoose.h"

class CellChoose : public QWidget
{
	Q_OBJECT

signals:
	int choosingCourse(QTreeWidgetItem * rowid);
	int discardingCourse(QTreeWidgetItem * rowid);

public:
	CellChoose(QTreeWidgetItem * rowid,QWidget *parent = 0);
	~CellChoose();
    void setChecked(bool state);
    bool getChecked();

private:
	Ui::CellChoose ui;
	QTreeWidgetItem * rowid;

	private slots:
	int onCheckboxChanged();
};

#endif // CELLCHOOSE_H
