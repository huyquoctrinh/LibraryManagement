#include "Staff.h"

bool Staff::addContent(Content* newContent)
{
    /*
     * ContentData contentDB = DBAccess::getInstance()->getContentDB();
     * book addResult = contentDB.addContent(newContent);
     * return addResult;
    */

	return false;
}

bool Staff::updateContent(Content* updatedContent)
{
    /*
     * ContentData contentDB = DBAccess::getInstance()->getContentDB();
     * book updateResult = contentDB.updateContent(newContent);
     * return updateResult;
    */
	return false;
}

bool Staff::removeContent(Content*)
{
    /*
     * ContentData contentDB = DBAccess::getInstance()->getContentDB();
     * book removeResult = contentDB.deleteContent(newContent);
     * return removeResult;
    */
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

vector<Reservation> Staff::getAllReservations(ReservationFilter filter)
{
    DBAccess* dbaccess = DBAccess::getInstance();
    ReservationData d = dbaccess->getReservationDB();
    vector<Reservation> res = d.readAllReservations(filter);
    return res;
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
