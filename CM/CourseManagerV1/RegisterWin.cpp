#include "RegisterWin.h"
#include "cskernel.h"
extern kernel Kernel;
RegisterWin::RegisterWin(int type, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    this->type = type;
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onbtnReClicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(onbtnCancelClicked()));
}

RegisterWin::~RegisterWin()
{

}

int RegisterWin::onbtnReClicked()
{
    QString name = ui.lineEdit_5->text();
    QString user = ui.lineEdit->text();
    QString passwd = ui.lineEdit_2->text();
    QString email = ui.lineEdit_7->text();
    QString phone = ui.lineEdit_4->text();
    QString profcla = ui.lineEdit_3->text();
    QString deptgra = ui.lineEdit_6->text();
    int type;
    bool status;
    if (ui.radioButton->isChecked())
    {
        type = 1;
    }
    else if (ui.radioButton_2->isChecked())
    {
        type = 2;
    }
    else
    {
        type = 3;
    }


    if(type == 1){
        status = Kernel.createStu(name.toStdString(),
                                  user.toStdString(),
                                  passwd.toStdString(),
                                  email.toStdString(),
                                  phone.toStdString(),
                                  profcla.toStdString(),
                                  deptgra.toStdString());
    }else if(type == 2){
        status = Kernel.createTea(name.toStdString(),
                                  user.toStdString(),
                                  passwd.toStdString(),
                                  email.toStdString(),
                                  phone.toStdString(),
                                  profcla.toStdString(),
                                  deptgra.toStdString());
    }else{
        status = Kernel.createAdm(name.toStdString(),
                                  user.toStdString(),
                                  passwd.toStdString(),
                                  email.toStdString(),
                                  phone.toStdString(),
                                  deptgra.toStdString());
    }
    if(status){
        QMessageBox::about(NULL, "Create Success", "NewUser accepted!");
    }else
        QMessageBox::warning(NULL, "Create Fails", "NewUser not accepted!");

	accept();
	return 0;
}
int RegisterWin::onbtnCancelClicked()
{
	reject();
	return 0;
}


