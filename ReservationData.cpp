#include "ReservationData.h"

#include "Student.h"

bool ReservationData::createReservation()
{
    createRecord(this->reservationData);
    return true;
}

vector<vector<string> > ReservationData::getAllData()
{
    return this->reservationData;
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

bool ReservationData::updateReservation(Reservation reservation)
{
    vector<string> reserve  = reservation.getReserve();
    this->updateRecord(reserve);
    return 1;
}

bool ReservationData::deleteReservation(Reservation)
{
	return false;
}

ReservationData::ReservationData()
{
}

ReservationData::ReservationData(string ReservationDatabase) : Database(ReservationDatabase){
    this->reservationData = getRecord();
}

ReservationData::ReservationData(Reservation * reservations, int reservationCount)
{
}
