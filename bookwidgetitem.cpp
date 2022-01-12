#include "bookwidgetitem.h"
#include "ui_bookwidgetitem.h"

BookWidgetItem::BookWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookWidgetItem)
{
    ui->setupUi(this);
}

BookWidgetItem::~BookWidgetItem()
{
    delete ui;
}

void BookWidgetItem::setContent(QString title, QString category, QString authors)
{
    ui->lblTitle->setText(title);
    ui->lblCategory->setText(category);
    ui->lblAuthors->setText(authors);

    //ui->thumbnail->setPixmap();
}
