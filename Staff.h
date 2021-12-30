#pragma once
#include <vector>
#include "User.h"
#include "Student.h"
#include "UniversityEnum.h"
#include "ReservationData.h"

class Staff : public User
{
private:
public:
	bool addContent(Content);
	bool updateContent(Content);
	bool removeContent(Content);
	bool addStudent(Student);
	bool blockStudent();
	ReservationData getAllReservationData();
    vector<Student> getStudents();
	UserType getUserType();
	//Phuong thuc khoi tao, huy
public:
	Staff();
    Staff(string name, DateTime dateOfBirth, bool gender, Account account);
    ~Staff();
};
