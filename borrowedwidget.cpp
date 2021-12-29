#include "borrowedwidget.h"
#include "ui_borrowedwidget.h"

BorrowedWidget::BorrowedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowedWidget)
{
    ui->setupUi(this);
    QVector<Reading> results;
    results << Reading("12", catBook, sttAvailable, 10, 20, "Harry Potter", "J.K Rowling", 1999)
            << Reading("12", catBook, sttAvailable, 10, 20, "Harry Potter", "J.K Rowling", 1999)
            << Reading("12", catBook, sttAvailable, 10, 20, "Harry Potter", "J.K Rowling", 1999)
            << Reading("12", catBook, sttAvailable, 10, 20, "Harry Potter", "J.K Rowling", 1999)
            << Reading("12", catBook, sttAvailable, 10, 20, "Harry Potter", "J.K Rowling", 1999)
            << Reading("12", catBook, sttAvailable, 10, 20, "Harry Potter", "J.K Rowling", 1999)
            << Reading("12", catBook, sttAvailable, 10, 20, "Harry Potter", "J.K Rowling", 1999);
    displayContentResults(results);
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

void BorrowedWidget::displayContentResults(QVector<Reading> results)
{
    for (int i = 0; i < results.size(); i++) {
        addReadingItem(results[i], ui);
    }
}
