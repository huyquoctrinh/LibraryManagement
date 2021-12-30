#pragma once
#include "MemberShip.h"

#define MEMBERSHIP_BASIC "Basic"
#define BASIC_FEE 60

class Basic : public MemberShip
{
public:
	void getMaxBorrowDate(Content);
public:
	//Cac phuong thuc khoi tao, huy
    Basic();
    Basic(const Basic&);
};
