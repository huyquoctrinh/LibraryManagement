#include "Reservation.h"

bool Reservation::isReturned() const
{
    return _isReturned;
}

void Reservation::setIsReturned(bool newIsReturned)
{
    _isReturned = newIsReturned;
}

vector<string> Reservation::getReserve()
{
    vector<string> res;
    res.push_back(this->_id);
    res.push_back(this->_startTime.toString());
    res.push_back(this->_expiredTime.toString());
    res.push_back(this->_content->getId());
    res.push_back(this->_borrower->getId());
	if (this->_isReturned==0){
		res.push_back("0");
	}
	else{
		res.push_back("1");
	}
    return res;
}

const string &Reservation::id() const
{
    return _id;
}

void Reservation::setId(const string &newId)
{
    _id = newId;
}

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

Content* Reservation::getContent()
{
	return _content;
}

User* Reservation::getBorrower()
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

void Reservation::setContent(Content* content)
{
	_content = content;
}

void Reservation::setBorrower(User* borrower)
{
	_borrower = borrower;
}

Reservation::Reservation()
{
}

Reservation::Reservation(DateTime start, DateTime expire, Content* content, User* borrower, bool isReturned)
{
	_startTime = start;
	_expiredTime = expire;
	_content = content;
	_borrower = borrower;
    _isReturned = isReturned;
}
