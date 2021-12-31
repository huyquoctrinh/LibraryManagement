#ifndef CONTENTDETAILSDIALOG_H
#define CONTENTDETAILSDIALOG_H

#include <QDialog>
#include "Content.h"
#include "Reading.h"
#include "Book.h"
#include "AcademicJournal.h"
#include "User.h"
#include "Student.h"

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
    void setInfo(Reading* reading, User*);
    void setUsertype(QString usertype);

private slots:
    void on_btnCancel_clicked();

    void on_btnReserve_clicked();

    void on_btnBorrow_clicked();

private:
    Ui::ContentDetailsDialog *ui;
    User* _currentUser;
    Reading* _currentReading;
};

#endif // CONTENTDETAILSDIALOG_H
