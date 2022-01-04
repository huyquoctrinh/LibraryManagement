#include"Student.h"
#include"UserData.h"
#include"Content.h"
#include"Reservation.h"
#include"ReservationFilter.h"

vector<string> Student::getfullInfo(){
    vector<string> res = getInfo();
    res.push_back(this->studentID);
    res.push_back(renewalDate.To_String());
    res.push_back(memberType);
    return res;
}

bool Student::Reserve(Reservation p){
    ReservationData* tmp = new ReservationData("Reservation.csv");
    tmp->addReservation(p);
    return 1;
}

vector<Reservation> Student::getReservation(ReservationFilter p){
    ReservationData* tmp = new ReservationData("Reservation.csv");
    return tmp->readAllReservation();
}

bool Student::renewMembership(){
    DateTime tmp_time = DateTime();
    tmp_time.setMonth(tmp_time.getMonth()+6);
    return 1;
}