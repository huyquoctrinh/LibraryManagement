#ifndef BORROWEDITEMWIDGET_H
#define BORROWEDITEMWIDGET_H

#include <QWidget>
#include <QDebug>
#include "Reading.h"
#include "Reservation.h"
#include "Student.h"
#include "LibMS.h"

namespace Ui {
class BorrowedItemWidget;
}

class BorrowedItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowedItemWidget(QWidget *parent = nullptr);
    ~BorrowedItemWidget();

private:
    Ui::BorrowedItemWidget *ui;
    Reservation _reservation;


public:
    void setContent(Reservation);

private slots:
    void on_label_4_linkActivated(const QString &link);
    void on_btnReturn_clicked();

signals:
    void newReturn();
};

#endif // BORROWEDITEMWIDGET_H
