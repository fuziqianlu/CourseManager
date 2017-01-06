#include "CellChoose.h"

CellChoose::CellChoose(QTreeWidgetItem * rowid,QWidget *parent)
: QWidget(parent), rowid(rowid)
{
	ui.setupUi(this);
	connect(ui.checkBox, SIGNAL(stateChanged(int)), this, SLOT(onCheckboxChanged()));
}

CellChoose::~CellChoose()
{

}

void CellChoose::setChecked(bool state){
    if(state == true)
        ui.checkBox->setCheckState(Qt::Checked);
    else
        ui.checkBox->setCheckState(Qt::Unchecked);
}

bool CellChoose::getChecked(){
    if(ui.checkBox->checkState() == Qt::Checked)
        return true;
    else
        return false;
}

int CellChoose::onCheckboxChanged()
{
	if (ui.checkBox->isChecked())
	{
		emit choosingCourse(rowid);
	}
	else
	{
		emit discardingCourse(rowid);
	}

	return 0;
}
