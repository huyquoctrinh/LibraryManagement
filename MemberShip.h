#pragma once
#include <string>
#include "Content.h"

using namespace std;

class MemberShip
{
private:
	string _typeName;
	double _fee;
public:
	virtual void getMaxBorrowDate(Content);
public:
	//Cac phuong thuc khoi tao, huy
	MemberShip();
    MemberShip(string typeName, double fee);
    MemberShip(const MemberShip&);
public:
	//Cac getter
	string getTypename();
	double getFee();
public:
	//Cac setter
	void setTypename(string);
	void setFee(double);
};
