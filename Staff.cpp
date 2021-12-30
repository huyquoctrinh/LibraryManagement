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

vector<Student> Staff::getStudents()
{
    return vector<Student>();
}

UserType Staff::getUserType() {
	return uStaff;
}

Staff::Staff() : User()
{
}

Staff::Staff(string name, DateTime dateOfBirth, bool gender, Account account)
    : User(name, dateOfBirth, gender, account)
{
}

Staff::~Staff() {

}
