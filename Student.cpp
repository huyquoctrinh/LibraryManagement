#include "Student.h"

bool Student::signUp()
{
	return false;
}

void Student::reserve(Content)
{
}

void Student::returnReservation(Reservation)
{
}

Reservation * Student::getReservations()
{
	return nullptr;
}

UserType Student::getUserType() {
	return uStudent;
}

bool Student::renewMembership()
{
	return false;
}

Student::Student() :User()
{
}

Student::Student(string name, DateTime dateOfBirth, bool gender, Account account, string studentId, University uni, DateTime renewDate, MemberShip *membership)
    :User(name, dateOfBirth, gender, account)
{
	_studentId = studentId;
	_university = uni;
	_renewalDate = renewDate;
    _membership = membership;
}

Student::~Student()
{
    delete _membership;
}

string Student::getStudentId() const
{
	return _studentId;
}

University Student::getUniversity() const
{
	return _university;
}

DateTime Student::getRenewalDate() const
{
	return _renewalDate;
}

MemberShip* Student::getMemberShip() const
{
	return _membership;
}

void Student::setStudentId(string studentId)
{
	_studentId = studentId;
}

void Student::setUniversity(University university)
{
	_university = university;
}

void Student::setRenewalDate(DateTime renewTime)
{
	_renewalDate = renewTime;
}

void Student::setMemberShip(MemberShip* membership)
{
	_membership = membership;
}



University toKey(string str) {
    if (str == "USSH")
        return USSH;
    if (str == "HCMUT")
        return HCMUT;
    if (str == "IU")
        return IU;
    return HCMUS;
}
