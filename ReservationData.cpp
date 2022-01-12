#include "ReservationData.h"
#include "UserData.h"
#include "Student.h"
#include "UserData.h"


bool ReservationData::createReservation(Reservation reservation)
{
    this->reservationData = getRecord();
    QString lastId = QString::fromStdString(this->reservationData[this->reservationData.size() - 1][0]);
    int maxId = lastId.toInt() + 1;

    reservation.setId(to_string(maxId));
    addRecord(reservation.getReserve());
    this->reservationData = getRecord();
    return true;
}

vector<vector<string> > ReservationData::getAllData()
{
    return this->reservationData;
}

bool checkFilter(ReservationFilter filter, Reservation reservation) {

    if (filter.isBorrowing() && reservation.isReturned() == false)
        return true;
    if (filter.isReturned() && reservation.isReturned() == true)
        return true;
    return false;
}

vector<Reservation> ReservationData::readAllReservations(ReservationFilter filter)
{
    this->reservationData = getRecord();
    vector<Reservation> res;

    for (auto row: this->reservationData){

        string id = row[0];
        DateTime startTime = DateTime(row[1]);
        DateTime expiredTime = DateTime(row[2]);
        UserData* tmp = new UserData("Account.csv"); 
        User* borrower = tmp->GetUser(row[4]);
        ContentData* ctmp = new ContentData("Book.csv");
        Content* content = ctmp->getContentbyID(row[3]);
        qInfo() << QString::fromStdString(row[3]);
        bool isReturned = row[5] == "1";
        Reservation resevereRow =  Reservation(startTime, expiredTime, content, borrower, isReturned);
        resevereRow.setId(id);
        if (content && checkFilter(filter, resevereRow))
            res.push_back(resevereRow);
    }
    return res;
}

vector<Reservation> ReservationData::readUserReservations(User* user, ReservationFilter filter)
{
    this->reservationData = getRecord();
    vector<Reservation> res;
    string id = user->getId();
    for (auto row:this->reservationData){
        if (id == row[4]){
            string id = row[0];
            DateTime start = DateTime(row[1]);
            DateTime end = DateTime(row[2]);
            UserData* tmp = new UserData("Account.csv");
            User* borrower = tmp->GetUser(row[4]);
            bool isReturned = row[5] == "1";
            ContentData* ctmp = new ContentData("Book.csv");
            Content* content = ctmp->getContentbyID(row[3]);
            Reservation newReservation = Reservation(start, end, content, borrower, isReturned);
            newReservation.setId(id);
            if (content && checkFilter(filter, newReservation))
                res.push_back(newReservation);
        }
    }
    return res;
}

bool ReservationData::updateReservation(Reservation reservation)
{
    this->reservationData = getRecord();
    vector<string> reserve  = reservation.getReserve();
    this->updateRecord(reserve);
    this->reservationData = getRecord();
    return 1;
}

bool ReservationData::deleteReservation(Reservation a)
{
    vector<string> reserve = a.getReserve();
    vector<vector<string>> tmp;
    bool check = 0;
    for (auto row: this->reservationData){
        if (compare(row,reserve)){
            check = 1;
            continue;
        }
        else{
            tmp.push_back(row);
        }
    } 
    this->reservationData = getRecord();
    return check;
}

ReservationData::ReservationData()
{
}

ReservationData::ReservationData(string ReservationDatabase) : Database(ReservationDatabase){
    this->reservationData = getRecord();

}


