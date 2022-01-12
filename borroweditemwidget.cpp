#include "borroweditemwidget.h"
#include "ui_borroweditemwidget.h"
#include <QMessageBox>

BorrowedItemWidget::BorrowedItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowedItemWidget)
{
    ui->setupUi(this);
}

BorrowedItemWidget::~BorrowedItemWidget()
{
    delete ui;
}

void BorrowedItemWidget::setContent(Reservation reservation)
{
    this->_reservation = reservation;
    Reading* reading = static_cast<Reading*>(reservation.getContent());

    qInfo() << "Here 1 setContent";
    QString title = QString::fromStdString(reading->getTitle());
    qInfo() << "Here 2 setContent";
    QString category = QString::fromStdString(ToValue(reading->getCategory()));
    QString authors = QString::fromStdString(reading->getAuthors());
    QString borrowerName = QString::fromStdString(_reservation.getBorrower()->getName());
    QString startDate = QString::fromStdString(reservation.getStartTime().toString());
    QString expiredDate = QString::fromStdString(reservation.getExpiredTime().toString());

    ui->lblTitle->setText(title);
    ui->lblCategory->setText(category);
    ui->lblAuthors->setText(authors);
    ui->lblStartDate->setText(startDate);
    ui->lblExpiredDate->setText(expiredDate);
    if (reservation.isReturned()) {
        ui->lblReturned->setText("Returned");
        ui->lblReturned->setStyleSheet("QLabel { color : green; }");
    }
    else {
        ui->lblReturned->setText("Borrowing");
        ui->lblReturned->setStyleSheet("QLabel { color : red; }");
    }
    // Only student can return item
    User* user = LibMS::getInstance()->getCurrentUser();
    ui->btnReturn->setEnabled(user->getUserType() == uStudent && !reservation.isReturned());
    ui->label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_4->setText("<a href=\"abc\">" + borrowerName + "</a>");
}

void BorrowedItemWidget::on_label_4_linkActivated(const QString &link)
{
    Student* student = dynamic_cast<Student*>(_reservation.getBorrower());
    string info = "Name: " + student->getName() + "\n" +
                  "Student ID: " + student->getStudentId() + "\n"
                  "University: " + toValue(student->getUniversity());
    QMessageBox msgBox;
    msgBox.setStyleSheet("QLabel{min-width:500 px; font-size: 13px;}");
    msgBox.setText("Borrower's info");
    msgBox.setInformativeText(QString::fromStdString(info));
    msgBox.exec();
}

void BorrowedItemWidget::on_btnReturn_clicked()
{
    User* currentUser = LibMS::getInstance()->getCurrentUser();
    Student* student = dynamic_cast<Student*>(currentUser);
    student->returnReservation(_reservation);

    emit newReturn();

}

