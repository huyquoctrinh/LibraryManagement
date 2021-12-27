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

void BorrowedItemWidget::setContent(QString title, QString category, QString authors, bool isReturned)
{
    ui->lblTitle->setText(title);
    ui->lblCategory->setText(category);
    ui->lblAuthors->setText(authors);
    ui->btnReturn->setEnabled(isReturned);
    ui->btnRenewal->setEnabled(isReturned);
    ui->label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_4->setText("<a href=\"abc\">Student A</a>");
}

void BorrowedItemWidget::on_label_4_linkActivated(const QString &link)
{
    qInfo() << link;
}

