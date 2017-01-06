#include "TeacherWin.h"
#include "cskernel.h"
extern kernel Kernel;

TeacherWin::TeacherWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    ui.lineEdit_7->setEnabled(false);
    ui.lineEdit_8->setEnabled(false);
    ui.lineEdit_9->setEnabled(false);
    ui.lineEdit_10->setEnabled(false);
}

TeacherWin::~TeacherWin()
{

}

int TeacherWin::getScheduleCol(string date){
    int res;

    if(QString::fromStdString(date) == QString::fromLocal8Bit("周一"))
        res = 0;
    else if(QString::fromStdString(date) == QString::fromLocal8Bit("周二"))
        res = 1;
    else if(QString::fromStdString(date) == QString::fromLocal8Bit("周三"))
        res = 2;
    else if(QString::fromStdString(date) == QString::fromLocal8Bit("周四"))
        res = 3;
    else if(QString::fromStdString(date) == QString::fromLocal8Bit("周五"))
        res = 4;
    else if(QString::fromStdString(date) == QString::fromLocal8Bit("周六"))
        res = 5;
    else
        res = 6;

    return res;
}

int TeacherWin::getTime(string time){
    int res = 0;

    for(int i = 0; i < time.size(); i++){
        res = res * 10 + time[i] - 48;
    }

    return res;
}


void TeacherWin::setUserName(QString username, int role)
{
//	ui.label_11->setText(username);
    ui.label_16->setText(username);
    bool status = Kernel.getUserName(role);
    if(status)
        ui.label_14->setText(QString::fromStdString(Kernel.getName(role)));
    else
        ui.label_14->setText(QString::fromStdString("NO RECORD"));
}

void TeacherWin::setDefaultPerInfo(int role){
    bool status;
    vector<string> row;

    status = Kernel.getPersonInfo(role);
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.lineEdit_7->setText(QString::fromStdString(row[0]));
            ui.lineEdit_8->setText(QString::fromStdString(row[1]));
            ui.lineEdit_9->setText(QString::fromStdString(row[2]));
            ui.lineEdit_10->setText(QString::fromStdString(row[3]));
            ui.lineEdit_11->setText(QString::fromStdString(row[4]));
            ui.lineEdit_12->setText(QString::fromStdString(row[5]));
        }
    }
    qDebug() << status;
}

void TeacherWin::setDefaultSchedule()
{
    string id = Kernel.getUserID();
    bool status;
    vector<string> row;
    ui.teacherCourses->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.teacherCourses_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    status = Kernel.getTeaSchedule(id);
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.teacherCourses->insertRow(i);
            ui.teacherCourses->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.teacherCourses->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.teacherCourses->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[6])));
            ui.teacherCourses->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[7])));
            ui.teacherCourses->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[8])));
            ui.teacherCourses->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[9])));

            for(int j = getTime(row[7]); j <= getTime(row[8]); j++){
                ui.teacherCourses_2->setItem(j - 1,getScheduleCol(row[6]),new QTableWidgetItem(QString::fromStdString(row[1])));
            }

            ui.teacherCourses->show();
            ui.teacherCourses_2->show();
        }
    }
    qDebug() << status;
}

void TeacherWin::setDefaultApply()
{
    string id = Kernel.getUserID();
    bool status;
    vector<string> row;

    status = Kernel.getTeaApply(id);
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.tableWidget_3->insertRow(i);
            ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));
            ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
        }
    }
    qDebug() << status;
}

void TeacherWin::setDefaultAllSelection()
{
    string id = Kernel.getUserID();
    bool status;
    vector<string> row;
    ui.tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    status = Kernel.getTeaSchedule(id);
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.tableWidget_2->insertRow(i);
            ui.tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[6])));
            ui.tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[7])));
            ui.tableWidget_2->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[8])));
            ui.tableWidget_2->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[4])));
            ui.tableWidget_2->setItem(i,6,new QTableWidgetItem(QString::fromStdString(row[5])));

            ui.tableWidget_2->show();
        }
    }
    qDebug() << status;
}




void TeacherWin::on_tabWidget_tabBarClicked(int index)
{
    ui.teacherCourses->setRowCount(0);
    ui.teacherCourses->clearContents();
    ui.tableWidget_2->setRowCount(0);
    ui.tableWidget_2->clearContents();
    ui.tableWidget_3->setRowCount(0);
    ui.tableWidget_3->clearContents();
    ui.teacherCourses_2->clearContents();
    ui.teacherCourses->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.teacherCourses_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

    string id = Kernel.getUserID();
    bool status;
    vector<string> row;

    if(index == 0){
        status = Kernel.getTeaSchedule(id);
        if(status){
            for(int i = 0; i < Kernel.getTeaRnum(); i++){
                row = Kernel.getTeaRow(i);
                ui.teacherCourses->insertRow(i);
                ui.teacherCourses->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
                qDebug() <<QString::fromStdString(row[0]);
                ui.teacherCourses->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
                ui.teacherCourses->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[6])));
                ui.teacherCourses->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[7])));
                ui.teacherCourses->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[8])));
                ui.teacherCourses->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[9])));

                for(int j = getTime(row[7]); j <= getTime(row[8]); j++){
                    ui.teacherCourses_2->setItem(j - 1,getScheduleCol(row[6]),new QTableWidgetItem(QString::fromStdString(row[1])));
                }

                ui.teacherCourses->show();
                ui.teacherCourses_2->show();
            }
        }
        qDebug() << status;
    }else if(index == 1){
        status = Kernel.getTeaSchedule(id);
        if(status){
            for(int i = 0; i < Kernel.getTeaRnum(); i++){
                row = Kernel.getTeaRow(i);
                ui.tableWidget_2->insertRow(i);
                ui.tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
                qDebug() <<QString::fromStdString(row[0]);
                ui.tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
                ui.tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[6])));
                ui.tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[7])));
                ui.tableWidget_2->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[8])));
                ui.tableWidget_2->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[4])));
                ui.tableWidget_2->setItem(i,6,new QTableWidgetItem(QString::fromStdString(row[5])));

                ui.tableWidget_2->show();
            }
        }
        qDebug() << status;
    }else if(index == 2){
        status = Kernel.getPersonInfo(Kernel.getRole());
        if(status){
            for(int i = 0; i < Kernel.getTeaRnum(); i++){
                row = Kernel.getTeaRow(i);
                ui.lineEdit_7->setText(QString::fromStdString(row[0]));
                ui.lineEdit_8->setText(QString::fromStdString(row[1]));
                ui.lineEdit_9->setText(QString::fromStdString(row[2]));
                ui.lineEdit_10->setText(QString::fromStdString(row[5]));
                ui.lineEdit_11->setText(QString::fromStdString(row[3]));
                ui.lineEdit_12->setText(QString::fromStdString(row[4]));
            }
        }

        status = Kernel.getTeaApply(id);
        if(status){
            for(int i = 0; i < Kernel.getTeaRnum(); i++){
                row = Kernel.getTeaRow(i);
                ui.tableWidget_3->insertRow(i);
                ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
                qDebug() <<QString::fromStdString(row[0]);
                ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
                ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));
                ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
            }
        }
        qDebug() << status;
    }
}
void TeacherWin::on_tabWidget_3_tabBarClicked(int index){
    ui.tableWidget_2->setRowCount(0);
    ui.tableWidget_2->clearContents();
    ui.tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    string id = Kernel.getUserID();
    bool status;
    vector<string> row;

    status = Kernel.getTeaSchedule(id);
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.tableWidget_2->insertRow(i);
            ui.tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[6])));
            ui.tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[7])));
            ui.tableWidget_2->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[8])));
            ui.tableWidget_2->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[4])));
            ui.tableWidget_2->setItem(i,6,new QTableWidgetItem(QString::fromStdString(row[5])));

            ui.tableWidget_2->show();
        }
    }
    qDebug() << status;

}

void TeacherWin::on_pushButton_2_clicked()
{
    ui.tableWidget->setRowCount(0);
    ui.tableWidget->clearContents();

    QString courseid = ui.lineEdit_3->text();
    QString coursename = ui.lineEdit_4->text();

    bool status;
    vector<string> row;

    status = Kernel.getTeaStuList(courseid.toStdString(), coursename.toStdString(), Kernel.getUserID());
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.tableWidget->insertRow(i);
            ui.tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));
            ui.tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
            ui.tableWidget->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[4])));

            ui.tableWidget->show();
        }
        ui.lineEdit_3->setEnabled(false);
        ui.lineEdit_4->setEnabled(false);
        ui.tableWidget->setEnabled(true);
    }
    qDebug() << status;
}

void TeacherWin::on_pushButton_5_clicked()
{
    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.lineEdit_5->clear();
    ui.plainTextEdit->clear();
}

void TeacherWin::on_tabWidget_4_tabBarClicked(int index)
{
    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.lineEdit_5->clear();
    ui.plainTextEdit->clear();

    ui.tableWidget_3->setRowCount(0);
    ui.tableWidget_3->clearContents();
    ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

    bool status;
    vector<string> row;

    status = Kernel.getPersonInfo(Kernel.getRole());
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.lineEdit_7->setText(QString::fromStdString(row[0]));
            ui.lineEdit_8->setText(QString::fromStdString(row[1]));
            ui.lineEdit_9->setText(QString::fromStdString(row[2]));
            ui.lineEdit_10->setText(QString::fromStdString(row[5]));
            ui.lineEdit_11->setText(QString::fromStdString(row[3]));
            ui.lineEdit_12->setText(QString::fromStdString(row[4]));
        }
    }

    status = Kernel.getTeaApply(Kernel.getUserID());
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.tableWidget_3->insertRow(i);
            ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));
            ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
        }
    }
    qDebug() << status;
}

void TeacherWin::on_tabWidget_2_tabBarClicked(int index)
{
    ui.teacherCourses->setRowCount(0);
    ui.teacherCourses->clearContents();
    ui.teacherCourses_2->clearContents();
    ui.teacherCourses->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.teacherCourses_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    string id = Kernel.getUserID();
    bool status;
    vector<string> row;

    status = Kernel.getTeaSchedule(id);
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.teacherCourses->insertRow(i);
            ui.teacherCourses->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.teacherCourses->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.teacherCourses->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[6])));
            ui.teacherCourses->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[7])));
            ui.teacherCourses->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[8])));
            ui.teacherCourses->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[9])));

            for(int j = getTime(row[7]); j <= getTime(row[8]); j++){
                ui.teacherCourses_2->setItem(j - 1,getScheduleCol(row[6]),new QTableWidgetItem(QString::fromStdString(row[1])));
            }

            ui.teacherCourses->show();
            ui.teacherCourses_2->show();
        }
    }
    qDebug() << status;
}

void TeacherWin::on_pushButton_4_clicked()
{
    QString courseid = ui.lineEdit->text();;
    QString coursename = ui.lineEdit_2->text();;
    QString dept = ui.lineEdit_5->text();
    QString desc = ui.plainTextEdit->document()->toPlainText();

    bool status;
    vector<string> row;

    status = Kernel.applyTeaNewCourse(courseid.toStdString(),
                                      coursename.toStdString(),
                                      dept.toStdString(),
                                      desc.toStdString(),
                                      Kernel.getUserID());
    if(status)
        QMessageBox::about(NULL, "Apply Success", "Wait for admission!");
    else
        QMessageBox::warning(NULL, "Apply Fail", "Can't apply. Try again!");

    ui.tableWidget_3->setRowCount(0);
    ui.tableWidget_3->clearContents();
    ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    status = Kernel.getTeaApply(Kernel.getUserID());
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.tableWidget_3->insertRow(i);
            ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));
            ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
        }
    }
    qDebug() << status;
}

void TeacherWin::on_pushButton_6_clicked()
{
    QString courseid = ui.tableWidget_3->item(ui.tableWidget_3->currentRow(),0)->text();

    bool status;
    vector<string> row;

    status = Kernel.deleteTeaNewCourse(courseid.toStdString(),Kernel.getUserID());
    if(status)
        QMessageBox::about(NULL, "Delete Success", "Apply deleted!");
    else
        QMessageBox::warning(NULL, "Delete Fail", "Apply can't be deleted!");

    ui.tableWidget_3->setRowCount(0);
    ui.tableWidget_3->clearContents();
    ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    status = Kernel.getTeaApply(Kernel.getUserID());
    if(status){
        for(int i = 0; i < Kernel.getTeaRnum(); i++){
            row = Kernel.getTeaRow(i);
            ui.tableWidget_3->insertRow(i);
            ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));
            ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
        }
    }
    qDebug() << status;
}


void TeacherWin::on_pushButton_8_clicked()
{
    bool status;
    vector<string> ps;

    QString name = ui.lineEdit_11->text();
    ps.push_back(name.toStdString());
    name =ui.lineEdit_12->text();
    ps.push_back(name.toStdString());

    status = Kernel.updatePersonInfo(Kernel.getRole(), ps);
    if(status == true)
        QMessageBox::about(NULL, "Update success","Info updated!");
    else
        QMessageBox::warning(NULL, "Update Fail", "Fail to update Info!");

    status = Kernel.getUserName(Kernel.getRole());
    if(status)
        ui.label_14->setText(QString::fromStdString(Kernel.getName(Kernel.getRole())));
    else
        ui.label_14->setText(QString::fromStdString("NO RECORD"));
}

void TeacherWin::on_pushButton_clicked()
{
    bool status;
    vector<string> cs;
    string score;

    QString name = ui.lineEdit_3->text();
    cs.push_back(name.toStdString());
    name = ui.label_16->text();
    cs.push_back(name.toStdString());

    for(int i = 0; i < ui.tableWidget->rowCount(); i++){
        name = ui.tableWidget->item(i,0)->text();
        cs.push_back(name.toStdString());
        score = ui.tableWidget->item(i,4)->text().toStdString();;
        status = Kernel.updateScore(score, cs);
        if(status == false){
            QMessageBox::warning(NULL, "Update Fail", "Fail to update Score!");
            break;
        }
        cs.pop_back();
    }
    if(status == true){
        QMessageBox::about(NULL, "Update Success", "Score all Updated!");
    }
    else{
        QMessageBox::warning(NULL, "Update Fail", "Fail to update all Score!");
    }

    ui.lineEdit_3->setEnabled(true);
    ui.lineEdit_4->setEnabled(true);
    ui.tableWidget->setEnabled(false);
}
