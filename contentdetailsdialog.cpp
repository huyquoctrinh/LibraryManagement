#include "contentdetailsdialog.h"
#include "ui_contentdetailsdialog.h"

ContentDetailsDialog::ContentDetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContentDetailsDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->edtDateStart->setDate(QDate::currentDate());
    ui->edtDateReturned->setDate(QDate::currentDate());
    ui->lblSttReserve->setVisible(false);
    setInfo();
}

ContentDetailsDialog::~ContentDetailsDialog()
{
    delete ui;
}

void ContentDetailsDialog::setInfo()
{
    User* _currentUser = LibMS::getInstance()->getCurrentUser();
    Reading* reading = LibMS::getInstance()->getViewingReading();
    ui->lblTitle->setText(QString::fromStdString(reading->getTitle()));
    ui->lblAuthor->setText(QString::fromStdString(reading->getAuthors()));
    ui->lblPublicationYear->setText(QString::number(reading->getPublicationYear()));
    if (ToValue(reading->getStatus()))
        ui->lblStatus->setText("Available");
    else
        ui->lblStatus->setText("Unavailable");
    if (reading->getCategory() == catBook) {
        Book* book = dynamic_cast<Book*>(reading);
        ui->lblISBN->setText(QString::fromStdString(book->getISBN()));
        ui->lblGenre->setText(QString::fromStdString(book->getGenre()));
        ui->lblPublisher->setText(QString::fromStdString(book->getPublisher()));
        ui->rdbBook->setChecked(true);
    }
    else if (reading->getCategory() == catAcademicJournal) {
        AcademicJournal* journal = dynamic_cast<AcademicJournal*>(reading);
        ui->lblISSN->setText(QString::fromStdString(journal->getISSN()));
        ui->lblSubject->setText(QString::fromStdString(journal->getSubject()));
        ui->lblVol->setText(QString::number(journal->getVolume()));
        ui->rdbJournal->setChecked(true);
    }
    // Borrow button is enabled when all the following criteria is correct:
    // 1. User is student
    // 2. The content is available
    ui->btnBorrow->setEnabled(_currentUser && _currentUser->getUserType() == uStudent && ToValue(reading->getStatus()));
}

void ContentDetailsDialog::on_btnCancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void ContentDetailsDialog::on_btnReserve_clicked()
{
    User* _currentUser = LibMS::getInstance()->getCurrentUser();
    Reading* _currentReading = LibMS::getInstance()->getViewingReading();
    // Only student can borrow items
    Student* student = dynamic_cast<Student*>(_currentUser);
    DateTime startDate(ui->edtDateStart->date().day(), ui->edtDateStart->date().month(), ui->edtDateStart->date().year());
    DateTime expiredDate(ui->edtDateReturned->date().day(), ui->edtDateReturned->date().month(), ui->edtDateReturned->date().year());
    Reservation newReservation(startDate, expiredDate, _currentReading, _currentUser, false);
    bool result = student->reserve(newReservation);
    if (result) // Successfully reserve
    {
        ui->lblSttReserve->setText(SUCCESS_RESERVATION);
        ui->lblSttReserve->setStyleSheet("QLabel { color : green; }");
        ui->lblSttReserve->setVisible(true);
    }
    else
    {
       ui->lblSttReserve->setText(ERROR_FAILED);
       ui->lblSttReserve->setStyleSheet("QLabel { color : red; }");
       ui->lblSttReserve->setVisible(true);
    }

}


void ContentDetailsDialog::on_btnBorrow_clicked()
{
    ui->lblTitle_2->setText(ui->lblTitle->text());
    ui->lblAuthor_2->setText(ui->lblAuthor->text());
    ui->lblPublicationYear_2->setText(ui->lblPublicationYear->text());
    ui->stackedWidget->setCurrentIndex(1);
}

void ContentDetailsDialog::on_edtDateReturned_userDateChanged(const QDate &date)
{
    if (date > QDate::currentDate().addDays(30) || date < QDate::currentDate()) {
        ui->lblSttReserve->setText(ERROR_OUT_OF_DAYS);
        ui->lblSttReserve->setStyleSheet("QLabel { color : red; }");
        ui->lblSttReserve->setVisible(true);
        ui->btnReserve->setEnabled(false);
    }
    else {
        ui->lblSttReserve->setVisible(false);
        ui->btnReserve->setEnabled(true);
    }
}

