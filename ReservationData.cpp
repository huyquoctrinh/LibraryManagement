#include "ReservationData.h"

bool ReservationData::createReservation()
{
	return false;
}

Reservation * ReservationData::readReservations()
{
	return nullptr;
}

Reservation * ReservationData::readExpiredReservations()
{
	return nullptr;
}

Reservation * ReservationData::readUnexpiredReservations()
{
	return nullptr;
}

bool ReservationData::updateReservation(Reservation)
{
	return false;
}

bool ReservationData::deleteReservation(Reservation)
{
	return false;
}

ReservationData::ReservationData()
{
	_reservations = NULL;
	_reservationCount = 0;
}

ReservationData::ReservationData(Reservation * reservations, int reservationCount)
{
	_reservations = NULL;
	if (reservationCount >= 0)
		reservations = new Reservation[reservationCount];
	for (int i = 0; i < reservationCount; ++i)
		_reservations[i] = reservations[i];
}

ReservationData::ReservationData(const ReservationData& other)
{
	_reservationCount = other._reservationCount;
	_reservations = new Reservation[_reservationCount];
	for (int i = 0; i < _reservationCount; ++i)
		_reservations[i] = other._reservations[i];
}

ReservationData::~ReservationData()
{
	if (_reservations)
		delete[] _reservations;
}

ReservationData& ReservationData::operator=(const ReservationData& other)
{
	if (&other != this)
	{
		if (_reservations)
			delete _reservations;
		_reservationCount = other._reservationCount;
		_reservations = new Reservation[_reservationCount];

		for (int i = 0; i < _reservationCount; ++i)
			_reservations[i] = other._reservations[i];
	}
	return *this;
}

Reservation * ReservationData::getReservations()
{
	return _reservations;
}

int ReservationData::getReservationCount()
{
	return _reservationCount;
}

void ReservationData::setReservations(Reservation * reservations)
{
	_reservations = reservations;
}

void ReservationData::setReservationCount(int reservationCount)
{
	_reservationCount = reservationCount;
}
