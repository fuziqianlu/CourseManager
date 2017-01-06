#include "LoginWindow.h"
#include "RegisterWin.h"
#include "cskernel.h"
extern kernel Kernel;

LoginWindow::LoginWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(onBtnOKClicked()));
//	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onBtnRegisterClicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(onBtnCancelClicked()));
}

LoginWindow::~LoginWindow()
{

}

int LoginWindow::onBtnOKClicked()
{
//关于登录验证的代码
    if (ui.radioButton1->isChecked())
    {
        id = 1;
    }
    else if (ui.radioButton_2->isChecked())
    {
        id = 2;
    }
    else
    {
        id = 3;
    }
    user = ui.userEdit->text();
    password = ui.PasswordLine->text();

    int status = Kernel.logIn(user.toStdString(),password.toStdString(),id);
    if(status != -1) accept();
    else{
        QMessageBox::warning(0, qApp->tr("Fail To Log In"),
            qApp->tr("Account not exist or wrong password!"
                      ), QMessageBox::Cancel);
    }
    return 0;

}
//int LoginWindow::onBtnRegisterClicked()
//{
//	RegisterWin redialog(this);
//	int ret = redialog.exec();
//	if (ret == QDialog::Accepted)
//	{
//		ui.userEdit->setText(redialog.r_user);
//		ui.PasswordLine->setText(redialog.r_password);
//
//	}
//	return 0;
//
//}
int LoginWindow::onBtnCancelClicked()
{
	reject();
	return 0;
}
