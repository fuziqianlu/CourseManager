#ifndef MYDELETE_H
#define MYDELETE_H

#include <vector>
#include <string>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

using namespace std;

class myDelete{
private:
    string tablename;
    vector<string> cond;
public:
    myDelete():tablename(""){}

    string singleCondForm(string f1, string f2, string op, bool quote = false){
        if(quote == true)
            return f1 + " " + op + " " + f2;
        else
            return f1 + " " + op + " \'" + f2 + "\'";
    }

    QString deleteForm(){
        QString res;
        string Q = "";
        string pro = "";

        Q = "DELETE FROM " + this->getTable();
        pro = " WHERE ";
        for(int i = 0; i < this->cond.size(); i++){
            pro += this->getCond(i);
            if(i + 1 != this->cond.size())
                pro += " AND ";
        }

        Q += pro + ";";
        res = QString::fromStdString(Q);
        qDebug() << res;
        return res;
    }

    string getTable() const{
        return this->tablename;
    }

    void setTable(string name){
        this->tablename = name;
    }

    string getCond(int index){
        string res = "";
        if(index >= 0 && index < this->cond.size()){
            res = this->cond[index];
        }
        return res;
    }

    void setCond(vector<string> cs){
        string temp;
        for(int i = 0; i < cs.size(); i++){
            temp = cs[i];
            this->cond.push_back(temp);
        }
    }
};

class deleteExec{
public:
    deleteExec(){}

    bool exec(myDelete& Q){
        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery query(db);
        bool status;

//        qDebug() << Q.queryForm();
        status = query.exec(Q.deleteForm());
        return status;
    }
};

#endif // MYDELETE_H
