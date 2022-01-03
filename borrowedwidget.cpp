#include "borrowedwidget.h"
#include "ui_borrowedwidget.h"

BorrowedWidget::BorrowedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowedWidget)
{
    ui->setupUi(this);

    //displayContentResults(results);
}

BorrowedWidget::~BorrowedWidget()
{
    delete ui;
}

void addReadingItem(Reservation reservation, Ui::BorrowedWidget* ui)
{

    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem (listWidgetItem);
    BorrowedItemWidget *theWidgetItem = new BorrowedItemWidget;

    theWidgetItem->setContent(reservation);
    listWidgetItem->setSizeHint (theWidgetItem->sizeHint());
    ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);
}

void BorrowedWidget::displayContentResults(vector<Reservation> results)
{
    for (int i = 0; i < results.size(); i++) {
        addReadingItem(results[i], ui);
    }
}

void BorrowedWidget::on_btnFilter_clicked()
{
    LibMS* libms = LibMS::getInstance();
    User* currentUser = libms->getCurrentUser();
    qInfo() << QString::fromStdString(currentUser->getName());
    ReservationFilter filter(ui->chbExpired->isChecked(), ui->chbUnexpired->isChecked());
    vector<Reservation> resVec;
    if (currentUser->getUserType() == uStudent) {
        Student* student = dynamic_cast<Student*>(currentUser);
        resVec = student->getReservations(filter);
    }
    else
    {
        Staff* staff = dynamic_cast<Staff*>(currentUser);
        resVec = staff->getAllReservations(filter);
    }
    displayContentResults(resVec);
}

