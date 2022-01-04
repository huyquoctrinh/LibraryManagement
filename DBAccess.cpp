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
}

DBAccess *DBAccess::getInstance()
{
    if (_instance == NULL) {
        _instance = new DBAccess;
    }
    return _instance;
}
