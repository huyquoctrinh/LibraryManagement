#include "Basic.h"

int Basic::getMaxBorrowDate()
{
   return 30;
}

Basic::Basic() : MemberShip(MEMBERSHIP_BASIC, BASIC_FEE)
{
}

Basic::Basic(const Basic &other) : MemberShip(other)
{

}

