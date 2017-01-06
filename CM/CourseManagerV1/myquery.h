#ifndef MYQUERY_H
#define MYQUERY_H

#include <vector>
#include <string>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

using namespace std;

class myQuery{
private:
    string tablename;
    vector<string> cond;
    vector<string> cond_op;
    vector<string> project;
public:
    myQuery():tablename(""){}

    string singleCondForm(string f1, string f2, string op, bool quote = false){
        if(quote == true)
            return f1 + " " + op + " " + f2;
        else
            return f1 + " " + op + " \'" + f2 + "\'";
    }

    QString queryForm(bool assistant_op = false){
        QString res;
        string Q = "";
        string pro = "";
        string cond = "";

        pro = "SELECT ";
        for(int i = 0; i < this->project.size(); i++){
            pro += this->getProj(i);
            if(i + 1 != this->project.size())
                pro += ",";
        }

        if(this->cond.size()){
            cond = "";
            if(assistant_op){
                for(int i = 0; i < this->cond.size(); i++){
                    if(this->getCondOP(i) != "TOP"){
                        if(this->getCondOP(i) == "OR"){
                            cond += " " + this->getCondOP(i) + " ";
                            cond = "(" + cond + this->getCond(i) + ")";
                        }else{
                            cond += " " + this->getCondOP(i) + " ";
                            cond += this->getCond(i);
                        }
                    }else
                        cond += this->getCond(i);
                }
            }else{
                for(int i = 0; i < this->cond.size(); i++){
    //                qDebug() << QString::fromStdString(this->getCond(i));
                    cond += this->getCond(i);
                    if(i + 1 != this->cond.size())
                        cond += " AND ";
                }
            }
            cond = "WHERE " + cond;
        }
        else{
            cond = "";
        }

        Q = pro + " FROM " + this->getTable() + " " + cond + ";";
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

    string getCondOP(int index){
        string res = "";
        if(index >= 0 && index < this->cond_op.size()){
            res = this->cond_op[index];
        }
        return res;
    }

    void setCondOP(vector<string> cops){
        string temp;
        for(int i = 0; i < cops.size(); i++){
            temp = cops[i];
            this->cond_op.push_back(temp);
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

class queryExec{
public:
    queryExec():delimeter(QString::fromStdString("#")),record_num(0){}
    void setDelim(string del){
        this->delimeter = QString::fromStdString(del);
    }

    string getDelim() const{
        return this->delimeter.toStdString();
    }

    void dataClear(){
        while(data.size()){
            data.pop_back();
        }
        this->record_num = 0;
        this->col_num = 0;
    }

    int getCol() const{
        return this->col_num;
    }

    int getRnum() const{
        return this->record_num;
    }

    string getData(int index){
        string res = "";
        if(index >=0 && index < data.size())
            res = this->data[index].toStdString();
        return res;
    }

    bool exec(myQuery& Q, bool op_ass = false){
        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery query(db);
        bool status;
        QString r;

//        qDebug() << Q.queryForm();
        status = query.exec(Q.queryForm(op_ass));
        if(status){
            query.setForwardOnly(true);
            this->col_num = query.record().count();
            while(query.next()){
                r = "";
                for(int i = 0; i < this->col_num; i++){
                    r += query.value(i).toString();
                    if(i + 1 != this->col_num) r += this->delimeter;
                }
                data.push_back(r);
            }
            this->record_num = data.size();
            return true;
        }
        else{
            return false;
        }
    }
private:
    QString delimeter;
    vector<QString> data;
    int col_num;
    int record_num;
};

#endif // MYQUERY_H
