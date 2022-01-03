#include "ReservationData.h"

#include "Student.h"

bool ReservationData::createReservation()
{
    return false;
}

vector<Reservation> ReservationData::readAllReservations(ReservationFilter filter)
{
    string name = "Lê Quang Trí";
    bool gender = false;
    DateTime dateOfBirth(3, 1, 2002);
    DateTime renewalDate(30, 1, 2022);
    University uni = toKey("HCMUS");
    string sid = "20120022";
    MemberShip* membership = new Premium();
    Account account("abc", "xxx");
    Student* student1 = new Student(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);
    student1->setId("11523");

    Student* student2 = new Student(string("Nguyễn Văn A"), dateOfBirth, gender, account, sid, uni, renewalDate, membership);
    student2->setId("11523");
    return  {
                Reservation(DateTime(3,1,2022), DateTime(9,1,2022),
                            new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), student1, true),
                Reservation(DateTime(3,1,2022), DateTime(9,1,2022),
                            new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), student2, false),
                Reservation(DateTime(3,1,2022), DateTime(9,1,2022),
                            new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), student2, true)
            };
}

vector<Reservation> ReservationData::readUserReservations(User* user, ReservationFilter filter)
{
    return  {
                Reservation(DateTime(3,1,2022), DateTime(9,1,2022), new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), user, true),
                Reservation(DateTime(3,1,2022), DateTime(9,1,2022), new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), user, false),
                Reservation(DateTime(3,1,2022), DateTime(9,1,2022), new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), user, true)
            };
}

bool ReservationData::updateReservation(Reservation)
{

    return false;
}

bool ReservationData::deleteReservation(Reservation)
{
	return false;
}

ReservationData::ReservationData()
{
	_reservations = NULL;
	_reservationCount = 0;
}

ReservationData::ReservationData(Reservation * reservations, int reservationCount)
{
	_reservations = NULL;
	if (reservationCount >= 0)
		reservations = new Reservation[reservationCount];
	for (int i = 0; i < reservationCount; ++i)
		_reservations[i] = reservations[i];
}

ReservationData::ReservationData(const ReservationData& other)
{
	_reservationCount = other._reservationCount;
	_reservations = new Reservation[_reservationCount];
	for (int i = 0; i < _reservationCount; ++i)
		_reservations[i] = other._reservations[i];
}

ReservationData::~ReservationData()
{
	if (_reservations)
		delete[] _reservations;
}

ReservationData& ReservationData::operator=(const ReservationData& other)
{
	if (&other != this)
	{
		if (_reservations)
			delete _reservations;
		_reservationCount = other._reservationCount;
		_reservations = new Reservation[_reservationCount];

		for (int i = 0; i < _reservationCount; ++i)
			_reservations[i] = other._reservations[i];
	}
	return *this;
}

Reservation * ReservationData::getReservations()
{
	return _reservations;
}

int ReservationData::getReservationCount()
{
	return _reservationCount;
}

void ReservationData::setReservations(Reservation * reservations)
{
	_reservations = reservations;
}

void ReservationData::setReservationCount(int reservationCount)
{
	_reservationCount = reservationCount;
}
