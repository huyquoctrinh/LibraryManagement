#include"Account.h"
#include"Student.h"
#include "Staff.h"
class Staff;
class Student;



class UserData:public Database{
    private:
        vector<vector<string>> accountList;
    public:
        UserData(string databaseName):Database(databaseName){
            this->accountList = getRecord();
        }

        vector<vector<string>> getfullDatabase(){
            return this->accountList;
        }
        bool signin(string username, string password);
        bool Register(string username, string password, string fullName, string DateOfBirth);
        int isAccountExisted(string username);
        bool changePassword(string username, string oldPassword, string newPassword);
        User* GetUser(string id);
};
#pragma once