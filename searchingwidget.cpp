#include "searchingwidget.h"
#include "ui_searchingwidget.h"

SearchingWidget::SearchingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchingWidget)
{
    ui->setupUi(this);
    results << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin")
            << Reading("20120022", "Math", "avaiable", 2, 15, "Algebra", "Kevin");
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
    theWidgetItem->setContent(reading.title(), reading.category(), reading.authors());
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
    contentDetailsDialog->setInfo(results[currentRow].title(), "Guest");
    contentDetailsDialog->show();
}

