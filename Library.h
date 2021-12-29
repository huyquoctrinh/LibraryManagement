#pragma once
#include "Content.h"

class Library
{
private:
	Content* _contents;
	int _contentCount;
public:
	Content* loadContents();
public:
	//Cac phuong thuc khoi tao, huy
	Library();
	Library(Content* contents, int contentCount);
	Library(const Library &);

	virtual ~Library();
public:
	//Toan tu gan bang =
	Library& operator=(const Library&);
public:
	//Cac getter
	Content* getContents();
	int getContentCount();
public:
	//Cac setter
	void setContents(Content*);
	void setContentCount(int);
};