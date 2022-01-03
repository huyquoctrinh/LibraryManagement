#include"Database.h"
#include<iostream>
#include<string>

class User{
    private:
        string id;
        string uname;
        string password;
        string fullName;
        string DateOfBirth;
        int gender;
    public:
        User(string id, string uname, string password, string fullName, string DateOfBirth, int gender){
            this->id = id;
            this->uname = uname;
            this->password = password;
            this->fullName = fullName;
            this->DateOfBirth = DateOfBirth;
            this->gender = gender;
        }
        vector<string> getInfo(){
            vector<string> account;
            account.push_back(this->uname);
            account.push_back(this->password);
            account.push_back(this->fullName);
            account.push_back(this->DateOfBirth);
            account.push_back(to_string(this->gender));
            return account;
        }
        string getId(){    
            return this->id;
        }
};

class UserData:public Database{
    private:
        vector<vector<string>> accountList;
    public:
        UserData(string databaseName):Database(databaseName){
            this->accountList = getRecord();
        }
        bool signin(string username, string password){
            for (auto row: this->accountList){
                if (row[1] == username && row[2] == password){
                    return 1;
                }
            }
            return 0;
        }
        bool Register(string username, string password, string fullName, string DateOfBirth){
            vector<string> data;
            if(username=="" || password.size()<6 || fullName=="" || DateOfBirth == "" ){
                return 0;
            }
            int id = this->accountList.size();
            data.push_back(to_string(id+1));
            data.push_back(username);
            data.push_back(password);
            data.push_back(fullName);
            data.push_back(DateOfBirth);
            updateRecord(data);
            return 1;
        }
        int isAccountExisted(string username){
            for (int i = 0;i<this->accountList.size();i++){
                if (this->accountList[i][1] == username){
                    return i;
                }
            }
            return -1;
        }
        
        bool changePassword(string username, string oldPassword, string newPassword){
            if (newPassword.length()<6){
                return 0;
            } // check Pass length < 6
            int id = isAccountExisted(username);
            if (id == -1){
                return 0;
            } // check account if not existed
            else{
                if (this->accountList[id][2]!=oldPassword){
                    return 0; // check if type old Password wrong
                }
                else{
                    this->accountList[id][2] = newPassword;
                    this->createRecord(this->accountList);
                } // update Password
            }
        }
        User* GetUser(string id){
            for (auto row: this->accountList){
                if (row[0] == id){
                    string id = row[0];
                    string uname = row[1];
                    string password = row[2];
                    string fullName = row[3];
                    string dob = row[4];
                    int gender = (stoi(row[5]));
                    User* newUser = new User(id, uname, password, fullName, dob, gender);
                    return newUser;
                }
            }
            return NULL;
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