#include "UserData.h"

// UserData::UserData()
// {

// }

Student *UserData::searchBySID(string sid)
{
    Database* tmp = new Database("Account.csv");
    vector<vector<string>> allRecord = tmp->getRecord();
    for (auto row:allRecord){
        if (row[0]== sid){
            DateTime time =  DateTime(row[4]);
            int g = stoi(row[5]);
            bool gender = !!g;
            MemberShip* mbship = new MemberShip(row[10],100);
            string uni = row[7];
            string sid = row[8];
            Account acc = Account(row[1],row[2]);
            DateTime renewal =  DateTime(row[9]);
            Student* st = new Student(row[3],time,gender,acc,sid,uni,renewal,mbship);
        }
    }
}

bool UserData::addStudent(Student *student)
{
    
}

bool UserData::updateStudent(Student *student)
{

}

bool UserData::deleteStudent(Student *student)
{

}
