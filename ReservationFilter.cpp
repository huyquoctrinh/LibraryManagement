#include "ReservationFilter.h"

bool ReservationFilter::isReturned() const
{
    return _isReturned;
}

void ReservationFilter::setIsReturned(bool newIsReturned)
{
    _isReturned = newIsReturned;
}

bool ReservationFilter::isBorrowing() const
{
    return _isBorrowing;
}

void ReservationFilter::setIsBorrowing(bool newIsBorrowing)
{
    _isBorrowing = newIsBorrowing;
}

ReservationFilter::ReservationFilter()
{
    _isReturned = true;
    _isBorrowing = true;
}

ReservationFilter::ReservationFilter(bool isReturned, bool isBorrowing)
{
    _isReturned = isReturned;
    _isBorrowing = isBorrowing;
}
