#pragma once
#include "Reading.h"
#include <string>

using namespace std;

class Book : public Reading
{
	//Cac thuoc tinh
private:
	string _publisher;
	string _ISBN;
	string _genre;
	//Cac ham getter
public:
	string getPublisher();
	string getISBN();
	string getGenre();
	//Cac ham setter
public:
	void setPublisher(string);
	void setISBN(string);
	void setGenre(string);
	//Cac phuong thuc khoi tao va huy
public:
	Book();
    Book(string id, Status status, int availCount, int totalCount, string title, string authors, int publicYear, string publisher, string ISBN, string genre);
    Book(Status status, int availCount, int totalCount, string title, string authors, int publicYear, string publisher, string ISBN, string genre);
	virtual ~Book();
};
