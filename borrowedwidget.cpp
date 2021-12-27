#include "borrowedwidget.h"
#include "ui_borrowedwidget.h"

BorrowedWidget::BorrowedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowedWidget)
{
    ui->setupUi(this);
    QVector<Reading> results;
    results << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin");
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
    theWidgetItem->setContent(reading.title(), reading.category(), reading.authors(), true);
    listWidgetItem->setSizeHint (theWidgetItem->sizeHint());
    ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);
}

void BorrowedWidget::displayContentResults(QVector<Reading> results)
{
    for (int i = 0; i < results.size(); i++) {
        addReadingItem(results[i], ui);
    }
}
