#ifndef BORROWEDWIDGET_H
#define BORROWEDWIDGET_H

#include <QWidget>
#include <QDebug>
#include "Reading.h"
#include "borroweditemwidget.h"
#include "User.h"
#include "Reservation.h"
#include "ReservationData.h"
#include "LibMS.h"
#include "ReservationFilter.h"

namespace Ui {
class BorrowedWidget;
}

class BorrowedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowedWidget(QWidget *parent = nullptr);
    ~BorrowedWidget();

private:
    Ui::BorrowedWidget *ui;
    QVector<Reservation> _result;
    User* _currentUser;

public:
    void displayContentResults(vector<Reservation>);
    void setCurrentUser(User* user);
    void addReadingItem(Reservation reservation);

private slots:
    void on_btnFilter_clicked();
    void receiveNewReturn();
};

#endif // BORROWEDWIDGET_H
