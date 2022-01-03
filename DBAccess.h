#ifndef DBACCESS_H
#define DBACCESS_H

#include "ReservationData.h"

class DBAccess
{
private:
    ReservationData _reservationDB;
    //ContentData _contentDB;
    //UserData _userDB;
    static DBAccess* _instance;
private:
    DBAccess();
public:
    static DBAccess* getInstance();
    const ReservationData &getReservationDB() const;
    void setReservationDB(const ReservationData &newReservationDB);
};

#endif // DBACCESS_H
