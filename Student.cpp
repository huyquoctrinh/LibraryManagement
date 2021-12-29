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

Student::Student(string id, string name, DateTime dateOfBirth, Account account, string studentId, University uni, DateTime renewDate, MemberShip membership):User(id, name, dateOfBirth, account)
{
	_studentId = studentId;
	_university = uni;
	_renewalDate = renewDate;
	_membership = membership;
}

string Student::getStudentId()
{
	return _studentId;
}

University Student::getUniversity()
{
	return _university;
}

DateTime Student::getRenewalDate()
{
	return _renewalDate;
}

MemberShip Student::getMemberShip()
{
	return _membership;
}

void Student::getStudentId(string studentId)
{
	_studentId = studentId;
}

void Student::getUniversity(University university)
{
	_university = university;
}

void Student::getRenewalDate(DateTime renewTime)
{
	_renewalDate = renewTime;
}

void Student::getMemberShip(MemberShip membership)
{
	_membership = membership;
}
