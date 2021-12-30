#pragma once
#include "Content.h"
#include "User.h"
#include "Student.h"
#include "Staff.h"
#include "Basic.h"
#include "Premium.h"

class Library
{
public:
	Content* loadContents();
public:
    Library();
public:
    static User* signIn(Account account);
    static bool signUp(Student* newStudent);
};
