#pragma once
#include "MemberShip.h"

class Basic : MemberShip
{
public:
	void getMaxBorrowDate(Content);
public:
	//Cac phuong thuc khoi tao, huy
	Basic();
	Basic(string typeName, double fee);
};