#include "Student.h"

bool Student::reserve(Reservation reservation)
{
    // Reserve a content
    // If reserve successfully, return true. If not, return false
    // Should call createReservation() function of ReservationData class
    // Should check if the content is available or not
    return true;
}

void Student::returnReservation(Reservation reservation)
{
    DBAccess* dbaccess = DBAccess::getInstance();
    ReservationData reservationDb = dbaccess->getReservationDB();
    // Update reservation
    reservation.setIsReturned(true);
    reservationDb.updateReservation(reservation);
}

vector<Reservation> Student::getReservations(ReservationFilter filter)
{
    DBAccess* dbaccess = DBAccess::getInstance();
    ReservationData d = dbaccess->getReservationDB();
    vector<Reservation> res = d.readUserReservations(this, filter);
    return res;
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

vector<string> Student::getAllStudentData(){
    vector<string> res;
    res.push_back(this->getId());
    Account acc = this->getAccount();
    string uname = acc.getUsername();
    string passw = acc.getPassword();
    res.push_back(uname);
    res.push_back(passw);
    res.push_back(this->getName());
    DateTime dt = this->getDateOfBirth();
    res.push_back(dt.To_String());
    res.push_back(to_string(this->getGender()));
    // res.push_back() 
    res.push_back("0");
    res.push_back(this->_studentId);
    DateTime renewalDate = this->getRenewalDate();
    res.push_back(renewalDate.To_String());
    string typename = this->_membership->getTypename();
    res.push_back(typename);
    return res;
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

string toValue(University uni)
{
    switch (uni) {
        case USSH: return "USSH";
        case HCMUT: return "HCMUT";
        case IU: return "IU";
    }
    return "HCMUS";
}
