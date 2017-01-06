#ifndef CONNECTION_H
#define CONNECTION_H

#define HOST "localhost"
#define DB "CourseSystem"
#define USERNAME "root"
//#define USERNAME "root"
#define PASSWD ""
//#define PASSWD "123456"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConn()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(HOST);
    db.setDatabaseName(DB);
    db.setUserName(USERNAME);
    db.setPassword(PASSWD);
    if (!db.open()) {
       QMessageBox::warning(0, qApp->tr("Cannot open database"),
           qApp->tr("Unable to establish a database connection."
                     ), QMessageBox::Cancel);
       return false;
    }
    return true;
}

static void disconnectConn()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
}

#endif // CONNECTION_H
