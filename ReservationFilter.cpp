#include "ReservationFilter.h"


bool ReservationFilter::isBorrowing() const
{
    return _isBorrowing;
}

void ReservationFilter::setIsBorrowing(bool newIsBorrowing)
{
    _isBorrowing = newIsBorrowing;
}

bool ReservationFilter::isReturned() const
{
    return _isReturned;
}

void ReservationFilter::setIsReturned(bool newIsReturned)
{
    _isReturned = newIsReturned;
}

ReservationFilter::ReservationFilter()
{
    _isBorrowing = true;
    _isReturned = true;
}

ReservationFilter::ReservationFilter(bool isBorrowing, bool isReturned)
{
    _isBorrowing = isBorrowing;
    _isReturned = isReturned;
}
