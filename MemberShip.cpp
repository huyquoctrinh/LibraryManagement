#include "MemberShip.h"


MemberShip::MemberShip()
{
	_fee = 0;
}

MemberShip::MemberShip(string typeName, double fee)
{
	_typeName = typeName;
    _fee = fee;
}

MemberShip::MemberShip(const MemberShip & other)
{
    this->_typeName = other._typeName;
    this->_fee = other._fee;
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
