#include "Premium.h"

void Premium::getMaxBorrowDate(Content)
{
}

Premium::Premium() : MemberShip(MEMBERSHIP_PREMIUM, PREMIUM_FEE)
{
}

Premium::Premium(const Premium &other) : MemberShip(other)
{

}
