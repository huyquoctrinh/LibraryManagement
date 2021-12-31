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
        return newStudent;


        /*
        // Example login as staff
        string name = "Lê Quang Trí";
        bool gender = false;
        DateTime dateOfBirth(3, 1, 2002);
        Staff* loginStaff = new Staff(name, dateOfBirth, gender, account);
        return loginStaff;*/
    }

    return NULL; // Failed to sign in
}

bool Library::signUp(Student* newStudent)
{
    // Sign up with newStudent's info
    // Return: true if success, false if not.
    return true;
}

vector<Reading *> Library::searchReadingByAuthors(string authors, vector<string> filter)
{
    // Search in database by authors with some filter
    // Ex1: Filter <"Book", "AcademicJournal", "Art", "Biography", "Economics", "Math", "Philosophy", "Textbook", "Science">
    //        |         Category        |                             Genre for Book only                            |
    // Apply all filter above to search and refine the results based on category and genre (for book only) with OR criteria.
    // In Ex1, get all the results
    // Ex2: Filter <"", "AcademicJournal", "", "" ,"", "", "" ,"", "">
    // In Ex2, get the results in category AcademicJournal
    // Ex3: Filter <"Book", "AcademicJournal", "Art", "" ,"", "", "" ,"", "">
    // In Ex3, get the results in category Book OR AcademicJournal. For Book results, just get those have Art genre.

    return vector<Reading*> {new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                             new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                             new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                             new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science")};
}

vector<Reading *> Library::searchReadingByTitle(string title, vector<string> filter)
{
    // Search in database by title with some filter
    // Ex1: Filter <"Book", "AcademicJournal", "Art", "Biography", "Economics", "Math", "Philosophy", "Textbook", "Science">
    //        |         Category        |                             Genre for Book only                            |
    // Apply all filter above to search and refine the results based on category and genre (for book only) with OR criteria.
    // In Ex1, get all the results
    // Ex2: Filter <"", "AcademicJournal", "", "" ,"", "", "" ,"", "">
    // In Ex2, get the results in category AcademicJournal
    // Ex3: Filter <"Book", "AcademicJournal", "Art", "" ,"", "", "" ,"", "">
    // In Ex3, get the results in category Book OR AcademicJournal. For Book results, just get those have Art genre.

    return vector<Reading*> {new Book("12", sttAvailable, 12, 15, "Harry Potter", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                             new Book("12", sttAvailable, 12, 15, "Harry Potter", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                             new Book("12", sttAvailable, 12, 15, "Harry Potter", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction")};
}
