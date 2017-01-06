#include "CourseChoice.h"
#include "cskernel.h"
extern kernel Kernel;

CourseChoice::CourseChoice(const QString& courseid,
                           const QString &coursename,
                           const QString &teaname,
                           const QString &day,
                           const QString &start,
                           const QString &end,
                           const QString &pos,
                           const QString &capacity,
                           const QString &current,
                           string id, QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onBtnClose()));

    while(ui.treeWidget_3->topLevelItemCount())
    {
        QTreeWidgetItem* item = ui.treeWidget_3->takeTopLevelItem(0);
        delete item;
    }

    bool status;

    status = Kernel.getStuCourseSelect(courseid.toStdString(), id);
    if(status){
        if(Kernel.getStuRnum() != 0){
            addCourseChoice(courseid,coursename,teaname,day,start,end,pos,capacity,current,true);
        }
        else{
            addCourseChoice(courseid,coursename,teaname,day,start,end,pos,capacity,current,false);
        }
        ui.treeWidget_3->show();
    }
    qDebug() << status;
}

CourseChoice::~CourseChoice()
{

}
void CourseChoice::addCourseChoice(const QString& courseid,
                                   const QString& coursename,
                                   const QString& teaname,
                                   const QString& day,
                                   const QString& start,
                                   const QString& end,
                                   const QString& pos,
                                   const QString& capacity,
                                   const QString& current,
                                   bool status)
{
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, courseid);
    item->setText(1, coursename);
    item->setText(2, teaname);
    item->setText(3, day);
    item->setText(4, start);
    item->setText(5, end);
    item->setText(6, pos);
    item->setText(7, current);
    item->setText(8, capacity);
    ui.treeWidget_3->addTopLevelItem(item);

    CellChoose* widget = new CellChoose(item);
    widget->setChecked(status);
    ui.treeWidget_3->setItemWidget(item, 9, widget);

    connect(widget, SIGNAL(choosingCourse(QTreeWidgetItem*)), this, SLOT(onCourseIsChoosed(QTreeWidgetItem*)));
    connect(widget, SIGNAL(discardingCourse(QTreeWidgetItem*)), this, SLOT(onCourseIsDiscarded(QTreeWidgetItem*)));
}
int CourseChoice::onCourseIsChoosed(QTreeWidgetItem* rowid)
{
    rowid->setCheckState(9,Qt::Checked);

    QMessageBox::about(NULL, "Choosing success", "Choosing course succeed!!!");
    return 0;
}
int CourseChoice::onCourseIsDiscarded(QTreeWidgetItem* rowid)
{
    rowid->setCheckState(9,Qt::Unchecked);

    QMessageBox::about(NULL, "Discarding success", "Discarding course succeed!!!");
    return 0;
}
int CourseChoice::onBtnClose()
{
    bool status;

    while(ui.treeWidget_3->topLevelItemCount())
    {
        QTreeWidgetItem* item = ui.treeWidget_3->takeTopLevelItem(0);
        qDebug() << item->checkState(9);
        if(item->checkState(9) == Qt::Checked)
            status = Kernel.StuSelectCourse(Kernel.getUserID(), item->text(2).toStdString(), item->text(0).toStdString());
        else
            status = Kernel.StuCancelCourse(Kernel.getUserID(), item->text(0).toStdString());
        if(status == false)
            QMessageBox::warning(NULL, "Change Fails", "Your choice not accepted!");
    }

    close();
    return 0;
}

