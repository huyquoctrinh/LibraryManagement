#include "searchingwidget.h"
#include "ui_searchingwidget.h"

SearchingWidget::SearchingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchingWidget)
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

SearchingWidget::~SearchingWidget()
{
    delete ui;
}

void addReadingItem(Reading reading, Ui::SearchingWidget* ui)
{
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem (listWidgetItem);
    BookWidgetItem *theWidgetItem = new BookWidgetItem;
    QString title = QString::fromStdString(reading.getTitle());
    QString category = QString::fromStdString(ToValue(reading.getCategory()));
    QString authors = QString::fromStdString(reading.getAuthors());
    theWidgetItem->setContent(title, category, authors);
    listWidgetItem->setSizeHint (theWidgetItem->sizeHint ());
    ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);
}

void SearchingWidget::displayContentResults(QVector<Reading> results)
{
    for (int i = 0; i < results.size(); i++) {
        addReadingItem(results[i], ui);
    }
}


void SearchingWidget::on_listWidget_currentRowChanged(int currentRow)
{
    contentDetailsDialog = new ContentDetailsDialog;
    contentDetailsDialog->setModal(true);
    contentDetailsDialog->setInfo(QString::fromStdString(results[currentRow].getTitle()), "Guest");
    contentDetailsDialog->show();
}

