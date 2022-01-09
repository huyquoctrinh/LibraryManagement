#include "UserData.h"
#include "QDebug"

#include"Student.h"
#include "Staff.h"
#include "Database.h"

// UserData::UserData()
// {

// }

Student *UserData::searchBySID(string sid)
{
    Database* tmp = new Database("Account.csv");
    vector<vector<string>> allRecord = tmp->getRecord();

    for (auto row:allRecord){
        qInfo() << QString::fromStdString(row[8]);
        if (row[8]== sid){
            DateTime time =  DateTime(row[4]);
            int g = stoi(row[5]);
            bool gender = !!g;
            MemberShip* mbship = new MemberShip(row[10],100);
            string uni = row[7];
            string sid = row[8];
            Account acc = Account(row[1],row[2]);
            DateTime renewal =  DateTime(row[9]);
            Student* st = new Student(row[3],time,gender,acc,sid,toKey(uni),renewal,mbship);
            return st;
        }
    }
    return NULL;
}

bool UserData::addStudent(Student *student)
{
    UserData userDB = DBAccess::getInstance()->getUserDB();
    userDB.addRecord(student->getAllStudentData());
}

bool UserData::updateStudent(Student *student)
{
    UserData userDB = DBAccess::getInstance()->getUserDB();
    userDB.updateRecord(student->getAllStudentData());
    return 1;
}

bool UserData::deleteStudent(Student *student)
{
    UserData userDB = DBAccess::getInstance()->getUserDB();
    userDB.deleteRecord(student->getAllStudentData());
}

User *UserData::GetUser(string id)
{
    for (auto row: this->accountList){
        if (row[0] == id){
            string id = row[0];
            string uname = row[1];
            string password = row[2];
            string fullName = row[3];
            string dob = row[4];
            DateTime DateofBirth = DateTime(dob);
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
                Student* student = new Student(fullName, DateofBirth, gender_data, acc ,studentID, toKey(uni), t, mbship);
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
