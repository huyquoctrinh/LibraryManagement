#pragma once
#include "MemberShip.h"

class Premium : MemberShip
{
public:
	void getMaxBorrowDate(Content);
public:
	//Cac phuong thuc khoi tao, huy
	Premium();
	Premium(string typeName, double fee);
};