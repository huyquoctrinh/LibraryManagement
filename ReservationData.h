#pragma once
#include "Book.h"
#include "Reservation.h"
#include "ReservationFilter.h"
#include "Premium.h"
#include "Account.h"
#include <vector>

class Student;

class ReservationData
{
private:
	Reservation* _reservations;
	int _reservationCount;
public:
	bool createReservation();
    vector<Reservation> readAllReservations(ReservationFilter);
    vector<Reservation> readUserReservations(User*, ReservationFilter);
	bool updateReservation(Reservation);
	bool deleteReservation(Reservation);

public:
	ReservationData();
	ReservationData(Reservation* reservations, int reservationCount);
	ReservationData(const ReservationData&);

	virtual ~ReservationData();
public:
	ReservationData& operator=(const ReservationData&);
public:
	//Cac getter
	Reservation* getReservations();
	int getReservationCount();
public:
	//Cac setter
	void setReservations(Reservation*);
	void setReservationCount(int);
};

