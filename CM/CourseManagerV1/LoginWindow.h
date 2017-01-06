#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QtWidgets/QDialog>
#include "ui_LoginWindow.h"

class LoginWindow : public QDialog
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private:
	Ui::LoginWindow ui;

private slots:
	int onBtnOKClicked();
//	int onBtnRegisterClicked();
	int onBtnCancelClicked();

public:
	QString user;
	QString password;
	int id;
};

#endif // LOGINWINDOW_H
