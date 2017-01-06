#ifndef MYINSERT_H
#define MYINSERT_H

#include <vector>
#include <string>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

using namespace std;

class myInsert{
private:
    string tablename;
    vector<string> project;
public:
    myInsert():tablename(""){}

    string singleCondForm(string f1, string f2, string op, bool quote = false){
        if(quote == true)
            return f1 + " " + op + " " + f2;
        else
            return f1 + " " + op + " \'" + f2 + "\'";
    }

    QString insertForm(){
        QString res;
        string Q = "";
        string pro = "";

        Q = "INSERT INTO " + this->getTable() + " VALUES ";
        pro = "";
        for(int i = 0; i < this->project.size(); i++){
            pro += "\'" + this->getProj(i) + "\'";
            if(i + 1 != this->project.size())
                pro += ",";
        }

        Q += "(" + pro + ");";
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

    string getProj(int index){
        string res = "";
        if(index >= 0 && index < this->project.size()){
            res = this->project[index];
        }
        return res;
    }

    void setProj(vector<string> ps){
        string temp;
        for(int i = 0; i < ps.size(); i++){
            temp = ps[i];
            this->project.push_back(temp);
        }
    }
};

class insertExec{
public:
    insertExec(){}

    bool exec(myInsert& Q){
        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery query(db);
        bool status;

//        qDebug() << Q.queryForm();
        status = query.exec(Q.insertForm());
        return status;
    }
};


#endif // MYINSERT_H
