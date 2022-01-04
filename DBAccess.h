#ifndef DBACCESS_H
#define DBACCESS_H

#include "ReservationData.h"
#include "ContentData.h"
#include "UserData.h"

class DBAccess
{
private:
    ReservationData *_reservationDB;
    ContentData *_contentDB;
    UserData *_userDB;
    static DBAccess* _instance;
private:
    DBAccess();
public:
    static DBAccess* getInstance();
    const ReservationData &getReservationDB() const;
    const ContentData &getContentDB() const;
    const UserData &getUserDB() const;
};

#endif // DBACCESS_H
