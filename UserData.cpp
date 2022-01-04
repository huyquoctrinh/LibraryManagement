#include"UserData.h"

bool UserData::Register(string username, string password, string fullName, string DateOfBirth){
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

int UserData::isAccountExisted(string username){
    for (int i = 0;i<this->accountList.size();i++){
        if (this->accountList[i][1] == username){
            return i;
        }
    }
    return -1;
}

User* UserData::GetUser(string id){
    for (auto row: this->accountList){
        if (row[0] == id){
            string id = row[0];
            string uname = row[1];
            string password = row[2];
            string fullName = row[3];
            string dob = row[4];
            int gender = (stoi(row[5]));
            string userType = row[6];
            if (userType == "0"){
                string studentID = row[8];
                string renewalDate = row[9];
                string memberType = row[10];
                Student* student = new Student(id, uname, password, fullName, dob, userType, gender,studentID, renewalDate, memberType);
                return student;
            }
            else if (userType == "1"){
                Staff* staff = new Staff(id, uname, password, fullName, dob, userType, gender);
                return staff;
            }
            else{
                return NULL;
            }
        }
    }
    return NULL;
}

bool UserData::changePassword(string username, string oldPassword, string newPassword){
    if (newPassword.length()<6){
        return 0;
    } // check Pass length < 6
    int id = this->isAccountExisted(username);
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

bool UserData::signin(string username, string password){
    for (auto row: this->accountList){
        if (row[1] == username && row[2] == password){
            return 1;
        }
    }
    return 0;
}