#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

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
public:
    int convertDate(){
        if (_month < 3) {
            _year--;
            _month += 12;
        }
        return 365*_year + _year/4 - _year/100 + _year/400 + (153*_month - 457)/5 + _day - 306;
    }
	DateTime getCurrentTime(){
        time_t t = time(NULL);
        tm* tPtr = localtime(&t);
        _day = tPtr->tm_mday;
        _month = tPtr->tm_mon+1;
        _year = tPtr->tm_year;
        DateTime res = DateTime(_day,_month,_year);
        return res;
    }
    int operator -(DateTime b){
        return this->convertDate() - b.convertDate();
    }
    static vector<string> Parse(string line, string seperator){
        vector<string> tokens;
        int startPos = 0;
        size_t foundPos = line.find(seperator, startPos);
        while (foundPos != string::npos){
            int count =  foundPos - startPos;
            string token = line.substr(startPos, count);
            tokens.push_back(token);
            startPos = foundPos + seperator.length();
            foundPos = line.find(seperator, startPos);
        }
        int count  =  line.length() - startPos;
        string token = line.substr(startPos, count);
        tokens.push_back(token);
        return tokens;
    }
    DateTime(string DateTime){
        vector<string> date = Parse(DateTime,"/");
        this->_day = stoi(date[0]);
        this->_month = stoi(date[1]);
        this->_year = stoi(date[2]); 
    } 
    string To_String(){
        stringstream writer;
        writer<<this->_day<<"/"<<this->_month<<"/"<<this->_year;
        return writer.str();
    }  
};
