#include "LibMS.h"

Reading *LibMS::getViewingReading() const
{
    return _viewingReading;
}

void LibMS::setViewingReading(Reading *newViewingReading)
{
    //delete _viewingReading;
    _viewingReading = newViewingReading;
}

User *LibMS::getCurrentUser() const
{
    return _currentUser;
}

void LibMS::setCurrentUser(User *newCurrentUser)
{
    _currentUser = newCurrentUser;
}

LibMS::LibMS()
{
    _currentUser = NULL;
    _viewingReading = NULL;
}

LibMS *LibMS::getInstance()
{
    if (_instance == NULL) {
        _instance = new LibMS;
    }
    return _instance;
}

User *LibMS::signIn(Account account)
{
    Database* tmp = new Database("Account.csv");
    vector<vector<string>> accountList = tmp->getRecord();
    string username = account.getUsername();
    string password = account.getPassword();
    for (auto row: accountList){
        if (row[1] == username && row[2] == password){
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
            qInfo() << QString::number(row.size());
            if (row.size() == 8){
                Staff* staff =  new Staff(fullName, dob, gender_data,acc);
                staff->setId(id);
                return staff;
            }
            else{
                string studentID = row[8];
                string renewalDate = row[9];
                string memberType = row[10];
                string uni = row[7];
                MemberShip* mbship = new MemberShip(memberType, 100);
                DateTime t =  DateTime(renewalDate);
                Student* student = new Student(fullName, DateofBirth, gender_data, acc ,studentID,toKey(uni), t, mbship);
                student->setId(id);
                return student;
            }
        }
    }

    return NULL;
}

bool LibMS::signOut()
{
    delete _currentUser;
    _currentUser = NULL;
    return true;
}

bool LibMS::signUp(Student *newStudent)
{
    return true;
}

bool LibMS::signUp(Student* newStudent)
{
    // Sign up with newStudent's info
    // Return: true if success, false if not.

    Database* db = new Database("Account.csv");
    vector<vector<string>> record = db->getRecord(); 
    int id = record.size();
    vector<string> tmp = newStudent->getAllStudentData();
    vector<string> res;
    res.push_back(id);
    for (auto info:tmp){
        res.push_back(info);
    }
    // dbaccess->g
    //dbaccess->getUserDB()->signIn(newStudent->getAccount().getUsername(), newStudent->getAccount().getPassword());
    // string username = newStudent->
    return true;
}

// bool LibMS::signUp(Student* newStudent){

// }
