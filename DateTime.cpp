#include "DateTime.h"

int DateTime::getDay()
{
	return _day;
}

int DateTime::getMonth()
{
	return _month;
}

int DateTime::getYear()
{
	return _year;
}

void DateTime::setDay(int day)
{
	_day = day;
}

void DateTime::setMonth(int month)
{
	_month = month;
}

void DateTime::setYear(int year)
{
	_year = year;
}

DateTime::DateTime()
{
	time_t t = std::time(0);
	tm* now = std::localtime(&t);

	_year = now->tm_year + 1900;
	_month = now->tm_mon + 1;
	_day = now->tm_mday;
}

DateTime::DateTime(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

DateTime::~DateTime()
{
}

bool DateTime::isLeapYear(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) ||
		(year % 400 == 0));
}

bool DateTime::isValidDateTime(int day, int month, int year)
{
	if (year < 0)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	if (month == 2)
	{
		if (DateTime::isLeapYear(year))
			return (day <= 29);
		else
			return (day <= 28);
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);

	return true;
}

string DateTime::toString() const
{
	stringstream writer;
	writer << _day << "/" << _month << "/" << _year;
	return writer.str();
}

istream& operator>>(istream &is, DateTime &x)
{
	cout << "Nhap ngay: ";
	is >> x._day;
	cout << "Nhap thang: ";
	is >> x._month;
	cout << "Nhap nam: ";
	is >> x._year;
	return is;
}

ostream& operator<<(ostream &os, const DateTime &x)
{
	os << x.toString();
	return os;
}
