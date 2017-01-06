#ifndef CELLENTER_H
#define CELLENTER_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QTreeWidget>
#include "ui_CellEnter.h"

class CellEnter : public QWidget
{
	Q_OBJECT

signals:
	int studentEnter(QTreeWidgetItem* rowid);

public:
	CellEnter(QTreeWidgetItem* rowid,QWidget *parent = 0);
	~CellEnter();

private:
	Ui::CellEnter ui;
	QTreeWidgetItem* rowid;

	private slots:
	int onBtnEnter();
};

#endif // CELLENTER_H
