#ifndef MYUPDATE_H
#define MYUPDATE_H

#include <vector>
#include <string>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

using namespace std;

class myUpdate{
private:
    string tablename;
    vector<string> cond;
    vector<string> project;
public:
    myUpdate():tablename(""){}

    string singleCondForm(string f1, string f2, string op, bool quote = false){
        if(quote == true)
            return f1 + " " + op + " " + f2;
        else
            return f1 + " " + op + " \'" + f2 + "\'";
    }

    QString updateForm(){
        QString res;
        string Q = "";
        string pro = "";
        string cond = "";

        Q = "UPDATE " + this->getTable();
        pro = "SET ";
        for(int i = 0; i < this->project.size(); i++){
            pro += this->getProj(i);
            if(i + 1 != this->project.size())
                pro += ",";
        }

        cond = "WHERE ";
        for(int i = 0; i < this->cond.size(); i++){
            cond += this->getCond(i);
            if(i + 1 != this->cond.size())
                cond += " AND ";
        }

        Q += " " + pro + " " + cond + ";";
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

class updateExec{
public:
    updateExec(){}

    bool exec(myUpdate& Q){
        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery query(db);
        bool status;

//        qDebug() << Q.queryForm();
        status = query.exec(Q.updateForm());
        return status;
    }
};


#endif // MYUPDATE_H
