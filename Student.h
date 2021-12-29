#pragma once
#include "User.h"
#include "UniversityEnum.h"
#include "MemberShip.h"
#include "Reservation.h"

class Student :public User
{
private:
	string _studentId;
	University _university;
	DateTime _renewalDate;
	MemberShip _membership;
public:
	bool signUp();
	void reserve(Content);
	void returnReservation(Reservation);
	Reservation* getReservations();
	bool renewMembership();
	UserType getUserType();
	//Cac phuong thuc khoi tao, huy
public:
	Student();
	Student(string id, string name, DateTime dateOfBirth, Account account, string studentId, University uni, DateTime renewDate, MemberShip membership);
public:
	//Cac getter
	string getStudentId();
	University getUniversity();
	DateTime getRenewalDate();
	MemberShip getMemberShip();
public:
	//Cac setter
	void getStudentId(string);
	void getUniversity(University);
	void getRenewalDate(DateTime);
	void getMemberShip(MemberShip);
};
