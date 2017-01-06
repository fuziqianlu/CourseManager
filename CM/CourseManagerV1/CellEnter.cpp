#include "CellEnter.h"

CellEnter::CellEnter(QTreeWidgetItem* rowid,QWidget *parent)
: QWidget(parent), rowid(rowid)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onBtnEnter()));
}

CellEnter::~CellEnter()
{

}
int CellEnter::onBtnEnter()
{
	emit studentEnter(rowid);
	return 0;
}