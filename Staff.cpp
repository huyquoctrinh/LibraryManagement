#include "Staff.h"

bool Staff::addContent(Content)
{
	return false;
}

bool Staff::updateContent(Content)
{
	return false;
}

bool Staff::removeContent(Content)
{
	return false;
}

bool Staff::addStudent(Student)
{
	return false;
}

bool Staff::blockStudent()
{
	return false;
}

ReservationData Staff::getAllReservationData()
{
	return ReservationData();
}

Student * Staff::getStudents()
{
	return nullptr;
}

UserType Staff::getUserType() {
	return uStaff;
}

Staff::Staff() : User()
{
}

Staff::Staff(string id, string name, DateTime dateOfBirth, Account account) : User(id, name, dateOfBirth, account)
{
}
