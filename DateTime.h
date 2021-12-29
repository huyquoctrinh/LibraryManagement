#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class DateTime
{
private:
	int _day;
	int _month;
	int _year;
public:
	int getDay();
	int getMonth();
	int getYear();

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

public:
	DateTime();
	DateTime(int day, int month, int year);

	~DateTime();
public:
	static bool isLeapYear(int year);
	static bool isValidDateTime(int, int, int);

	string toString() const;
public:
	friend istream& operator>>(istream &is, DateTime &x);
	friend ostream& operator<<(ostream &os, const DateTime &x);
};