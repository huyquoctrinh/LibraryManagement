#pragma once
#include <vector>
#include "User.h"
#include "Student.h"
#include "UniversityEnum.h"
#include "DBAccess.h"
#include "ReservationFilter.h"

class Staff : public User
{
private:
public:
    bool addContent(Content*);
    bool updateContent(Content*);
    bool removeContent(Content*);
    bool addStudent(Student*);
    bool updateStudent(Student*);
    bool blockStudent(Student*);
    vector<Reservation> getAllReservations(ReservationFilter);
    vector<Student> getStudents();
	UserType getUserType();
	//Phuong thuc khoi tao, huy
public:
	Staff();
    Staff(string name, DateTime dateOfBirth, bool gender, Account account);
    ~Staff();
};
