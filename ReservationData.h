#pragma once
#include "Reservation.h"
#include "ReservationFilter.h"

class ReservationData
{
private:
	Reservation* _reservations;
	int _reservationCount;
public:
	bool createReservation();
    Reservation* readAllReservations(ReservationFilter);
    Reservation* readUserReservations();
	bool updateReservation(Reservation);
	bool deleteReservation(Reservation);
	//Phuong thuc khoi tao, huy
public:
	ReservationData();
	ReservationData(Reservation* reservations, int reservationCount);
	ReservationData(const ReservationData&);

	virtual ~ReservationData();
public:
	//Toan tu gan bang =
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

