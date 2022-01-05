#include "borroweditemwidget.h"
#include "ui_borroweditemwidget.h"

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
    _reservation = reservation;
    Reading reading = *(static_cast<Reading*>(reservation.getContent()));
    User* user = reservation.getBorrower();

    QString title = QString::fromStdString(reading.getTitle());
    QString category = QString::fromStdString(ToValue(reading.getCategory()));
    QString authors = QString::fromStdString(reading.getAuthors());
    QString borrowerName = QString::fromStdString(user->getName());

    ui->lblTitle->setText(title);
    ui->lblCategory->setText(category);
    ui->lblAuthors->setText(authors);
    if (reservation.isReturned()) {
        ui->lblReturned->setText("Returned");
        ui->lblReturned->setStyleSheet("QLabel { color : green; }");
    }
    else {
        ui->lblReturned->setText("Borrowing");
        ui->lblReturned->setStyleSheet("QLabel { color : red; }");
    }
    // Only student can return item
    ui->btnReturn->setEnabled(user->getUserType() == uStudent && !reservation.isReturned());
    ui->label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_4->setText("<a href=\"abc\">" + borrowerName + "</a>");
}

void BorrowedItemWidget::on_label_4_linkActivated(const QString &link)
{
    qInfo() << link;
}


void BorrowedItemWidget::on_btnReturn_clicked()
{
    User* currentUser = LibMS::getInstance()->getCurrentUser();
    Student* student = dynamic_cast<Student*>(currentUser);
    student->returnReservation(_reservation);
}

