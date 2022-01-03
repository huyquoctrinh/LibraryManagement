#include"Database.h"
#include<iostream>
#include<string>
#include"Datetime.h"

class User{
    private:
        string id;
        string uname;
        string password;
        string fullName;
        string DateOfBirth;
        string userType;
        int gender;
    public:
        User(string id, string uname, string password, string fullName, string DateOfBirth,string userType, int gender){
            this->id = id;
            this->uname = uname;
            this->password = password;
            this->fullName = fullName;
            this->DateOfBirth = DateOfBirth;
            this->userType = userType;
            this->gender = gender;
        }
        vector<string> getInfo(){
            vector<string> account;
            account.push_back(this->uname);
            account.push_back(this->password);
            account.push_back(this->fullName);
            account.push_back(this->DateOfBirth);
            account.push_back(this->userType);
            account.push_back(to_string(this->gender));
            return account;
        }
        string getId(){    
            return this->id;
        }
};

class Membership{
    private:   
        double fee;
        string _typename;
    public:
        virtual int getMaxBorrowDate() = 0;
};

class Basic:public Membership{
    public:
        int getMaxBorrowDate(){
            return 10;
        }
};

class Premium:public Membership{
    public:
        int getMaxBorrowDate(){
            return 20;
        }
};

#pragma once