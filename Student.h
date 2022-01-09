#pragma once
#include "User.h"
#include "UniversityEnum.h"
#include "MemberShip.h"
#include "Reservation.h"
#include "ReservationFilter.h"
#include "Book.h"
#include "DBAccess.h"
#include <vector>

class Student : public User
{
private:
	string _studentId;
    University _university;
	DateTime _renewalDate;
    MemberShip* _membership;
public:
    bool reserve(Reservation);
	void returnReservation(Reservation);
    vector<Reservation> getReservations(ReservationFilter filter);
	bool renewMembership();
	UserType getUserType();

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
    vector<string> getAllStudentData();
public:
	//Cac setter
    void setStudentId(string);
    void setUniversity(University);
    void setRenewalDate(DateTime);
    void setMemberShip(MemberShip*);
};

University toKey(string str);
string toValue(University uni);
