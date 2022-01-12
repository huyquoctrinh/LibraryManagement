#include "UserData.h"
#include "QDebug"

#include "Student.h"
#include "Staff.h"
#include "Database.h"
#include "Basic.h"

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
            MemberShip* mbship = NULL;
            if (row[10] == "Basic")
                mbship = new Basic();
            else
                mbship = new Premium();
            string uni = row[7];
            string sid = row[8];
            Account acc = Account(row[1],row[2]);
            DateTime renewal =  DateTime(row[9]);
            Student* st = new Student(row[3],time,gender,acc,sid,toKey(uni),renewal,mbship);
            st->setId(row[0]);
            return st;
        }
    }
    return NULL;
}

bool UserData::addStudent(Student *student)
{
    addRecord(student->getAllStudentData());
    return true;
}

bool UserData::updateStudent(Student *student)
{
    updateRecord(student->getAllStudentData());
    return true;
}

bool UserData::deleteStudent(Student *student)
{
    deleteRecord(student->getAllStudentData());
    return true;
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
                MemberShip* mbship = NULL;
                if (row[10] == "Basic")
                    mbship = new Basic();
                else
                    mbship = new Premium();
                DateTime t =  DateTime(renewalDate);
                Student* student = new Student(fullName, DateofBirth, gender_data, acc ,studentID, toKey(uni), t, mbship);
                student->setId(id);
                return student;
            }
            else if (userType == "1"){
                Staff* staff = new Staff(fullName, dob, gender_data,acc);
                staff->setId(id);
                return staff;
            }
            else{
                return NULL;
            }
        }
    }
    return NULL;

}
