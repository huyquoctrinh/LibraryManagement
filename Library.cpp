#include "Library.h"

Content * Library::loadContents()
{
	return nullptr;
}

Library::Library()
{
}

User *Library::signIn(Account account)
{
    // Sign in with account's info
    // Return: User* if succeed, NULL if not.
    if (false) {
        // Example login as student
        /*string name = "Lê Quang Trí";
        bool gender = false;
        DateTime dateOfBirth(3, 1, 2002);
        DateTime renewalDate(30, 1, 2022);
        University uni = toKey("HCMUS");
        string sid = "20120022";
        MemberShip* membership = new Basic();
        Student* newStudent = new Student(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);
        newStudent->setId("11523");
        return newStudent;
        */


        // Example login as staff
        string name = "Lê Quang Trí";
        bool gender = false;
        DateTime dateOfBirth(3, 1, 2002);
        Staff* loginStaff = new Staff(name, dateOfBirth, gender, account);
        return loginStaff;
    }

    return NULL; // Failed to sign in
}

bool Library::signUp(Student* newStudent)
{
    // Sign up with newStudent's info
    // Return: true if success, false if not.
    return true;
}
