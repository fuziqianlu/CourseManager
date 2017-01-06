#include "educationmanager.h"
#include "cskernel.h"
#include <string>
extern kernel Kernel;
educationManager::educationManager(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    ui.lineEdit_7->setEnabled(false);
    ui.lineEdit_8->setEnabled(false);
    ui.lineEdit_9->setEnabled(false);
    ui.lineEdit_10->setEnabled(false);
}

educationManager::~educationManager()
{

}

int educationManager::getScheduleCol(string date){
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

int educationManager::getTime(string time){
    int res = 0;

    for(int i = 0; i < time.size(); i++){
        res = res * 10 + time[i] - 48;
    }

    return res;
}


void educationManager::setUserName(QString username, int role)
{
//	ui.label_11->setText(username);
	ui.label_15->setText(username);
    bool status = Kernel.getUserName(role);
    if(status)
        ui.label_11->setText(QString::fromStdString(Kernel.getName(role)));
    else
        ui.label_11->setText(QString::fromStdString("NO RECORD"));
}

void educationManager::setDefaultPerInfo(int role){
    bool status;
    vector<string> row;

    status = Kernel.getPersonInfo(role);
    if(status){
        for(int i = 0; i < Kernel.getStuRnum(); i++){
            row = Kernel.getStuRow(i);
            ui.lineEdit_7->setText(QString::fromStdString(row[0]));
            ui.lineEdit_8->setText(QString::fromStdString(row[1]));
            ui.lineEdit_9->setText(QString::fromStdString(row[3]));
            ui.lineEdit_10->setText(QString::fromStdString(row[2]));
            ui.lineEdit_11->setText(QString::fromStdString(row[4]));
            ui.lineEdit_12->setText(QString::fromStdString(row[5]));
        }
    }
    qDebug() << status;
}

void educationManager::setDefaultAllCourse(){
    bool status;
    vector<string> row;
    ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    status = Kernel.getStuAllCourseInfo();
    if(status){
        for(int i = 0; i < Kernel.getStuRnum(); i++){
            row = Kernel.getStuRow(i);
            ui.tableWidget_3->insertRow(i);
            ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));

            if(row.size() == 4){
                ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
            }else{
                ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString("No Description!")));
            }

            ui.tableWidget_3->show();
        }
    }
    qDebug() << status;
}

void educationManager::setDefaultSchedule()
{
    string id = Kernel.getUserID();
    bool status;
    vector<string> row;
    ui.tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);
    status = Kernel.getStuSchedule(id);
    if(status){
        for(int i = 0; i < Kernel.getStuRnum(); i++){
            row = Kernel.getStuRow(i);
            ui.tableWidget_4->insertRow(i);
            ui.tableWidget_4->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_4->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_4->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[5])));
            ui.tableWidget_4->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[6])));
            ui.tableWidget_4->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[7])));
            ui.tableWidget_4->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[8])));
            ui.tableWidget_4->setItem(i,6,new QTableWidgetItem(QString::fromStdString(row[9])));

            for(int j = getTime(row[7]); j <= getTime(row[8]); j++){
                ui.tableWidget_7->setItem(j - 1,getScheduleCol(row[6]),new QTableWidgetItem(QString::fromStdString(row[1])));
            }

            ui.tableWidget_4->show();
            ui.tableWidget_7->show();
        }
    }
    qDebug() << status;
}

void educationManager::addCourseList(const QString& courseid,
                                     const QString& coursename,
                                     const QString& teaname,
                                     const QString& day,
                                     const QString& start,
                                     const QString& end,
                                     const QString& pos,
                                     const QString& capacity,
                                     const QString& current
                                     )//用来向表格里添加项目的函数，要设定剩下的几列数据的话，增加这里的形参
{
	QTreeWidgetItem* item = new QTreeWidgetItem();
	item->setText(0, courseid);//0是列数，剩下几列也可以这样设计
    item->setText(1, coursename);//0是列数，剩下几列也可以这样设计
    item->setText(2, teaname);//0是列数，剩下几列也可以这样设计
    item->setText(3, day);//0是列数，剩下几列也可以这样设计
    item->setText(4, start);//0是列数，剩下几列也可以这样设计
    item->setText(5, end);//0是列数，剩下几列也可以这样设计
    item->setText(6, pos);//0是列数，剩下几列也可以这样设计
    item->setText(7, capacity);//0是列数，剩下几列也可以这样设计
    item->setText(8, current);//0是列数，剩下几列也可以这样设计
    ui.treeWidget->addTopLevelItem(item);

	CellEnter* widget = new CellEnter(item);
    ui.treeWidget->setItemWidget(item, 9, widget);
	connect(widget, SIGNAL(studentEnter(QTreeWidgetItem*)), this, SLOT(onEnterClicked(QTreeWidgetItem*)));
}

int educationManager::onEnterClicked(QTreeWidgetItem* item)//点击进入选课以后，打开选课列表
{


    CourseChoice *cc=new CourseChoice(item->text(0),
                                      item->text(1),
                                      item->text(2),
                                      item->text(3),
                                      item->text(4),
                                      item->text(5),
                                      item->text(6),
                                      item->text(7),
                                      item->text(8),
                                      Kernel.getUserID());//如果要向选课列表传入参数，把它的构造函数改一下就好
	cc->show();//显示选课列表
	return 0;
}

void educationManager::on_tabWidget_tabBarClicked(int index)
{
    ui.tableWidget_3->setRowCount(0);
    ui.tableWidget_3->clearContents();
    ui.tableWidget_4->setRowCount(0);
    ui.tableWidget_4->clearContents();
    ui.tableWidget_7->clearContents();
    ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);

    string id = Kernel.getUserID();
    bool status;
    vector<string> row;

    if(index == 0){
        status = Kernel.getStuSchedule(id);
        if(status){
            for(int i = 0; i < Kernel.getStuRnum(); i++){
                row = Kernel.getStuRow(i);
                ui.tableWidget_4->insertRow(i);
                ui.tableWidget_4->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
                ui.tableWidget_4->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
                ui.tableWidget_4->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[5])));
                ui.tableWidget_4->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[6])));
                ui.tableWidget_4->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[7])));
                ui.tableWidget_4->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[8])));
                ui.tableWidget_4->setItem(i,6,new QTableWidgetItem(QString::fromStdString(row[9])));

                for(int j = getTime(row[7]); j <= getTime(row[8]); j++){
                    ui.tableWidget_7->setItem(j - 1,getScheduleCol(row[6]),new QTableWidgetItem(QString::fromStdString(row[1])));
                }

                ui.tableWidget_4->show();
                ui.tableWidget_7->show();
            }
        }
        qDebug() << status;
    }else if(index == 1){
        status = Kernel.getStuAllCourseInfo();
        if(status){
            for(int i = 0; i < Kernel.getStuRnum(); i++){
                row = Kernel.getStuRow(i);
                ui.tableWidget_3->insertRow(i);
                ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
                ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
                ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));

                if(row.size() == 4){
                    ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
                }else{
                    ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString("No Description!")));
                }

                ui.tableWidget_3->show();
            }
        }
        qDebug() << status;
    }else if(index == 2){
        status = Kernel.getPersonInfo(Kernel.getRole());
        if(status){
            for(int i = 0; i < Kernel.getStuRnum(); i++){
                row = Kernel.getStuRow(i);
                ui.lineEdit_7->setText(QString::fromStdString(row[0]));
                ui.lineEdit_8->setText(QString::fromStdString(row[1]));
                ui.lineEdit_9->setText(QString::fromStdString(row[3]));
                ui.lineEdit_10->setText(QString::fromStdString(row[2]));
                ui.lineEdit_11->setText(QString::fromStdString(row[4]));
                ui.lineEdit_12->setText(QString::fromStdString(row[5]));
            }
        }
        qDebug() << status;
    }
}

void educationManager::on_pushButton_clicked()
{
    while(ui.treeWidget->topLevelItemCount())
    {
        QTreeWidgetItem* item = ui.treeWidget->takeTopLevelItem(0);
        delete item;
    }
    QString courseid = ui.lineEdit->text();
    qDebug() << courseid;
    QString coursename = ui.lineEdit_2->text();
    int date = ui.comboBox_2->currentIndex();
    QString start = ui.spinBox->text();
    QString end = ui.spinBox_2->text();
    QString dept = ui.lineEdit_3->text();
    string tempop = "TOP";

    bool status;
    vector<string> row;
    vector<string> cops;

    cops.push_back(tempop);
    tempop = (ui.comboBox->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);
    tempop = (ui.comboBox_3->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);
    tempop = (ui.comboBox_4->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);

    status = Kernel.getStuCourseInfo(courseid.toStdString(),
                                  coursename.toStdString(),
                                  date,
                                  start.toStdString(),
                                  end.toStdString(),
                                  dept.toStdString(),
                                  cops);
    if(status){
        for(int i = 0; i < Kernel.getStuRnum(); i++){
            row = Kernel.getStuRow(i);
            addCourseList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[6]),
                    QString::fromStdString(row[7]),
                    QString::fromStdString(row[8]),
                    QString::fromStdString(row[9]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[5]));
            ui.treeWidget->show();
        }
    }
    qDebug() << status;
}

void educationManager::on_pushButton_5_clicked()
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
        ui.label_11->setText(QString::fromStdString(Kernel.getName(Kernel.getRole())));
    else
        ui.label_11->setText(QString::fromStdString("NO RECORD"));
}

void educationManager::on_pushButton_2_clicked()
{
    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.comboBox->setCurrentIndex(0);
    ui.comboBox_2->setCurrentIndex(0);
    ui.comboBox_3->setCurrentIndex(0);
    ui.comboBox_4->setCurrentIndex(0);
    ui.spinBox->setValue(ui.spinBox->minimum());
    ui.spinBox_2->setValue(ui.spinBox_2->minimum());
    ui.lineEdit_3->clear();
}

void educationManager::on_tabWidget_2_tabBarClicked(int index)
{
    ui.tableWidget_3->setRowCount(0);
    ui.tableWidget_3->clearContents();
    ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bool status;
    vector<string> row;

    status = Kernel.getStuAllCourseInfo();
    if(status){
        for(int i = 0; i < Kernel.getStuRnum(); i++){
            row = Kernel.getStuRow(i);
            ui.tableWidget_3->insertRow(i);
            ui.tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            ui.tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[2])));

            if(row.size() == 4){
                ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[3])));
            }else{
                ui.tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString("No Description!")));
            }

            ui.tableWidget_3->show();
        }
    }
    qDebug() << status;
}

void educationManager::on_tabWidget_5_tabBarClicked(int index)
{
    ui.tableWidget_4->setRowCount(0);
    ui.tableWidget_4->clearContents();
    ui.tableWidget_7->clearContents();
    ui.tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);

    string id = Kernel.getUserID();
    bool status;
    vector<string> row;

    status = Kernel.getStuSchedule(id);
    if(status){
        for(int i = 0; i < Kernel.getStuRnum(); i++){
            row = Kernel.getStuRow(i);
            ui.tableWidget_4->insertRow(i);
            ui.tableWidget_4->setItem(i,0,new QTableWidgetItem(QString::fromStdString(row[0])));
            qDebug() <<QString::fromStdString(row[0]);
            ui.tableWidget_4->setItem(i,1,new QTableWidgetItem(QString::fromStdString(row[1])));
            ui.tableWidget_4->setItem(i,2,new QTableWidgetItem(QString::fromStdString(row[5])));
            ui.tableWidget_4->setItem(i,3,new QTableWidgetItem(QString::fromStdString(row[6])));
            ui.tableWidget_4->setItem(i,4,new QTableWidgetItem(QString::fromStdString(row[7])));
            ui.tableWidget_4->setItem(i,5,new QTableWidgetItem(QString::fromStdString(row[8])));
            ui.tableWidget_4->setItem(i,6,new QTableWidgetItem(QString::fromStdString(row[9])));

            for(int j = getTime(row[7]); j <= getTime(row[8]); j++){
                ui.tableWidget_7->setItem(j - 1,getScheduleCol(row[6]),new QTableWidgetItem(QString::fromStdString(row[1])));
            }

            ui.tableWidget_4->show();
            ui.tableWidget_7->show();
        }
    }
    qDebug() << status;
}
