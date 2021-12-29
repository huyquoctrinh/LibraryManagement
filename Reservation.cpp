#include "Reservation.h"

bool Reservation::isExpired()
{
	return false;
}

int Reservation::getTimeLeft()
{
	return 0;
}

DateTime Reservation::getStartTime()
{
	return _startTime;
}

DateTime Reservation::getExpiredTime()
{
	return _expiredTime;
}

Content Reservation::getContent()
{
	return _content;
}

User Reservation::getBorrower()
{
	return _borrower;
}

void Reservation::setStartTime(DateTime startTime)
{
	_startTime = startTime;
}

void Reservation::setExpiredTime(DateTime expiredTime)
{
	_expiredTime = expiredTime;
}

void Reservation::setContent(Content content)
{
	_content = content;
}

void Reservation::setBorrower(User borrower)
{
	_borrower = borrower;
}

Reservation::Reservation()
{
}

Reservation::Reservation(DateTime start, DateTime expire, Content content, User borrower)
{
	_startTime = start;
	_expiredTime = expire;
	_content = content;
	_borrower = borrower;
}
