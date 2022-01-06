#pragma once
#include <QCoreApplication>
#include <QDebug>
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
#include "DBAccess.h"
#include "Utils.h"

class LibMS
{
private:
    User* _currentUser;
    Reading* _viewingReading;
    static LibMS* _instance;
private:
    LibMS();
public:
    static LibMS* getInstance();
public:
    User* signIn(Account account);
    bool signOut();
    bool signUp(Student* newStudent);
    const ReservationData &getReservationDB() const;
    void setReservationDB(const ReservationData &newReservationDB);
    Reading *getViewingReading() const;
    void setViewingReading(Reading *newViewingReading);
    User *getCurrentUser() const;
    void setCurrentUser(User *newCurrentUser);
};
