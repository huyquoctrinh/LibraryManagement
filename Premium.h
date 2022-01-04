#pragma once
#include "MemberShip.h"

#define MEMBERSHIP_PREMIUM "Premium"
#define PREMIUM_FEE 120

class Premium : public MemberShip
{
public:
    int getMaxBorrowDate();
public:
	//Cac phuong thuc khoi tao, huy
    Premium();
    Premium(const Premium&);
};
