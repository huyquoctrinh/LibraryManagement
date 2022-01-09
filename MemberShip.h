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
    virtual int getMaxBorrowDate();
public:
	//Cac phuong thuc khoi tao, huy
	MemberShip();
    MemberShip(string typeName, double fee);
    MemberShip(const MemberShip&);
public:
	string getTypename(){
		return this->_typeName;
	};
	double getFee();
public:
	//Cac setter
	void setTypename(string);
	void setFee(double);
};
