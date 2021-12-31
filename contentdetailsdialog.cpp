#include "contentdetailsdialog.h"
#include "ui_contentdetailsdialog.h"

ContentDetailsDialog::ContentDetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContentDetailsDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

ContentDetailsDialog::~ContentDetailsDialog()
{
    delete ui;
}

void ContentDetailsDialog::setInfo(Reading* reading, User* user)
{
    _currentUser = user;
    _currentReading = reading;
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
    ui->btnBorrow->setEnabled(user && user->getUserType() == uStudent && ToValue(reading->getStatus()));
}

void ContentDetailsDialog::on_btnCancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void ContentDetailsDialog::on_btnReserve_clicked()
{
    // Only student can borrow items
    Student* student = dynamic_cast<Student*>(_currentUser);
    bool result = student->reserve(*_currentReading);
    if (result) // Successfully reserve
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
}


void ContentDetailsDialog::on_btnBorrow_clicked()
{
    ui->lblTitle_2->setText(ui->lblTitle->text());
    ui->lblAuthor_2->setText(ui->lblAuthor->text());
    ui->lblPublicationYear_2->setText(ui->lblPublicationYear->text());
    ui->stackedWidget->setCurrentIndex(1);
}

