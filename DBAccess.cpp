#include "DBAccess.h"

const ReservationData &DBAccess::getReservationDB() const
{
    return *_reservationDB;
}

const ContentData &DBAccess::getContentDB() const
{
    return *_contentDB;
}

const UserData &DBAccess::getUserDB() const
{
    return *_userDB;
}

DBAccess::DBAccess()
{
    // Construct _reservationDB, _contentDB, _userDB
    this->_userDB = new UserData("Account.csv");
    this->_reservationDB = new ReservationData("Reservation.csv");
    this->_contentDB = new ContentData("Book.csv");
}

DBAccess *DBAccess::getInstance()
{
    if (_instance == NULL) {
        _instance = new DBAccess;
    }
    return _instance;
}
