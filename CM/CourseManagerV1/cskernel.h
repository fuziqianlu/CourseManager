#ifndef CSKERNEL_H
#define CSKERNEL_H

#include <QDebug>
#include <string>
#include "connection.h"
#include "myquery.h"
#include "myupdate.h"
#include "myinsert.h"
#include "mydelete.h"
#include "login.h"

using namespace std;

class roleManager{
public:
    roleManager():statusCode(false),record_num(0),field_num(0){}
    virtual ~roleManager(){}

    bool getName(string id){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = tablename;
        string deli;

        temp = myQ.singleCondForm("id", id, "=");
        cs.push_back(temp);

        temp = "name";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->username = QM.getData(0);
        }

        return this->statusCode;
    }

    string getUserName(){return this->username;}

    bool getPersonalInfo(string id){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = tablename;
        string deli;

        temp = myQ.singleCondForm("id", id, "=");
        cs.push_back(temp);

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    bool getAllCourseInfo(){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = "course";
        string deli;

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    bool getCourseInfo(string courseid, string coursename, int date, string start,
                       string end, string dept, vector<string> cops){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        vector<string> ops;
        string temp, table = "teaches";
        string deli;

        if(start.size() == 2){
            start = (start[0] - 48) * 10 + start[1];
        }
        if(end.size() == 2){
            end = (end[0] - 48) * 10 + end[1];
        }

        temp = cops[0];
        ops.push_back(temp);
        if(courseid != ""){
            temp = myQ.singleCondForm("courseid", courseid, "=");
            cs.push_back(temp);
        }
        if(coursename != ""){
            temp = myQ.singleCondForm("coursename", coursename, "=");
            cs.push_back(temp);
            temp = cops[1];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }
        if(start != "0" && end != "0"){
            temp = "(";
            temp += myQ.singleCondForm("day", this->getTrueDay(date), "=");
            temp += myQ.singleCondForm(" AND starttime", start, ">=");
            temp += myQ.singleCondForm(" AND endtime", end, "<=");
            temp += ")";
            cs.push_back(temp);
            temp = cops[2];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }
        if(dept != ""){
            temp = myQ.singleCondForm("dept", dept, "=");
            cs.push_back(temp);
            temp = cops[3];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setCondOP(ops);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ, true);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    bool createAccount(string user, string passwd, string role){
        myInsert myQ;
        insertExec QM;
        vector<string> ps;
        string temp, table = "Account";

        temp = user;
        ps.push_back(temp);
        temp = passwd;
        ps.push_back(temp);
        temp = role;
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    string getTrueDay(int date){
        string res;
        switch(date){
            case 0: res = "周一";break;
            case 1: res = "周二";break;
            case 2: res = "周三";break;
            case 3: res = "周四";break;
            case 4: res = "周五";break;
            case 5: res = "周六";break;
            case 6: res = "周日";break;
        }
        return res;
    }

    int getTime(string time){
        int res = 0;

        for(int i = 0; i < time.size(); i++){
            res = res * 10 + time[i] - 48;
        }

        return res;
    }

    string getTimeString(int time){
        char a[4];
        return string(itoa(time, a, 10));
    }

    void setTable(string table){
        this->tablename = table;
    }

    int getRnum() const{
        return this->record_num;
    }

    int getFnum() const{
        return this->field_num;
    }

    vector<string> getData(int index){
        vector<string> temp;
        if(index >= 0 && index < data.size()){
            temp = data[index];
        }
        return temp;
    }

    void dataClear(){
        while(data.size()){
            vector<string> temp;
            temp = data[data.size() - 1];
            while(temp.size())
                temp.pop_back();
            data.pop_back();
        }
    }

    vector<string> splitData(string data, string deli){
        vector<string> res;
        string temp;
        string::size_type pos_begin, comma_pos = 0;
        if(!data.empty()){
            pos_begin = data.find_first_not_of(deli);
            while(pos_begin != string::npos){
                comma_pos = data.find(deli, pos_begin);
                if(comma_pos != string::npos){
                    temp = data.substr(pos_begin, comma_pos - pos_begin);
                    pos_begin = comma_pos + deli.length();
                }else{
                    temp = data.substr(pos_begin);
                    pos_begin = comma_pos;
                }

                if(!temp.empty()){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }

protected:
    vector< vector<string> > data;
    bool statusCode;
    int record_num;
    int field_num;
    string tablename;
    string username;
};

class StuManager: public roleManager{
public:
    StuManager():roleManager(){}
    bool getSchedule(string stuid){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "takes";
          string deli;

          temp = myQ.singleCondForm("stuid", stuid, "=");
          cs.push_back(temp);

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool createStu(string user, string name, string deptgra,
                   string profcla, string phone, string email){
        myInsert myQ;
        insertExec QM;
        vector<string> ps;
        string temp, table = "Student";

        temp = user;
        ps.push_back(temp);
        temp = name;
        ps.push_back(temp);
        temp = deptgra;
        ps.push_back(temp);
        temp = profcla;
        ps.push_back(temp);
        temp = phone;
        ps.push_back(temp);
        temp = email;
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool getSelectCourseInfo(string courseid, string id){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = "takes";
        string deli;

        temp = myQ.singleCondForm("stuid", id, "=");
        cs.push_back(temp);
        temp = myQ.singleCondForm("courseid", courseid, "=");
        cs.push_back(temp);

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    bool updatePersonInfo(string id, vector<string> aps){
        myUpdate myQ;
        updateExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = tablename;

        temp = myQ.singleCondForm("id", id, "=");
        cs.push_back(temp);

        temp = myQ.singleCondForm("phone", aps[0], "=");
        ps.push_back(temp);
        temp = myQ.singleCondForm("email", aps[1], "=");
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);

        return this->statusCode;
    }

    bool CancelCourse(string courseid, string teaid, string stuid){
        myDelete myQ;
        deleteExec QM;
        myUpdate myQU;
        updateExec QMU;
        myQuery myQQ;
        queryExec QMQ;
        vector<string> cs;
        vector<string> ps;
        string temp, deli, table = "takes";
        int newcurrent;

        temp = myQ.singleCondForm("courseid" , courseid, "=");
        cs.push_back(temp);
        temp = myQ.singleCondForm("teaid" , teaid, "=");
        cs.push_back(temp);
        temp = myQ.singleCondForm("stuid" , stuid, "=");
        cs.push_back(temp);

        myQ.setCond(cs);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        if(this->statusCode){
            //step1
            table = "teaches";
            while(cs.size() > 0)
                cs.pop_back();
            temp = myQQ.singleCondForm("courseid" , courseid, "=");
            cs.push_back(temp);
            temp = myQQ.singleCondForm("teaid" , teaid, "=");
            cs.push_back(temp);

            temp = "currentstu";
            ps.push_back(temp);

            myQQ.setCond(cs);
            myQQ.setProj(ps);
            myQQ.setTable(table);

            QMQ.exec(myQQ);
            this->dataClear();
            this->record_num = QMQ.getRnum();
            this->field_num = QMQ.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QMQ.getData(i);
                deli = QMQ.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
            newcurrent = getTime(getData(0)[0]);

            //step2
            table = "teaches";
            while(cs.size() > 0)
                cs.pop_back();
            while(ps.size() > 0)
                ps.pop_back();
            temp = myQU.singleCondForm("courseid" , courseid, "=");
            cs.push_back(temp);
            temp = myQU.singleCondForm("teaid" , teaid, "=");
            cs.push_back(temp);

            temp = myQU.singleCondForm("currentstu" , getTimeString(newcurrent+1), "=");
            ps.push_back(temp);

            myQU.setCond(cs);
            myQU.setProj(ps);
            myQU.setTable(table);
            this->statusCode = QMU.exec(myQU);
        }

        return this->statusCode;
    }

    bool SelectCourse(string courseid, string teaname, string stuname, string id){
        myInsert myQ;
        insertExec QM;
        myUpdate myQU;
        updateExec QMU;
        myQuery myQQ,myQQ2;
        queryExec QMQ;
        vector<string> cs;
        vector<string> ps;
        string temp, deli, table = "teaches";
        int newcurrent;

        temp = myQQ.singleCondForm("courseid" , courseid, "=");
        cs.push_back(temp);
        temp = myQQ.singleCondForm("teaname" , teaname, "=");
        cs.push_back(temp);

        temp = "currentstu";
        ps.push_back(temp);

        myQQ.setCond(cs);
        myQQ.setProj(ps);
        myQQ.setTable(table);

        QMQ.exec(myQQ);
        this->dataClear();
        this->record_num = QMQ.getRnum();
        this->field_num = QMQ.getCol();
        for(int i = 0; i < this->record_num; i++){
            temp = QMQ.getData(i);
            deli = QMQ.getDelim();
            vector<string> back = splitData(temp, deli);
            data.push_back(back);
        }
        newcurrent = getTime(getData(0)[0]);

        if(newcurrent >= 1){
            //step1
            ps.pop_back();
            temp = "*";
            ps.push_back(temp);

            myQQ2.setCond(cs);
            myQQ2.setProj(ps);
            myQQ2.setTable(table);
            QMQ.dataClear();
            this->statusCode = QMQ.exec(myQQ2);
            this->dataClear();
            this->record_num = QMQ.getRnum();

            if(this->statusCode){
              this->field_num = QMQ.getCol();
              for(int i = 0; i < this->record_num; i++){
                  temp = QMQ.getData(i);
                  deli = QMQ.getDelim();
                  vector<string> back = splitData(temp, deli);
                  data.push_back(back);
              }
            }

            //step2
            table = "takes";
            while(ps.size() > 0)
                ps.pop_back();
            temp = courseid;
            ps.push_back(temp);
            temp = getData(0)[1];
            ps.push_back(temp);
            temp = id;
            ps.push_back(temp);
            temp = stuname;
            ps.push_back(temp);
            temp = getData(0)[2];
            ps.push_back(temp);
            temp = getData(0)[3];
            ps.push_back(temp);
            temp = getData(0)[6];
            ps.push_back(temp);
            temp = getData(0)[7];
            ps.push_back(temp);
            temp = getData(0)[8];
            ps.push_back(temp);
            temp = getData(0)[9];
            ps.push_back(temp);
            temp = "0";
            ps.push_back(temp);

            myQ.setProj(ps);
            myQ.setTable(table);

            this->statusCode = QM.exec(myQ);

            //step3
            if(this->statusCode){
                table = "teaches";
                while(cs.size() > 0)
                    cs.pop_back();
                while(ps.size() > 0)
                    ps.pop_back();
                temp = myQU.singleCondForm("courseid" , courseid, "=");
                cs.push_back(temp);
                temp = myQU.singleCondForm("teaname" , teaname, "=");
                cs.push_back(temp);

                temp = myQU.singleCondForm("currentstu" , getTimeString(newcurrent-1), "=");
                ps.push_back(temp);

                myQU.setCond(cs);
                myQU.setProj(ps);
                myQU.setTable(table);
                this->statusCode = QMU.exec(myQU);
            }
        }

        return this->statusCode;
    }


    ~StuManager(){}
private:

};

class TeaManager: public roleManager{
public:
    TeaManager():roleManager(){}
    bool getSchedule(string teaid){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "teaches";
          string deli;

          temp = myQ.singleCondForm("teaid", teaid, "=");
          cs.push_back(temp);

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool createTea(string user, string name, string deptgra,
                   string profcla, string phone, string email){
        myInsert myQ;
        insertExec QM;
        vector<string> ps;
        string temp, table = "Teacher";

        temp = user;
        ps.push_back(temp);
        temp = name;
        ps.push_back(temp);
        temp = profcla;
        ps.push_back(temp);
        temp = phone;
        ps.push_back(temp);
        temp = email;
        ps.push_back(temp);
        temp = deptgra;
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool updatePersonInfo(string id, vector<string> aps){
        myUpdate myQ;
        updateExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = tablename;

        temp = myQ.singleCondForm("id", id, "=");
        cs.push_back(temp);

        temp = myQ.singleCondForm("phone", aps[0], "=");
        ps.push_back(temp);
        temp = myQ.singleCondForm("email", aps[1], "=");
        ps.push_back(temp);
        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);

        return this->statusCode;
    }

    bool updateScore(string score, vector<string> acs){
        myUpdate myQ;
        updateExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = "takes";

        temp = myQ.singleCondForm("courseid", acs[0], "=");
        cs.push_back(temp);
        temp = myQ.singleCondForm("teaid", acs[1], "=");
        cs.push_back(temp);
        temp = myQ.singleCondForm("stuid", acs[2], "=");
        cs.push_back(temp);

        temp = myQ.singleCondForm("score", score, "=");
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);

        return this->statusCode;
    }

    bool getNewCourse(string teaid){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "newcourse";
          string deli;

          temp = myQ.singleCondForm("teaid", teaid, "=");
          cs.push_back(temp);

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool applyNewCourse(string courseid, string coursename,
                        string dept, string desc, string teaid){
        myInsert myQ;
        insertExec QM;
        vector<string> ps;
        string temp, table = "newcourse";

        temp = courseid;
        ps.push_back(temp);
        temp = coursename;
        ps.push_back(temp);
        temp = dept;
        ps.push_back(temp);
        temp = desc.substr(0, desc.length() > 400 ? 400 : desc.length());
        ps.push_back(temp);
        temp = teaid;
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool deleteNewCourse(string courseid, string teaid){
        myDelete myQ;
        deleteExec QM;
        vector<string> cs;
        string temp, table = "newcourse";

        temp = myQ.singleCondForm("courseid" , courseid, "=");
        cs.push_back(temp);
        temp = myQ.singleCondForm("teaid" , teaid, "=");
        cs.push_back(temp);

        myQ.setCond(cs);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool getStuList(string courseid, string coursename, string teaid){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "takes, student";
          string deli;

          temp = myQ.singleCondForm("takes.courseid", courseid, "=");
          cs.push_back(temp);
          temp = myQ.singleCondForm("takes.coursename", coursename, "=");
          cs.push_back(temp);
          temp = myQ.singleCondForm("takes.teaid", teaid, "=");
          cs.push_back(temp);
          temp = myQ.singleCondForm("student.id", "takes.stuid", "=", true);
          cs.push_back(temp);

          temp = "student.id";
          ps.push_back(temp);
          temp = "student.name";
          ps.push_back(temp);
          temp = "student.grade";
          ps.push_back(temp);
          temp = "student.class";
          ps.push_back(temp);
          temp = "takes.score";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }


    ~TeaManager(){}
private:

};

class AdmManager: public roleManager{
public:
    AdmManager():roleManager(){}

    bool updatePersonInfo(string id, vector<string> aps){
        myUpdate myQ;
        updateExec QM;
        vector<string> cs;
        vector<string> ps;
        string temp, table = tablename;

        temp = myQ.singleCondForm("id", id, "=");
        cs.push_back(temp);

        temp = myQ.singleCondForm("name", aps[0], "=");
        ps.push_back(temp);
        temp = myQ.singleCondForm("dept", aps[1], "=");
        ps.push_back(temp);
        temp = myQ.singleCondForm("phone", aps[2], "=");
        ps.push_back(temp);
        temp = myQ.singleCondForm("email", aps[3], "=");
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ);

        return this->statusCode;
    }

    bool createAdm(string user, string name, string deptgra,
                   string phone, string email){
        myInsert myQ;
        insertExec QM;
        vector<string> ps;
        string temp, table = "Admin";

        temp = user;
        ps.push_back(temp);
        temp = name;
        ps.push_back(temp);
        temp = phone;
        ps.push_back(temp);
        temp = email;
        ps.push_back(temp);
        temp = deptgra;
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool getNewCourse(){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "newcourse";
          string deli;

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool getAllStu(){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "student";
          string deli;

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool getAllTea(){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "teacher";
          string deli;

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool getAllCourse(){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "course";
          string deli;

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool getAllAdm(){
          myQuery myQ;
          queryExec QM;
          vector<string> cs;
          vector<string> ps;
          string temp, table = "admin";
          string deli;

          temp = "*";
          ps.push_back(temp);

          myQ.setProj(ps);
          myQ.setCond(cs);
          myQ.setTable(table);
          this->statusCode = QM.exec(myQ);
          this->dataClear();
          this->record_num = QM.getRnum();

          if(this->statusCode){
            this->field_num = QM.getCol();
            for(int i = 0; i < this->record_num; i++){
                temp = QM.getData(i);
                deli = QM.getDelim();
                vector<string> back = splitData(temp, deli);
                data.push_back(back);
            }
          }

          return this->statusCode;
    }

    bool passAdmNewCourse(string courseid, string coursename,
                          string dept, string desc){
        myInsert myQ;
        insertExec QM;
        vector<string> ps;
        string temp, table = "Course";

        temp = courseid;
        ps.push_back(temp);
        temp = coursename;
        ps.push_back(temp);
        temp = dept;
        ps.push_back(temp);
        temp = desc;
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool deleteNewCourse(string courseid, string teaid){
        myDelete myQ;
        deleteExec QM;
        vector<string> cs;
        string temp, table = "newcourse";

        temp = myQ.singleCondForm("courseid" , courseid, "=");
        cs.push_back(temp);
        temp = myQ.singleCondForm("teaid" , teaid, "=");
        cs.push_back(temp);

        myQ.setCond(cs);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool deleteAdmStu(string id){
        myDelete myQ;
        deleteExec QM;
        vector<string> cs;
        string temp, table = "Account";

        temp = myQ.singleCondForm("userid" , id, "=");
        cs.push_back(temp);

        myQ.setCond(cs);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool deleteAdmTea(string id){
        myDelete myQ;
        deleteExec QM;
        vector<string> cs;
        string temp, table = "Account";

        temp = myQ.singleCondForm("userid" , id, "=");
        cs.push_back(temp);

        myQ.setCond(cs);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool deleteAdmAdm(string id){
        myDelete myQ;
        deleteExec QM;
        vector<string> cs;
        string temp, table = "Account";

        temp = myQ.singleCondForm("userid" , id, "=");
        cs.push_back(temp);

        myQ.setCond(cs);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool deleteAdmCourse(string id){
        myDelete myQ;
        deleteExec QM;
        vector<string> cs;
        string temp, table = "course";

        temp = myQ.singleCondForm("courseid" , id, "=");
        cs.push_back(temp);

        myQ.setCond(cs);
        myQ.setTable(table);

        this->statusCode = QM.exec(myQ);
        return this->statusCode;
    }

    bool getAdmStuInfo(string id, string name, vector<string> cops){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        vector<string> ops;
        string temp, table = "student";
        string deli;

        temp = cops[0];
        ops.push_back(temp);
        if(id != ""){
            temp = myQ.singleCondForm("id", id, "=");
            cs.push_back(temp);
        }
        if(name != ""){
            temp = myQ.singleCondForm("name", name, "=");
            cs.push_back(temp);
            temp = cops[1];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setCondOP(ops);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ, true);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    bool getAdmTeaInfo(string id, string name, vector<string> cops){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        vector<string> ops;
        string temp, table = "teacher";
        string deli;

        temp = cops[0];
        ops.push_back(temp);
        if(id != ""){
            temp = myQ.singleCondForm("id", id, "=");
            cs.push_back(temp);
        }
        if(name != ""){
            temp = myQ.singleCondForm("name", name, "=");
            cs.push_back(temp);
            temp = cops[1];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setCondOP(ops);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ, true);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    bool getAdmAdmInfo(string id, string name, vector<string> cops){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        vector<string> ops;
        string temp, table = "admin";
        string deli;

        temp = cops[0];
        ops.push_back(temp);
        if(id != ""){
            temp = myQ.singleCondForm("id", id, "=");
            cs.push_back(temp);
        }
        if(name != ""){
            temp = myQ.singleCondForm("name", name, "=");
            cs.push_back(temp);
            temp = cops[1];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setCondOP(ops);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ, true);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    bool getAdmCourseInfo(string id, string name, string dept, vector<string> cops){
        myQuery myQ;
        queryExec QM;
        vector<string> cs;
        vector<string> ps;
        vector<string> ops;
        string temp, table = "course";
        string deli;

        temp = cops[0];
        ops.push_back(temp);
        if(id != ""){
            temp = myQ.singleCondForm("courseid", id, "=");
            cs.push_back(temp);
        }
        if(name != ""){
            temp = myQ.singleCondForm("coursename", name, "=");
            cs.push_back(temp);
            temp = cops[1];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }
        if(dept != ""){
            temp = myQ.singleCondForm("dept", dept, "=");
            cs.push_back(temp);
            temp = cops[2];
            ops.push_back(temp);
            if(ops.size() > 1 && ops.size() != cs.size())
                ops.pop_back();
        }

        temp = "*";
        ps.push_back(temp);

        myQ.setProj(ps);
        myQ.setCond(cs);
        myQ.setCondOP(ops);
        myQ.setTable(table);
        this->statusCode = QM.exec(myQ, true);
        this->dataClear();
        this->record_num = QM.getRnum();

        if(this->statusCode){
          this->field_num = QM.getCol();
          for(int i = 0; i < this->record_num; i++){
              temp = QM.getData(i);
              deli = QM.getDelim();
              vector<string> back = splitData(temp, deli);
              data.push_back(back);
          }
        }

        return this->statusCode;
    }

    ~AdmManager(){}
private:

};

class kernel{
private:
    StuManager m_stu;
    TeaManager m_tea;
    AdmManager m_adm;
    logProc m_log;
    static string logfile;
public:
    kernel(){}
    void start(){
        qDebug() << "Kernel starts!";
        m_stu.setTable("student");
        m_tea.setTable("teacher");
        m_adm.setTable("admin");
//        qDebug() << QString::fromStdString(m_log.getLogFailure());
//        qDebug() << m_log.nextWindow();
    }

    int logIn(string name, string passwd, int id){
        bool status = m_log.getLogIn(name, passwd, id);
//        qDebug() << status << id;
        if(status)
            return id;
        else
            return -1;
    }

    bool getStuSchedule(string stuid){
        bool status = m_stu.getSchedule(stuid);
        return status;
    }

    bool getTeaSchedule(string teaid){
        bool status = m_tea.getSchedule(teaid);
        return status;
    }

    bool getTeaApply(string teaid){
        bool status = m_tea.getNewCourse(teaid);
        return status;
    }

    bool getAdmApply(){
        bool status = m_adm.getNewCourse();
        return status;
    }

    bool getAdmStu(){
        bool status = m_adm.getAllStu();
        return status;
    }

    bool getAdmCourse(){
        bool status = m_adm.getAllCourse();
        return status;
    }

    bool getAdmTea(){
        bool status = m_adm.getAllTea();
        return status;
    }

    bool getAdmAdm(){
        bool status = m_adm.getAllAdm();
        return status;
    }

    bool applyTeaNewCourse(string courseid, string coursename,
                           string dept, string desc, string teaid){
        bool status = m_tea.applyNewCourse(courseid, coursename, dept, desc, teaid);
        return status;
    }

    bool deleteTeaNewCourse(string courseid, string teaid){
        bool status = m_tea.deleteNewCourse(courseid, teaid);
        return status;
    }

    bool deleteAdmNewCourse(string courseid, string teaid){
        bool status = m_adm.deleteNewCourse(courseid, teaid);
        return status;
    }

    bool deleteAdmCourse(string courseid){
        bool status = m_adm.deleteAdmCourse(courseid);
        return status;
    }

    bool deleteAdmStu(string stuid){
        bool status = m_adm.deleteAdmStu(stuid);
        return status;
    }

    bool deleteAdmTea(string teaid){
        bool status = m_adm.deleteAdmTea(teaid);
        return status;
    }

    bool deleteAdmAdm(string admid){
        bool status = m_adm.deleteAdmAdm(admid);
        return status;
    }

    bool passAdmNewCourse(string courseid, string teaid, string coursename,
                          string dept, string desc){
        bool status = m_adm.deleteNewCourse(courseid, teaid);
        if(status){
            status = m_adm.passAdmNewCourse(courseid, coursename, dept, desc);
        }
        return status;
    }

    bool getAdmStuInfo(string id, string name, vector<string> cops){
        bool status = m_adm.getAdmStuInfo(id, name, cops);
        return status;
    }
    bool getAdmTeaInfo(string id, string name, vector<string> cops){
        bool status = m_adm.getAdmTeaInfo(id, name, cops);
        return status;
    }
    bool getAdmAdmInfo(string id, string name, vector<string> cops){
        bool status = m_adm.getAdmAdmInfo(id, name, cops);
        return status;
    }
    bool getAdmCourseInfo(string id, string name, string dept, vector<string> cops){
        bool status = m_adm.getAdmCourseInfo(id, name, dept, cops);
        return status;
    }

    bool getTeaStuList(string courseid, string coursename, string teaid){
        bool status = m_tea.getStuList(courseid, coursename, teaid);
        return status;
    }

    bool getStuPerInfo(string id){
        bool status = m_stu.getPersonalInfo(id);
        return status;
    }

    bool getTeaPerInfo(string id){
        bool status = m_tea.getPersonalInfo(id);
        return status;
    }


    bool getStuAllCourseInfo(){
        bool status = m_stu.getAllCourseInfo();
        return status;
    }

    bool getTeaAllCourseInfo(){
        bool status = m_tea.getAllCourseInfo();
        return status;
    }

    bool getStuCourseInfo(string courseid, string coursename, int date, string start,
                          string end, string dept, vector<string> cops){
        bool status = m_stu.getCourseInfo(courseid, coursename, date, start,
                                          end, dept, cops);
        return status;
    }

    bool getStuCourseSelect(string courseid, string id){
        bool status = m_stu.getSelectCourseInfo(courseid, id);
        return status;
    }

    bool StuSelectCourse(string id, string teaname, string courseid){
        bool status = m_stu.getSelectCourseInfo(courseid, id);

        if(status){
            if(m_stu.getRnum() == 0){
                status = m_stu.SelectCourse(courseid, teaname, getName(1), id);
            }
        }
        return status;
    }

    bool StuCancelCourse(string id, string courseid){
        bool status = m_stu.getSelectCourseInfo(courseid, id);
        vector<string> row;
        if(status){
            if(m_stu.getRnum() > 0){
                row = getStuRow(0);
                status = m_stu.CancelCourse(courseid, row[4], id);
            }
        }
        qDebug() << m_stu.getRnum();
        return status;
    }

    string getName(int index){
        string status;
        if(index == 1)
            status = m_stu.getUserName();
        else if(index == 2)
            status = m_tea.getUserName();
        else
            status = m_adm.getUserName();
        return status;
    }

    bool getUserName(int index){
        bool status;
        if(index == 1)
            status = m_stu.getName(getUserID());
        else if(index == 2)
            status = m_tea.getName(getUserID());
        else
            status = m_adm.getName(getUserID());
        return status;
    }

    bool getPersonInfo(int index){
        bool status;
        if(index == 1)
            status = m_stu.getPersonalInfo(getUserID());
        else if(index == 2)
            status = m_tea.getPersonalInfo(getUserID());
        else
            status = m_adm.getPersonalInfo(getUserID());
        return status;
    }

    bool updatePersonInfo(int index, vector<string> ps){
        bool status;
        if(index == 1)
            status = m_stu.updatePersonInfo(getUserID(), ps);
        else if(index == 2)
            status = m_tea.updatePersonInfo(getUserID(), ps);
        else
            status = m_adm.updatePersonInfo(getUserID(), ps);
        return status;
    }

    bool updateScore(string score, vector<string> cs){
        bool status;
        status = m_tea.updateScore(score, cs);

        return status;
    }

    bool createStu(string name, string user, string passwd,
                   string email, string phone, string profcla, string deptgra)
    {
        bool status;
        status = m_stu.createAccount(user, passwd, "Student");
        if(status){
            status = m_stu.createStu(user, name, deptgra, profcla, phone, email);
        }

        return status;
    }

    bool createTea(string name, string user, string passwd,
                   string email, string phone, string profcla, string deptgra)
    {
        bool status;
        status = m_tea.createAccount(user, passwd, "Teacher");
        if(status){
            status = m_tea.createTea(user, name, deptgra, profcla, phone, email);
        }

        return status;
    }

    bool createAdm(string name, string user, string passwd,
                   string email, string phone, string deptgra)
    {
        bool status;
        status = m_adm.createAccount(user, passwd, "Administer");
        if(status){
            status = m_adm.createAdm(user, name, deptgra, phone, email);
        }

        return status;
    }

    int getStuRnum(){
        return this->m_stu.getRnum();
    }

    int getStuFnum(){
        return this->m_stu.getFnum();
    }

    int getTeaRnum(){
        return this->m_tea.getRnum();
    }

    int getTeaFnum(){
        return this->m_tea.getFnum();
    }

    int getAdmRnum(){
        return this->m_adm.getRnum();
    }

    int getAdmFnum(){
        return this->m_adm.getFnum();
    }

    vector<string> getStuRow(int index){
        return this->m_stu.getData(index);
    }

    vector<string> getTeaRow(int index){
        return this->m_tea.getData(index);
    }

    vector<string> getAdmRow(int index){
        return this->m_adm.getData(index);
    }

    string getUserID(){
        return this->m_log.getUserID();
    }

    int getRole(){
        return this->m_log.nextWindow();
    }

    void shutup(){
        qDebug() << "Kernel Shuts up!";
        disconnectConn();
    }
};

#endif // CSKERNEL_H
