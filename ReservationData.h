#pragma once
#include "Database.h"
#include "Book.h"
#include "Reservation.h"
#include "ReservationFilter.h"
#include "Premium.h"
#include "Account.h"
#include <vector>
#include <QDebug>

class Student;

class ReservationData : public Database
{
private:
    vector<vector<string>> reservationData;
public:
	bool createReservation();
    vector<vector<string>> getAllData();
    vector<Reservation> readAllReservations(ReservationFilter);
    vector<Reservation> readUserReservations(User*, ReservationFilter);
	bool updateReservation(Reservation);
	bool deleteReservation(Reservation);

public:
	ReservationData();
    ReservationData(string ReservationDatabase);
    ReservationData(Reservation* reservations, int reservationCount);
};

