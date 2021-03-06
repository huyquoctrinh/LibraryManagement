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
        qInfo() << QString::fromStdString(row[3]);
        qInfo() << QString::fromStdString(to_string(row.size()));
        if (row[1] == username && row[2] == password){
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
            qInfo() << QString::number(row.size());
            if (userType == "1"){
                qInfo() << "Staff";
                Staff* staff =  new Staff(fullName, dob, gender_data,acc);
                staff->setId(id);
                return staff;
            }
            else{
                string studentID = row[8];
                string renewalDate = row[9];
                string memberType = row[10];
                string uni = row[7];
                MemberShip* mbship = NULL;
                if (memberType == "Basic")
                    mbship = new Basic();
                else
                    mbship = new Premium();
                qInfo() << "Student";
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

bool LibMS::signUp(Student* newStudent)
{
    // Sign up with newStudent's info
    // Return: true if success, false if not.
    DBAccess* dbaccess = DBAccess::getInstance();
    UserData userDB = dbaccess->getUserDB();
    userDB.addStudent(newStudent);
    return true;
}



// bool LibMS::signUp(Student* newStudent){

// }
