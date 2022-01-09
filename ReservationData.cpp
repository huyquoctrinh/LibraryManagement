#include "ReservationData.h"
#include "UserData.h"
#include "Student.h"
#include "UserData.h"

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
    vector<Reservation> res;
    for (auto row: this->reservationData){
        string id = row[0];
        DateTime startTime = DateTime(row[1]);
        DateTime expiredTime = DateTime(row[2]);
        UserData* tmp = new UserData("Account.csv"); 
        User* borrower = tmp->GetUser(row[4]); 
        // Content* content = new Content(id, Tocat(row[2]), ToKey(row[]));
        ContentData* ctmp = new ContentData("Book.csv");
        Content* content = ctmp->getContentbyID(row[0]);
        Reservation resevereRow =  Reservation(startTime, expiredTime, content, borrower, 1);
        res.push_back(resevereRow);
    }
    return res;
}

vector<Reservation> ReservationData::readUserReservations(User* user, ReservationFilter filter)
{
    vector<Reservation> res;
    string id = user->getId();
    qInfo() << QString::number(this->reservationData.size()) << " " << QString::fromStdString(id);
    for (auto row:this->reservationData){
        if (id == row[4]){
            DateTime start = DateTime(row[1]);
            DateTime end = DateTime(row[2]);
            UserData* tmp = new UserData("Account.csv");
            User* borrower = tmp->GetUser(row[4]);
            bool isReturned = 1; 
            ContentData* ctmp = new ContentData("Book.csv");
            Content* content = ctmp->getContentbyID(row[0]);
            Reservation newReservation = Reservation(start, end,tmp_content, borrower, isReturned);
            res.push_back(newReservation);
            // return newReservation;
        }
    }
    return res;
    // return NULL;
    // return  {
    //             Reservation(DateTime(3,1,2022), DateTime(9,1,2022), new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), user, true),
    //             Reservation(DateTime(3,1,2022), DateTime(9,1,2022), new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), user, false),
    //             Reservation(DateTime(3,1,2022), DateTime(9,1,2022), new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"), user, true)
    //         };
}

bool ReservationData::updateReservation(Reservation reservation)
{
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

ReservationData::ReservationData(Reservation * reservations, int reservationCount)
{
}


