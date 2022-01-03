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

void addReadingItem(Reading reading, Ui::BorrowedWidget* ui)
{
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem (listWidgetItem);
    BorrowedItemWidget *theWidgetItem = new BorrowedItemWidget;
    QString title = QString::fromStdString(reading.getTitle());
    QString category = QString::fromStdString(ToValue(reading.getCategory()));
    QString authors = QString::fromStdString(reading.getAuthors());
    theWidgetItem->setContent(title, category, authors, true);
    listWidgetItem->setSizeHint (theWidgetItem->sizeHint());
    ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);
}

void BorrowedWidget::displayContentResults()
{
    /*for (int i = 0; i < results.size(); i++) {
        addReadingItem(results[i], ui);
    }*/
}

void BorrowedWidget::on_btnFilter_clicked()
{
    LibMS* libms = LibMS::getInstance();
    User* currentUser = libms->getCurrentUser();
    ReservationFilter filter(ui->chbReturned->isChecked(), ui->chbBorrowing->isChecked());
    vector<Reservation> resVec;
    if (currentUser->getUserType() == uStudent) {
        Student* student = dynamic_cast<Student*>(currentUser);
        resVec = student->getReservations(filter);
    }
    else
    {

    }

}

