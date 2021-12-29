#include "MemberShip.h"

void MemberShip::getMaxBorrowDate(Content)
{
}

MemberShip::MemberShip()
{
	_fee = 0;
}

MemberShip::MemberShip(string typeName, double fee)
{
	_typeName = typeName;
	_fee = fee;
}

string MemberShip::getTypename()
{
	return _typeName;
}

double MemberShip::getFee()
{
	return _fee;
}

void MemberShip::setTypename(string typeName)
{
	_typeName = typeName;
}

void MemberShip::setFee(double fee)
{
	_fee = fee;
}