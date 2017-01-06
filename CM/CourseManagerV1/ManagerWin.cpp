#include "ManagerWin.h"
#include "cskernel.h"
extern kernel Kernel;

ManagerWin::ManagerWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(onDeleteApplication()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(onPassApplication()));
	connect(ui.pushButton_17, SIGNAL(clicked()), this, SLOT(onDeleteStudent()));
	connect(ui.pushButton_13, SIGNAL(clicked()), this, SLOT(onDeleteTeacher()));
	connect(ui.pushButton_14, SIGNAL(clicked()), this, SLOT(onDeleteCourse()));
	connect(ui.pushButton_16, SIGNAL(clicked()), this, SLOT(onRegisterStudent()));
	connect(ui.pushButton_12, SIGNAL(clicked()), this, SLOT(onRegisterTeacher()));
	connect(ui.pushButton_22, SIGNAL(clicked()), this, SLOT(onAddManager()));
	connect(ui.pushButton_23, SIGNAL(clicked()), this, SLOT(onDeleteManager()));
    ui.lineEdit_8->setEnabled(false);
    ui.treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

ManagerWin::~ManagerWin()
{

}

void ManagerWin::setDefaultPerInfo(int role){
    bool status;
    vector<string> row;

    status = Kernel.getPersonInfo(role);
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            ui.lineEdit_8->setText(QString::fromStdString(row[0]));
            ui.lineEdit_10->setText(QString::fromStdString(row[1]));
            ui.lineEdit_15->setText(QString::fromStdString(row[4]));
            ui.lineEdit_14->setText(QString::fromStdString(row[2]));
            ui.lineEdit_13->setText(QString::fromStdString(row[3]));
        }
    }
    qDebug() << status;
}

void ManagerWin::setUserName(QString username, int role)
{
	ui.label_15->setText(username);
    bool status = Kernel.getUserName(role);
    if(status)
        ui.label_13->setText(QString::fromStdString(Kernel.getName(role)));
    else
        ui.label_13->setText(QString::fromStdString("NO RECORD"));
}

void ManagerWin::addApplyList(const QString& courseid,
                                     const QString& teaid,
                                     const QString& coursename,
                                     const QString& dept,
                                     const QString& desc
                                     )//用来向表格里添加项目的函数，要设定剩下的几列数据的话，增加这里的形参
{
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, courseid);//0是列数，剩下几列也可以这样设计
    item->setText(1, teaid);//0是列数，剩下几列也可以这样设计
    item->setText(2, coursename);//0是列数，剩下几列也可以这样设计
    item->setText(3, dept);//0是列数，剩下几列也可以这样设计
    item->setText(4, desc);//0是列数，剩下几列也可以这样设计
    ui.treeWidget_3->addTopLevelItem(item);
}

void ManagerWin::addStuList(const QString& id,
                             const QString& name,
                             const QString& grade,
                             const QString& clas,
                             const QString& phone,
                             const QString& email
                            )//用来向表格里添加项目的函数，要设定剩下的几列数据的话，增加这里的形参
{
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, id);//0是列数，剩下几列也可以这样设计
    item->setText(1, name);//0是列数，剩下几列也可以这样设计
    item->setText(2, grade);//0是列数，剩下几列也可以这样设计
    item->setText(3, clas);//0是列数，剩下几列也可以这样设计
    item->setText(4, phone);//0是列数，剩下几列也可以这样设计
    item->setText(5, email);//0是列数，剩下几列也可以这样设计
    ui.treeWidget_2->addTopLevelItem(item);
}

void ManagerWin::addTeaList(const QString& id,
                 const QString& name,
                 const QString& prof,
                 const QString& phone,
                 const QString& email,
                const QString& dept
                ){
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, id);//0是列数，剩下几列也可以这样设计
    item->setText(1, name);//0是列数，剩下几列也可以这样设计
    item->setText(2, prof);//0是列数，剩下几列也可以这样设计
    item->setText(3, phone);//0是列数，剩下几列也可以这样设计
    item->setText(4, email);//0是列数，剩下几列也可以这样设计
    item->setText(5, dept);//0是列数，剩下几列也可以这样设计
    ui.treeWidget_5->addTopLevelItem(item);
}

void ManagerWin::addCourseList(const QString& courseid,
                   const QString& coursename,
                   const QString& dept,
                   const QString& desc
                    ){
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, courseid);//0是列数，剩下几列也可以这样设计
    item->setText(1, coursename);//0是列数，剩下几列也可以这样设计
    item->setText(2, dept);//0是列数，剩下几列也可以这样设计
    item->setText(3, desc);//0是列数，剩下几列也可以这样设计

    ui.treeWidget->addTopLevelItem(item);
}

void ManagerWin::addAdmList(const QString& id,
                 const QString& name,
                 const QString& phone,
                 const QString& email,
                const QString& dept
                ){
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, id);//0是列数，剩下几列也可以这样设计
    item->setText(1, name);//0是列数，剩下几列也可以这样设计
    item->setText(2, phone);//0是列数，剩下几列也可以这样设计
    item->setText(3, email);//0是列数，剩下几列也可以这样设计
    item->setText(4, dept);//0是列数，剩下几列也可以这样设计
    ui.treeWidget_6->addTopLevelItem(item);
}


void ManagerWin::setDefaultApply()
{
    bool status;
    vector<string> row;

    status = Kernel.getAdmApply();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addApplyList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]));
            ui.treeWidget_3->show();
        }
    }
    qDebug() << status;
}

void ManagerWin::setDefaultStu()
{
    bool status;
    vector<string> row;

    status = Kernel.getAdmStu();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addStuList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[5]));
            ui.treeWidget_2->show();
        }
    }
    qDebug() << status;
}

void ManagerWin::setDefaultTea()
{
    bool status;
    vector<string> row;

    status = Kernel.getAdmTea();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addTeaList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[5]));
            ui.treeWidget_5->show();
        }
    }
    qDebug() << status;
}

void ManagerWin::setDefaultAdm()
{
    bool status;
    vector<string> row;

    status = Kernel.getAdmAdm();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addAdmList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]));
            ui.treeWidget_6->show();
        }
    }
    qDebug() << status;
}

void ManagerWin::setDefaultCourse()
{
    bool status;
    vector<string> row;

    status = Kernel.getAdmCourse();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            if(row.size() == 4)
                addCourseList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]));
            else
                addCourseList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString("No Description!"));
            ui.treeWidget->show();
        }
    }
    qDebug() << status;
}



int ManagerWin::onDeleteApplication()//删除选中的申请
{
    QString courseid = ui.treeWidget_3->currentItem()->text(0);
    QString teaid = ui.treeWidget_3->currentItem()->text(1);

    bool status;
    vector<string> row;

    status = Kernel.deleteAdmNewCourse(courseid.toStdString(),teaid.toStdString());
    if(status)
        QMessageBox::about(NULL, "Delete Success", "Apply deleted!");
    else
        QMessageBox::warning(NULL, "Delete Fail", "Apply can't be deleted!");

    while(ui.treeWidget_3->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_3->topLevelItem(0);
        delete item;
    }

    status = Kernel.getAdmApply();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addApplyList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]));
            ui.treeWidget_3->show();
        }
    }
    qDebug() << status;
    return 0;
}
int ManagerWin::onPassApplication()
{
    QString courseid = ui.treeWidget_3->currentItem()->text(0);
    QString teaid = ui.treeWidget_3->currentItem()->text(1);
    QString coursename = ui.treeWidget_3->currentItem()->text(2);
    QString dept = ui.treeWidget_3->currentItem()->text(3);
    QString desc = ui.treeWidget_3->currentItem()->text(4);

    bool status;
    vector<string> row;

    status = Kernel.passAdmNewCourse(courseid.toStdString(),
                                     teaid.toStdString(),
                                     coursename.toStdString(),
                                     dept.toStdString(),
                                     desc.toStdString());
    if(status)
        QMessageBox::about(NULL, "Approve Success", "Apply approved!");
    else
        QMessageBox::warning(NULL, "Approve Fail", "Apply can't be approved!");

    while(ui.treeWidget_3->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_3->topLevelItem(0);
        delete item;
    }

    status = Kernel.getAdmApply();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addApplyList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]));
            ui.treeWidget_3->show();
        }
    }
    qDebug() << status;
    return 0;

	return 0;
}
int ManagerWin::onDeleteStudent()//删除选中的学生
{
    QString stuid = ui.treeWidget_2->currentItem()->text(0);

    bool status;
    vector<string> row;

    status = Kernel.deleteAdmStu(stuid.toStdString());
    if(status)
        QMessageBox::about(NULL, "Delete Success", "Student deleted!");
    else
        QMessageBox::warning(NULL, "Delete Fail", "Student can't be deleted!");

    while(ui.treeWidget_2->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_2->topLevelItem(0);
        delete item;
    }

    status = Kernel.getAdmStu();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addStuList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[5]));
            ui.treeWidget_2->show();
        }
    }
    qDebug() << status;
    return 0;
}
int ManagerWin::onDeleteTeacher()//删除选中的老师
{
    QString teaid = ui.treeWidget_5->currentItem()->text(0);

    bool status;
    vector<string> row;

    status = Kernel.deleteAdmTea(teaid.toStdString());
    if(status)
        QMessageBox::about(NULL, "Delete Success", "Teacher deleted!");
    else
        QMessageBox::warning(NULL, "Delete Fail", "Teacher can't be deleted!");

    while(ui.treeWidget_5->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_5->topLevelItem(0);
        delete item;
    }

    status = Kernel.getAdmTea();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addTeaList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[5]));
            ui.treeWidget_5->show();
        }
    }
    return 0;
}
int ManagerWin::onDeleteCourse()//删除选中的课程
{
    QString courseid = ui.treeWidget->currentItem()->text(0);

    bool status;
    vector<string> row;

    status = Kernel.deleteAdmCourse(courseid.toStdString());
    if(status)
        QMessageBox::about(NULL, "Delete Success", "Course deleted!");
    else
        QMessageBox::warning(NULL, "Delete Fail", "Course can't be deleted!");

    while(ui.treeWidget->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget->topLevelItem(0);
        delete item;
    }

    status = Kernel.getAdmCourse();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            if(row.size() == 4)
                addCourseList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]));
            else
                addCourseList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString("No Description!"));
            ui.treeWidget->show();
        }
    }
    return 0;
}
int ManagerWin::onRegisterStudent()
{
    RegisterWin rw(1, this);
	int ret = rw.exec();
	return 0;
}

int ManagerWin::onRegisterTeacher()
{
    RegisterWin rw(2, this);
	int ret = rw.exec();
	return 0;
}

int ManagerWin::onDeleteManager()//删除选中的管理员
{
    QString admid = ui.treeWidget_6->currentItem()->text(0);

    bool status;
    vector<string> row;

    status = Kernel.deleteAdmAdm(admid.toStdString());
    if(status)
        QMessageBox::about(NULL, "Delete Success", "Admin deleted!");
    else
        QMessageBox::warning(NULL, "Delete Fail", "Admin can't be deleted!");

    while(ui.treeWidget_6->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_6->topLevelItem(0);
        delete item;
    }

    status = Kernel.getAdmAdm();
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addAdmList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]));
            ui.treeWidget_6->show();
        }
    }
    return 0;
}

int ManagerWin::onAddManager()
{
    RegisterWin rw(3, this);
	int ret = rw.exec();
	return 0;
}

void ManagerWin::on_pushButton_3_clicked()
{
    while(ui.treeWidget_2->topLevelItemCount())
    {
        QTreeWidgetItem* item = ui.treeWidget_2->takeTopLevelItem(0);
        delete item;
    }
    QString id = ui.lineEdit_4->text();
    QString name = ui.lineEdit_5->text();

    string tempop = "TOP";

    bool status;
    vector<string> row;
    vector<string> cops;

    cops.push_back(tempop);
    tempop = (ui.comboBox_6->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);

    status = Kernel.getAdmStuInfo(id.toStdString(),name.toStdString(),cops);
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addStuList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[5]));
            ui.treeWidget_2->show();
        }
    }
    qDebug() << status;
}

void ManagerWin::on_pushButton_11_clicked()
{
    bool status;
    vector<string> ps;

    QString name = ui.lineEdit_10->text();
    ps.push_back(name.toStdString());
    name =ui.lineEdit_14->text();
    ps.push_back(name.toStdString());
    name =ui.lineEdit_13->text();
    ps.push_back(name.toStdString());
    name =ui.lineEdit_15->text();
    ps.push_back(name.toStdString());

    status = Kernel.updatePersonInfo(Kernel.getRole(), ps);
    if(status == true)
        QMessageBox::about(NULL, "Update success","Info updated!");
    else
        QMessageBox::warning(NULL, "Update Fail", "Fail to update Info!");

    status = Kernel.getUserName(Kernel.getRole());
    if(status)
        ui.label_13->setText(QString::fromStdString(Kernel.getName(Kernel.getRole())));
    else
        ui.label_13->setText(QString::fromStdString("NO RECORD"));
}

void ManagerWin::on_tabWidget_tabBarClicked(int index)
{
    ui.lineEdit_8->setEnabled(false);
    ui.treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bool status;
    vector<string> row;

    if(index == 0){
        while(ui.treeWidget_2->topLevelItemCount()){
            QTreeWidgetItem* item = ui.treeWidget_2->topLevelItem(0);
            delete item;
        }

        status = Kernel.getAdmStu();
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                addStuList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString(row[3]),
                        QString::fromStdString(row[4]),
                        QString::fromStdString(row[5]));
                ui.treeWidget_2->show();
            }
        }
    }else if(index == 1){
        while(ui.treeWidget->topLevelItemCount()){
            QTreeWidgetItem* item = ui.treeWidget->topLevelItem(0);
            delete item;
        }

        status = Kernel.getAdmCourse();
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                if(row.size() == 4)
                    addCourseList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString(row[3]));
                else
                    addCourseList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString("No Description!"));
                ui.treeWidget->show();
            }
        }
        qDebug() << status;
    }else if(index == 2){
        while(ui.treeWidget_5->topLevelItemCount()){
            QTreeWidgetItem* item = ui.treeWidget_5->topLevelItem(0);
            delete item;
        }
        while(ui.treeWidget_3->topLevelItemCount()){
            QTreeWidgetItem* item = ui.treeWidget_3->topLevelItem(0);
            delete item;
        }

        status = Kernel.getAdmApply();
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                addApplyList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[4]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString(row[3]));
                ui.treeWidget_3->show();
            }
        }

        status = Kernel.getAdmTea();
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                addTeaList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString(row[3]),
                        QString::fromStdString(row[4]),
                        QString::fromStdString(row[5]));
                ui.treeWidget_5->show();
            }
        }
    }else if(index == 3){
        status = Kernel.getPersonInfo(Kernel.getRole());
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                ui.lineEdit_8->setText(QString::fromStdString(row[0]));
                ui.lineEdit_10->setText(QString::fromStdString(row[1]));
                ui.lineEdit_15->setText(QString::fromStdString(row[4]));
                ui.lineEdit_14->setText(QString::fromStdString(row[2]));
                ui.lineEdit_13->setText(QString::fromStdString(row[3]));
            }
        }
    }else if(index == 4){
        while(ui.treeWidget_6->topLevelItemCount()){
            QTreeWidgetItem* item = ui.treeWidget_6->topLevelItem(0);
            delete item;
        }

        status = Kernel.getAdmAdm();
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                addAdmList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString(row[3]),
                        QString::fromStdString(row[4]));
                ui.treeWidget_6->show();
            }
        }
    }
}

void ManagerWin::on_tabWidget_3_tabBarClicked(int index)
{
    ui.treeWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.treeWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bool status;
    vector<string> row;

    if(index == 0){
        while(ui.treeWidget_5->topLevelItemCount()){
            QTreeWidgetItem* item = ui.treeWidget_5->topLevelItem(0);
            delete item;
        }

        status = Kernel.getAdmTea();
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                addTeaList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString(row[3]),
                        QString::fromStdString(row[4]),
                        QString::fromStdString(row[5]));
                ui.treeWidget_5->show();
            }
        }
    }else if(index == 1){
        while(ui.treeWidget_3->topLevelItemCount()){
            QTreeWidgetItem* item = ui.treeWidget_3->topLevelItem(0);
            delete item;
        }

        status = Kernel.getAdmApply();
        if(status){
            for(int i = 0; i < Kernel.getAdmRnum(); i++){
                row = Kernel.getAdmRow(i);
                addApplyList(QString::fromStdString(row[0]),
                        QString::fromStdString(row[4]),
                        QString::fromStdString(row[1]),
                        QString::fromStdString(row[2]),
                        QString::fromStdString(row[3]));
                ui.treeWidget_3->show();
            }
        }
    }
}

void ManagerWin::on_pushButton_25_clicked()
{
    ui.lineEdit_18->clear();
    ui.lineEdit_19->clear();
    while(ui.treeWidget_6->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_6->topLevelItem(0);
        delete item;
    }
}

void ManagerWin::on_pushButton_4_clicked()
{
    ui.lineEdit_4->clear();
    ui.lineEdit_5->clear();
    while(ui.treeWidget_2->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_2->topLevelItem(0);
        delete item;
    }
}

void ManagerWin::on_pushButton_10_clicked()
{
    ui.lineEdit_11->clear();
    ui.lineEdit_12->clear();
    while(ui.treeWidget_5->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_5->topLevelItem(0);
        delete item;
    }
}

void ManagerWin::on_pushButton_2_clicked()
{
    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.lineEdit_3->clear();
    while(ui.treeWidget->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget->topLevelItem(0);
        delete item;
    }
}

void ManagerWin::on_pushButton_clicked()
{
    while(ui.treeWidget->topLevelItemCount())
    {
        QTreeWidgetItem* item = ui.treeWidget->takeTopLevelItem(0);
        delete item;
    }
    QString id = ui.lineEdit->text();
    QString name = ui.lineEdit_2->text();
    QString dept = ui.lineEdit_3->text();

    string tempop = "TOP";

    bool status;
    vector<string> row;
    vector<string> cops;

    cops.push_back(tempop);
    tempop = (ui.comboBox->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);
    tempop = (ui.comboBox_4->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);

    status = Kernel.getAdmCourseInfo(id.toStdString(), name.toStdString(),
                                     dept.toStdString(), cops);
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            if(row.size() == 4)
                addCourseList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]));
            else
                addCourseList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString("No Description!"));
            ui.treeWidget->show();
        }
    }
}

void ManagerWin::on_pushButton_9_clicked()
{
    while(ui.treeWidget_5->topLevelItemCount())
    {
        QTreeWidgetItem* item = ui.treeWidget_5->takeTopLevelItem(0);
        delete item;
    }
    QString id = ui.lineEdit_11->text();
    QString name = ui.lineEdit_12->text();

    string tempop = "TOP";

    bool status;
    vector<string> row;
    vector<string> cops;

    cops.push_back(tempop);
    tempop = (ui.comboBox_14->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);

    status = Kernel.getAdmTeaInfo(id.toStdString(),name.toStdString(),cops);
    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addTeaList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]),
                    QString::fromStdString(row[5]));
            ui.treeWidget_5->show();
        }
    }
    qDebug() << status;
}

void ManagerWin::on_pushButton_24_clicked()
{
    while(ui.treeWidget_6->topLevelItemCount()){
        QTreeWidgetItem* item = ui.treeWidget_6->topLevelItem(0);
        delete item;
    }
    QString id = ui.lineEdit_18->text();
    QString name = ui.lineEdit_19->text();

    string tempop = "TOP";

    bool status;
    vector<string> row;
    vector<string> cops;

    cops.push_back(tempop);
    tempop = (ui.comboBox_18->currentIndex() == 0) ? "OR" : "AND";
    cops.push_back(tempop);

    status = Kernel.getAdmAdmInfo(id.toStdString(),name.toStdString(),cops);

    if(status){
        for(int i = 0; i < Kernel.getAdmRnum(); i++){
            row = Kernel.getAdmRow(i);
            addAdmList(QString::fromStdString(row[0]),
                    QString::fromStdString(row[1]),
                    QString::fromStdString(row[2]),
                    QString::fromStdString(row[3]),
                    QString::fromStdString(row[4]));
            ui.treeWidget_6->show();
        }
    }
}
