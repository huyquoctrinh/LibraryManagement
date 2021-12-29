#pragma once
#include "Content.h"
#include <string>

using namespace std;

class Reading : public Content
{
	//Cac thuoc tinh
private:
	string _title;
	string _authors;
	int _publicationYear;
	//Cac ham getter
public:
	string getTitle();
	string getAuthors();
	int getPublicationYear();
	//Cac ham setter
public:
	void setTitle(string);
	void setAuthors(string);
	void setPublicationYear(int);
	//Cac phuong thuc khoi tao va huy
public:
	Reading();
    Reading(string id, Category cat, Status status, int availCount, int totalCount, string title, string authors, int publicYear);

	virtual ~Reading();
};
