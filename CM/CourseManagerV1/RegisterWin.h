#ifndef REGISTERWIN_H
#define REGISTERWIN_H

#include <QtWidgets/QDialog>
#include "ui_RegisterWin.h"

class RegisterWin : public QDialog
{
	Q_OBJECT

public:
    RegisterWin(int type, QWidget *parent = 0);
	~RegisterWin();

private:
	Ui::RegisterWin ui;

private slots:
	int onbtnReClicked();
	int onbtnCancelClicked();

public:
	QString r_user;
	QString r_password;
    int type;
};

#endif // REGISTERWIN_H
