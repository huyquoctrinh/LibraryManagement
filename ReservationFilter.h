#ifndef RESERVATIONFILTER_H
#define RESERVATIONFILTER_H


class ReservationFilter
{
private:
    bool _isBorrowing;
    bool _isReturned;
public:
    ReservationFilter();
    ReservationFilter(bool isBorrowing, bool isReturned);
    bool isBorrowing() const;
    void setIsBorrowing(bool newIsBorrowing);
    bool isReturned() const;
    void setIsReturned(bool newIsReturned);
};

#endif // RESERVATIONFILTER_H
