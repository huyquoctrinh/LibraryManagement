#ifndef USERDATA_H
#define USERDATA_H

#include <string>
#include <vector>
#include "Database.h"

using namespace std;

class User;
class Staff;
class Student;
class MemberShip;
class DateTime;
class Account;

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
    User* GetUser(string id);
};

#endif // USERDATA_H
