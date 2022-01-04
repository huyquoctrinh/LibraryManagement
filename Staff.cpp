#include "Staff.h"

bool Staff::addContent(Content* newContent)
{
    ContentData contentDB = DBAccess::getInstance()->getContentDB();
    bool addResult = contentDB.addContent(newContent);
    return addResult;
}

bool Staff::updateContent(Content* updatedContent)
{
    ContentData contentDB = DBAccess::getInstance()->getContentDB();
    bool updateResult = contentDB.updateContent(updatedContent);
    return updateResult;
}

bool Staff::removeContent(Content* content)
{

    ContentData contentDB = DBAccess::getInstance()->getContentDB();
    bool removeResult = contentDB.deleteContent(content);
    return removeResult;
}

bool Staff::addStudent(Student* student)
{
    UserData userDB = DBAccess::getInstance()->getUserDB();
    bool addResult = userDB.addStudent(student);
    return addResult;
}

bool Staff::updateStudent(Student* student)
{
    UserData userDB = DBAccess::getInstance()->getUserDB();
    bool result = userDB.updateStudent(student);
    return result;
}

bool Staff::blockStudent(Student* student)
{
    UserData userDB = DBAccess::getInstance()->getUserDB();
    bool result = userDB.deleteStudent(student);
    return result;
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
