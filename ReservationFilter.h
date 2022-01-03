#ifndef RESERVATIONFILTER_H
#define RESERVATIONFILTER_H


class ReservationFilter
{
private:
    bool _isExpired;
    bool _isUnexpired;
public:
    ReservationFilter();
    ReservationFilter(bool isExpired, bool isUnexpired);
    bool isExpired() const;
    void setIsExpired(bool newIsExpired);
    bool isUnexpired() const;
    void setIsUnexpired(bool newIsUnexpired);
};

#endif // RESERVATIONFILTER_H