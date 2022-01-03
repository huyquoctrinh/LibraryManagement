#include "ReservationFilter.h"


bool ReservationFilter::isExpired() const
{
    return _isExpired;
}

void ReservationFilter::setIsExpired(bool newIsExpired)
{
    _isExpired = newIsExpired;
}

bool ReservationFilter::isUnexpired() const
{
    return _isUnexpired;
}

void ReservationFilter::setIsUnexpired(bool newIsUnexpired)
{
    _isUnexpired = newIsUnexpired;
}

ReservationFilter::ReservationFilter()
{
    _isExpired = true;
    _isUnexpired = true;
}

ReservationFilter::ReservationFilter(bool isExpired, bool isUnexpired)
{
    _isExpired = isExpired;
    _isUnexpired = isUnexpired;
}