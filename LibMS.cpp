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
    // Sign in with account's info
    // Return: User* if succeed, NULL if not.

    if (true) {
        // Example login as student

        string name = "Lê Quang Trí";
        bool gender = false;
        DateTime dateOfBirth(3, 1, 2002);
        DateTime renewalDate(30, 1, 2022);
        University uni = toKey("HCMUS");
        string sid = "20120022";
        MemberShip* membership = new Basic();
        Student* newStudent = new Student(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);
        newStudent->setId("11523");
        // Update current user for this instance
        _currentUser = newStudent;
        return newStudent;


        /*
        // Example login as staff
        string name = "Lê Quang Trí";
        bool gender = false;
        DateTime dateOfBirth(3, 1, 2002);
        Staff* loginStaff = new Staff(name, dateOfBirth, gender, account);
        _currentUser = loginStaff;
        return loginStaff;
        */
    }
    _currentUser = NULL;
    return NULL; // Failed to sign in
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
    //dbaccess->getUserDB()->signIn(newStudent->getAccount().getUsername(), newStudent->getAccount().getPassword());
    return true;
}
