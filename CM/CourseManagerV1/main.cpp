#include "educationmanager.h"
#include "TeacherWin.h"
#include "LoginWindow.h"
#include "ManagerWin.h"
#include "cskernel.h"
#include <QtWidgets/QApplication>

string kernel::logfile = "LOG";
kernel Kernel;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TeacherWin w;
	educationManager edu;
	ManagerWin mana;

    if (!createConn())
        return 1;

    Kernel.start();

	LoginWindow login;
	int ret1 = login.exec();

	if (ret1 == QDialog::Accepted&&login.id==2)
	{
		w.show();
        w.setUserName(login.user,login.id);
        w.setDefaultPerInfo(login.id);
        w.setDefaultSchedule();
        w.setDefaultAllSelection();
        w.setDefaultApply();
	}
	else if (ret1 == QDialog::Accepted&&login.id == 1)
	{
		edu.show();
        edu.setUserName(login.user,login.id);
        edu.setDefaultSchedule();
        edu.setDefaultAllCourse();
        edu.setDefaultPerInfo(login.id);
	}
	else if (ret1 == QDialog::Accepted&&login.id == 3)
	{
		mana.show();
        mana.setUserName(login.user, login.id);
        mana.setDefaultPerInfo(login.id);
        mana.setDefaultApply();
        mana.setDefaultStu();
        mana.setDefaultTea();
        mana.setDefaultAdm();
        mana.setDefaultCourse();
	}
	
	return a.exec();
}
