#pragma once
#include "Reading.h"
#include <string>

using namespace std;

class AcademicJournal : public Reading
{
	//Cac thuoc tinh
private:
	int _volume;
	string _ISSN;
	string _subject;
public:
	//Cac ham getter
	int getVolume();
	string getISSN();
	string getSubject();
public:
	//Cac ham setter
	void setVolume(int);
	void setISSN(string);
	void setSubject(string);
	//Cac phuong thuc khoi tao va huy
public:
	AcademicJournal();
    AcademicJournal(string id, Status status, int availCount, int totalCount, string title, string authors, int publicYear, int volume, string ISSN, string subject);
    AcademicJournal(Status status, int availCount, int totalCount, string title, string authors, int publicYear, int volume, string ISSN, string subject);

	virtual ~AcademicJournal();
};
