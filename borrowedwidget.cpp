#include "borrowedwidget.h"
#include "ui_borrowedwidget.h"

BorrowedWidget::BorrowedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowedWidget)
{
    ui->setupUi(this);

    on_btnFilter_clicked();
}

BorrowedWidget::~BorrowedWidget()
{
    delete ui;
}

void BorrowedWidget::addReadingItem(Reservation reservation)
{

    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem (listWidgetItem);
    BorrowedItemWidget *theWidgetItem = new BorrowedItemWidget;
    connect(theWidgetItem, SIGNAL(newReturn()), this, SLOT(receiveNewReturn()));
    theWidgetItem->setContent(reservation);
    listWidgetItem->setSizeHint (theWidgetItem->sizeHint());
    ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);
}

void BorrowedWidget::displayContentResults(vector<Reservation> results)
{
    for (int i = 0; i < results.size(); i++) {
        addReadingItem(results[i]);
    }
}

void BorrowedWidget::on_btnFilter_clicked()
{
    LibMS* libms = LibMS::getInstance();
    User* currentUser = libms->getCurrentUser();
    ui->listWidget->clear();
    ReservationFilter filter(ui->chbBorrowing->isChecked(), ui->chbReturned->isChecked());
    vector<Reservation> resVec;
    if (currentUser->getUserType() == uStudent) {
        Student* student = dynamic_cast<Student*>(currentUser);
        qInfo() << QString::fromStdString(currentUser->getId());
        resVec = student->getReservations(filter);
    }
    else
    {
        Staff* staff = dynamic_cast<Staff*>(currentUser);
        resVec = staff->getAllReservations(filter);
    }
    displayContentResults(resVec);
}

void BorrowedWidget::receiveNewReturn()
{
    on_btnFilter_clicked();
}

