#ifndef LOGIN_H
#define LOGIN_H

#include<QDebug>
#include<string>
#include "myquery.h"
using namespace std;

class logRecord{
public:
    logRecord():role(""), userName(""){}
    ~logRecord(){}
    string getUserName() const {return this->userName;}
    void setUserName(string name) {this->userName = name;}
    string getRole() const {return this->role;}
    void setRole(string name) {this->role = name;}
    int getPrivLvl() const {
        int lvl = -1;
        if(isConned){
            if(this->role == "Student") lvl = 1;
            else if(this->role == "Teacher") lvl = 2;
            else if(this->role == "Administer") lvl = 3;
        }
        return lvl;
    }
    bool getConnStatus() const {return this->isConned;}
    void setConnStatus(bool status) {this->isConned = status;}
private:
    bool isConned;
    string role;
    string userName;
};

class logProc{
public:
    logProc():statusCode(false), logR(){}
    ~logProc(){}
    bool getLogIn(string name, string passwd, int id) {
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
//        vector<string> cops;
        string temp, table = "Account";

        temp = myQ.singleCondForm("userid", name, "=");
        cs.push_back(temp);
//        temp = "TOP";
//        cops.push_back(temp);
        temp = myQ.singleCondForm("passwd", passwd, "=");
        cs.push_back(temp);
//        temp = "OR";
//        cops.push_back(temp);

        temp = "role";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
//        myQ.setCondOP(cops);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);
//        qDebug() << this->statusCode;
        if(this->statusCode){
            this->logR.setRole(QM.getData(0));
            this->logR.setConnStatus(this->statusCode);
//            qDebug() << QString::fromStdString(QM.getData(0));
            if(id == this->logR.getPrivLvl()){
                this->logR.setUserName(name);
                return this->statusCode;
            }else{
                this->logR.setRole("");
                this->logR.setUserName("");
                this->logR.setConnStatus(false);
                return false;
            }
        }else{
            this->logR.setRole("");
            this->logR.setUserName("");
            this->logR.setConnStatus(false);
            return false;
        }
    }

    string getLogFailure() {
        string res;
        if(this->statusCode == true){
            res = "Log In Succeed.";
        }else{
            res = "Log In Fail: No such account.";
        }
        return res;
    }

    string getUserID() {
        return this->logR.getUserName();
    }

    int nextWindow() const{
        return this->logR.getPrivLvl();
    }
private:
    logRecord logR;
    bool statusCode;
};

#endif // LOGIN_H
