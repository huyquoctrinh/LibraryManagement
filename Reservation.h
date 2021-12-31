#pragma once
#include "DateTime.h"
#include "Content.h"
#include "User.h"

class Reservation
{
private:
	DateTime _startTime;
	DateTime _expiredTime;
	Content _content;
    User* _borrower;
public:
	bool isExpired();
	int getTimeLeft();
	//Cac getter
public:
	DateTime getStartTime();
	DateTime getExpiredTime();
	Content getContent();
    User* getBorrower();

	//Cac setter
	void setStartTime(DateTime);
	void setExpiredTime(DateTime);
	void setContent(Content);
    void setBorrower(User*);
	//Cac phuong thuc khoi tao, huy
public:
	Reservation();
    Reservation(DateTime start, DateTime expire, Content content, User* borrower);
};
