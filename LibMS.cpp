#include "LibMS.h"

Reading *LibMS::getViewingReading() const
{
    return _viewingReading;
}

void LibMS::setViewingReading(Reading *newViewingReading)
{
    delete _viewingReading;
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
            if (row.size() == 7){
                Staff* staff =  new Staff(fullName, dob, gender_data,acc);
            }
            else{
                string studentID = row[8];
                string renewalDate = row[9];
                string memberType = row[10];
                string uni = row[7];
                MemberShip* mbship = new MemberShip(memberType, 100);
                DateTime t =  DateTime(renewalDate);
                Student* student = new Student(fullName, DateofBirth, gender_data, acc ,studentID,toKey(uni), t, mbship);
                return student;
            }
        }
    }

    return NULL;
    // Sign in with account's info
    // Return: User* if succeed, NULL if not.



    // if (true) {
    //     // Example login as student

    //     string name = "Lê Quang Trí";
    //     bool gender = false;
    //     DateTime dateOfBirth(3, 1, 2002);
    //     DateTime renewalDate(30, 1, 2022);
    //     University uni = toKey("HCMUS");
    //     string sid = "20120022";
    //     MemberShip* membership = new Basic();
    //     Student* newStudent = new Student(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);
    //     newStudent->setId("11523");
    //     // Update current user for this instance
    //     _currentUser = newStudent;
    //     return newStudent;


    //     /*
    //     // Example login as staff
    //     string name = "Lê Quang Trí";
    //     bool gender = false;
    //     DateTime dateOfBirth(3, 1, 2002);
    //     Staff* loginStaff = new Staff(name, dateOfBirth, gender, account);
    //     _currentUser = loginStaff;
    //     return loginStaff;
    //     */
    // }
    // _currentUser = NULL;
    // return NULL; // Failed to sign in
}

bool LibMS::signOut()
{
    delete _currentUser;
    _currentUser = NULL;
    return true;
}

// bool LibMS::signUp(Student* newStudent)
// {
//     // Sign up with newStudent's info
//     // Return: true if success, false if not.
//     DBAccess* dbaccess = DBAccess::getInstance();
//     dbaccess->g
//     //dbaccess->getUserDB()->signIn(newStudent->getAccount().getUsername(), newStudent->getAccount().getPassword());
//     // string username = newStudent->
//     return true;
// }

// bool LibMS::signUp(Student* newStudent){

// }
