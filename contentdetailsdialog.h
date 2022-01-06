#ifndef CONTENTDETAILSDIALOG_H
#define CONTENTDETAILSDIALOG_H

#include <QDialog>
#include "Content.h"
#include "Reading.h"
#include "Book.h"
#include "AcademicJournal.h"
#include "User.h"
#include "Student.h"
#include "Reservation.h"
#include "LibMS.h"
#include <QDebug>

#define ERROR_OUT_OF_DAYS "Borrowed item must be returned within limited days of the Start Date."
#define ERROR_FAILED "Cannot complete your reservation. Please contact the staff for more information."
#define SUCCESS_RESERVATION "Successfully reserve!"

namespace Ui {
class ContentDetailsDialog;
}

class ContentDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContentDetailsDialog(QWidget *parent = nullptr);
    ~ContentDetailsDialog();

public:
    void setInfo();

private slots:
    void on_btnCancel_clicked();

    void on_btnReserve_clicked();

    void on_btnBorrow_clicked();

    void on_edtDateReturned_userDateChanged(const QDate &date);

private:
    Ui::ContentDetailsDialog *ui;
};

#endif // CONTENTDETAILSDIALOG_H
