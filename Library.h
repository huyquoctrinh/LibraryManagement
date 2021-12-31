#pragma once
#include "Content.h"
#include "User.h"
#include "Student.h"
#include "Staff.h"
#include "Basic.h"
#include "Premium.h"
#include "Reading.h"
#include "Book.h"
#include "AcademicJournal.h"
#include <vector>

class Library
{
public:
	Content* loadContents();
public:
    Library();
public:
    static User* signIn(Account account);
    static bool signUp(Student* newStudent);
    static vector<Reading*> searchReadingByTitle(string, vector<string>);
    static vector<Reading*> searchReadingByAuthors(string, vector<string>);
};
