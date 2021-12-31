#pragma once
#include "User.h"
#include "UniversityEnum.h"
#include "MemberShip.h"
#include "Reservation.h"

class Student : public User
{
private:
	string _studentId;
    University _university;
	DateTime _renewalDate;
    MemberShip* _membership;
public:
	bool signUp();
    bool reserve(Content);
	void returnReservation(Reservation);
	Reservation* getReservations();
	bool renewMembership();
	UserType getUserType();
	//Cac phuong thuc khoi tao, huy
public:
    Student();
    Student(string name, DateTime dateOfBirth, bool gender, Account account, string studentId, University uni, DateTime renewDate, MemberShip* membership);
    ~Student();
public:
	//Cac getter
    string getStudentId() const;
    University getUniversity() const;
    DateTime getRenewalDate() const;
    MemberShip* getMemberShip() const;
public:
	//Cac setter
    void setStudentId(string);
    void setUniversity(University);
    void setRenewalDate(DateTime);
    void setMemberShip(MemberShip*);
};

University toKey(string str);
