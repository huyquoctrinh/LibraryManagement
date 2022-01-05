#ifndef USERDATA_H
#define USERDATA_H

#include <string>

using namespace std;
#include"Student.h"
#include "Staff.h"
class Staff;
class Student;

class UserData:public Database
{
private:
    vector<vector<string>> accountList;
public:
    UserData(string databasename):Database(databasename){
        this->accountList = getRecord();
    };
public:
    Student* searchBySID(string sid);
    bool addStudent(Student* student);
    bool updateStudent(Student* student);
    bool deleteStudent(Student* student);
    User* UserData::GetUser(string id){
    for (auto row: this->accountList){
        if (row[0] == id){
            string id = row[0];
            string uname = row[1];
            string password = row[2];
            string fullName = row[3];
            string dob = row[4];
            DateTime DateofBirth =  DateTime(dob);
            Account acc = Account(row[1],row[2]);
            int gender = (stoi(row[5]));
            bool gender_data = !!gender;
            string userType = row[6];
            if (userType == "0"){
                string studentID = row[8];
                string renewalDate = row[9];
                string memberType = row[10];
                string uni = row[7];
                MemberShip* mbship = new MemberShip(memberType, 100);
                DateTime t =  DateTime(renewalDate);
                Student* student = new Student(fullName, DateofBirth, gender_data, acc ,studentID,uni, t, mbship);
                return student;
            }
            else if (userType == "1"){
                Staff* staff = new Staff(fullName, dob, gender_data,acc);
                return staff;
            }
            else{
                return NULL;
            }
        }
    }
    return NULL;
}
};

#endif // USERDATA_H
