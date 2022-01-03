#include "DBAccess.h"

const ReservationData &DBAccess::getReservationDB() const
{
    return _reservationDB;
}

void DBAccess::setReservationDB(const ReservationData &newReservationDB)
{
    _reservationDB = newReservationDB;
}

DBAccess::DBAccess()
{

}

DBAccess *DBAccess::getInstance()
{
    if (_instance == NULL) {
        _instance = new DBAccess;
    }
    return _instance;
}
