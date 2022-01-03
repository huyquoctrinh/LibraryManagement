#ifndef RESERVATIONFILTER_H
#define RESERVATIONFILTER_H


class ReservationFilter
{
private:
    bool _isReturned;
    bool _isBorrowing;
public:
    ReservationFilter();
    ReservationFilter(bool, bool);
    bool isReturned() const;
    void setIsReturned(bool newIsReturned);
    bool isBorrowing() const;
    void setIsBorrowing(bool newIsBorrowing);
};

#endif // RESERVATIONFILTER_H
