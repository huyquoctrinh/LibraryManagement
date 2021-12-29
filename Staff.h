#pragma once
#include "User.h"
#include "Student.h"
#include "UniversityEnum.h"
#include "ReservationData.h"

class Staff :public User
{
private:
public:
	bool addContent(Content);
	bool updateContent(Content);
	bool removeContent(Content);
	bool addStudent(Student);
	bool blockStudent();
	ReservationData getAllReservationData();
	Student* getStudents();
	UserType getUserType();
	//Phuong thuc khoi tao, huy
public:
	Staff();
	Staff(string id, string name, DateTime dateOfBirth, Account account);

};
