#include "Premium.h"

int Premium::getMaxBorrowDate()
{
    return 60;
}

Premium::Premium() : MemberShip(MEMBERSHIP_PREMIUM, PREMIUM_FEE)
{
}

Premium::Premium(const Premium &other) : MemberShip(other)
{

}
